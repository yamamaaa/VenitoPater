#include "ThreeDays.h"

#include"../../Object/ObjectManager/ObjectManager.h"
#include"../../Object/ObjectTag/ThreeDays_ObjectTag.h"

#include"../../Scene/Title/Title.h"
#include"../../Scene/Result/GameOver/GameOver.h"

#include"../../Object/CharaObj/AvoidStatus/AvoidStatus.h"

#include"../../Object/StageObj/Area/Area.h"
#include"../../Object/StageObj/MoveArea/MoveArea.h"
#include"../../Object/StageObj/ClockWork/ClockWork/ClockWork.h"
#include"../../Object/StageObj/Item/Item.h"

#include"../../Object/CharaObj/Enemy/EnemyManager/EnemyManager.h"
#include"../../Object/CharaObj/Enemy/Familia/Familia.h"
#include"../../Object/CharaObj/Enemy/Memini/Memini.h"
#include"../../Object/CharaObj/Enemy/Nil/Nil.h"
#include"../../Object/CharaObj/Enemy/Spero/Spero.h"
#include"../../Object/CharaObj/Enemy/Ira/Ira.h"

#include"../../Object/CharaObj/Avoid/Avoid.h"
#include"../../Object/CharaObj/Player/Player.h"

namespace scene
{
	ThreeDays::ThreeDays()
		:SceneBase()
	{
		//オブジェクトタグをセット
		object::ObjectManager::NowSceneSet(objecttag::ThreeDays_ObjTagAll);
		//Game状態をセット
		object::ObjectManager::SetGameState(object::GamePlay);

		//ステージ内オブジェの生成
		object::AvoidStatus::Initialize();
		object::ObjectManager::Entry(new object::Area);
		object::ObjectManager::Entry(new object::MoveArea);
		object::ObjectManager::Entry(new object::ClockWork);
		object::ObjectManager::Entry(new object::Item);

		//敵の生成
		object::EnemyManager::Initialize();
		object::ObjectManager::Entry(new object::Familia);
		object::ObjectManager::Entry(new object::Memini);
		object::ObjectManager::Entry(new object::Nil);
		object::ObjectManager::Entry(new object::Spero);
		object::ObjectManager::Entry(new object::Ira);

		//プレイヤー関連生成
		object::ObjectManager::Entry(new object::Avoid);
		object::ObjectManager::Entry(new object::Player);
	}

	ThreeDays::~ThreeDays()
	{
		//メモリ解放
		delete object_generation;
	}

	SceneBase* ThreeDays::UpdateScene(const float deltaTime)
	{
		object::ObjectManager::UpdateAllObj(deltaTime);

		//ゲームクリアしたら
		if (object::GameClear==object::ObjectManager::GetGameState())
		{
			object::ObjectManager::ReleaseAllObj();
			return new Title;
		}

		//ゲームオーバー
		if (object::GameOver == object::ObjectManager::GetGameState())
		{
			if (fade_transitor->IsFadeDone())
			{
				object::ObjectManager::ReleaseAllObj();
				return new GameOver;
			}
		}

		return this;
	}

	void ThreeDays::DrawScene()
	{
		DrawFormatString(0, 0, GetColor(255, 255, 255), "3Days");
		object::ObjectManager::DrawAllObj();

		//ゲームオーバー
		if (object::GameOver == object::ObjectManager::GetGameState())
		{
			fade_transitor->FadeOutStart(true);
		}
	}
}
