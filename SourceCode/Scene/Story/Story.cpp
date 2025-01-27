#include "Story.h"

#include"../../Object/ObjectTag/Story_ObjectTag.h"

#include"../ThreeDays/ThreeDays.h"

#include"../../Object/StoryObj/LineStatus/LineStatus.h"

#include"../../Object/Result/BackGround/BackGround.h"
#include"../../Object/StoryObj/Character/Character.h"
#include"../../Object/StoryObj/StoryItem/StoryItem.h"
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

		//フェードフラグ初期化
		m_FadeInSet = false;
		IsNextStory = false;
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

			//処理が終わったらステータスの変更と後処理
			if (transitor::FadeTransitor::IsFadeDone())
			{
				//次のステータスを取得しセット
				object::GameStatus status_next = object::ObjectManager::GetNextGameState();
				object::ObjectManager::SetNowGameState(status);

				object::ObjectManager::ReleaseAllObj();
				transitor::FadeTransitor::FadeProcessing();

				//次のシーンが同じストーリーシーンか
				if (object::Story == status_next || object::Still == status_next)
				{
					IsNextStory = true;
				}
			}
		}
		else
		{
			object::ObjectManager::UpdateAllObj(deltaTime);
		}

		if (object::GamePlay == status)
		{
			return new ThreeDays;
		}

		if (IsNextStory)
		{
			IsNextStory = false;
			return new Story;
		}

		return this;
	}

	void Story::DrawScene()
	{
		DrawFormatString(0, 0, GetColor(255, 255, 255), "Story");

		if (m_IsChangeScene || !m_FadeInSet)
		{
			transitor::FadeTransitor::DrawFade();
		}

		object::ObjectManager::DrawAllObj();
	}
}