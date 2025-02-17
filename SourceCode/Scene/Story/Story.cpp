#include "Story.h"

#include"../../Object/ObjectTag/Story_ObjectTag.h"

#include"../Play/Play.h"
#include"../Movie/Movie.h"
#include"../Title/Title.h"

#include"../../Object/StoryObj/LineStatus/LineStatus.h"

#include"../../Object/Result/BackGround/BackGround.h"
#include"../../Object/StoryObj/Character/Character.h"
#include"../../Object/StoryObj/StoryItem/StoryItem.h"
#include"../../Object/StoryObj/Line/Line.h"
#include"../../Object/Menu/Menu.h"

#include"../../Object/ObjectTag/Still_ObjectTag.h"

#include"../../Object/StoryObj/StillDraw/StillDraw.h"

#include"../a/a.h"

namespace scene
{
	Story::Story()
		:SceneBase()
	{
		//読み込み関連
		LoadObject();
	}

	Story::~Story()
	{
		//処理なし
	}

	void Story::LoadObject()
	{
		if (object::Story == object::ObjectManager::GetNowGameState())
		{
			//オブジェクトタグをセット
			object::ObjectManager::NowSceneSet(objecttag::Story_ObjectTagAll);
			//Game状態をセット
			object::ObjectManager::SetNextGameState(object::Story);

			object::LineStatus::Initialize();
			object::ObjectManager::Entry(new object::BackGround);
			object::ObjectManager::Entry(new object::Character);
			object::ObjectManager::Entry(new object::StoryItem);
			object::ObjectManager::Entry(new object::Line);
		}
		if (object::Still == object::ObjectManager::GetNowGameState())
		{
			//オブジェクトタグをセット
			object::ObjectManager::NowSceneSet(objecttag::still_ObjectTagAll);
			//Game状態をセット
			object::ObjectManager::SetNextGameState(object::Still);

			object::LineStatus::Initialize();
			object::ObjectManager::Entry(new object::StillDraw);
			object::ObjectManager::Entry(new object::Line);
		}

		object::ObjectManager::Entry(new object::Menu);

		//初期化
		m_IsNextSame = false;
	}

	SceneBase* Story::UpdateScene(const float deltaTime)
	{
		if (!m_FadeInSet)
		{
			transitor::FadeTransitor::FadeInStart(deltaTime);
			LoadScene();
		}

		//現在のステータスを取得
		object::GameStatus status = object::ObjectManager::GetNowGameState();

		//ゲームステータスが変わったらシーン切り替え処理をする
		if (status != object::ObjectManager::GetNextGameState())
		{
			m_IsChangeScene = true;
			transitor::FadeTransitor::FadeOutStart(deltaTime);
			TransitorScene(deltaTime, object::GameStatus::Story, object::GameStatus::Still, m_IsNextSame);
		}
		else
		{
			object::ObjectManager::UpdateAllObj(deltaTime);
		}

		if (object::GamePlay == status)
		{
			object::ObjectManager::ReleaseAllObj();
			return new Play;
		}

		if (object::Title == status)
		{
			object::ObjectManager::ReleaseAllObj();
			return new Title;
		}

		if (object::PlayEnd == status)
		{
			return new Movie;
		}

		if (m_IsNextSame)
		{
			return new Story;
		}

		return this;
	}

	void Story::DrawScene()
	{
		if (m_IsChangeScene || !m_FadeInSet)
		{
			transitor::FadeTransitor::DrawFade();
		}

		object::ObjectManager::DrawAllObj();

#if DEBUG
		DrawString(0, 0, "Story", GetColor(255, 255, 255));
#endif // DEBUG
	}
}