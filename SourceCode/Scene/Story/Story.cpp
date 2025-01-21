#include "Story.h"

#include"../../Object/ObjectTag/Story_ObjectTag.h"

#include"../ThreeDays/ThreeDays.h"

#include"../../Object/StoryObj/LineStatus/LineStatus.h"

#include"../../Object/StoryObj/Character/Character.h"
#include"../../Object/Result/BackGround/BackGround.h"
#include"../../Object/StoryObj/Line/Line.h"

#include"../../Object/ObjectTag/Still_ObjectTag.h"

#include"../../Object/StoryObj/StillDraw/StillDraw.h"

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
		if (object::Story == m_NowGameStatus)
		{
			//オブジェクトタグをセット
			object::ObjectManager::NowSceneSet(objecttag::Story_ObjectTagAll);
			//Game状態をセット
			object::ObjectManager::SetGameState(m_NowGameStatus);

			object::LineStatus::Initialize();
			object::ObjectManager::Entry(new object::BackGround);
			object::ObjectManager::Entry(new object::Character);
			object::ObjectManager::Entry(new object::Line);
		}
		else if (object::Still == m_NowGameStatus)
		{
			//オブジェクトタグをセット
			object::ObjectManager::NowSceneSet(objecttag::still_ObjectTagAll);
			//Game状態をセット
			object::ObjectManager::SetGameState(m_NowGameStatus);

			object::LineStatus::Initialize();
			object::ObjectManager::Entry(new object::StillDraw);
			object::ObjectManager::Entry(new object::Line);
		}
	}

	SceneBase* Story::UpdateScene(const float deltaTime)
	{
		object::ObjectManager::UpdateAllObj(deltaTime);

		if (object::GamePlay == m_NowGameStatus)
		{
			object::ObjectManager::ReleaseAllObj();
			return new ThreeDays;
		}

		if (object::Story == m_NowGameStatus|| object::Still == m_NowGameStatus)
		{
			object::ObjectManager::ReleaseAllObj();
			return new Story;
		}

		return this;
	}

	void Story::DrawScene()
	{
		DrawFormatString(0, 0, GetColor(255, 255, 255), "Story");

		//ゲームステータスが変わったら
		if (m_NowGameStatus != object::ObjectManager::GetGameState())
		{
			//フェード処理をする
			fade_transitor->FadeOutStart(true);
			TransitorScene();
		}

		if (!m_FadeInSet)
		{
			//フェードイン
			fade_transitor->FadeInStart(false);
			LoadScene();
		}

		object::ObjectManager::DrawAllObj();
	}
}