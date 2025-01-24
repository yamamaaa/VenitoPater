#include "ThreeDays.h"

#include"../../Object/ObjectManager/ObjectManager.h"
#include"../../Object/ObjectTag/ThreeDays_ObjectTag.h"

#include"../Result/Result.h"

#include"../../Object/CharaObj/AvoidStatus/AvoidStatus.h"

#include"../../Object/StageObj/ItemGetNum/ItemGetNum.h"
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

#include"../../Object/GameUi/ItemUi/ItemUi.h"
#include"../../Object/GameUi/RPMHPUi/RPMHPUi.h"
#include"../../Object/GameUi/AvoidUi/AvoidUi.h"
#include"../../Object/GameUi/WarningUi/WarningUi.h"

#include"../../Object/NumDays/NumDays.h"
#include"../../Object/Time/Time/Time.h"
#include"../../Object/Time/TimeStatus/TimeStatus.h"

#include"../../Object/CharaObj/Enemy/EnemyAction/EnemyAction.h"

namespace scene
{
	ThreeDays::ThreeDays()
		:SceneBase()
	{
		//読み込み関連
		LoadObject();
	}

	ThreeDays::~ThreeDays()
	{
		//処理なし
	}

	void ThreeDays::LoadObject()
	{
		//オブジェクトタグをセット
		object::ObjectManager::NowSceneSet(objecttag::ThreeDays_ObjTagAll);
		//Game状態をセット
		object::ObjectManager::SetNowGameState(object::GamePlay);
		object::ObjectManager::SetNextGameState(object::GamePlay);

		//ステージ内オブジェの生成
		object::AvoidStatus::Initialize();
		object::ObjectManager::Entry(new object::Area);
		object::ObjectManager::Entry(new object::MoveArea);
		object::ObjectManager::Entry(new object::ClockWork);
		object::ItemGetNum::Initialize();
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

		//ゲームUi生成
		object::ObjectManager::Entry(new object::ItemUi);
		object::ObjectManager::Entry(new object::RPMHPUi);
		object::ObjectManager::Entry(new object::AvoidUi);
		object::ObjectManager::Entry(new object::WarningUi);

		//Time関連生成
		object::TimeStatus::Initialize();
		object::ObjectManager::Entry(new object::Time);

		//敵のアクション生成
		object::ObjectManager::Entry(new object::EnemyAction);

		//フェードフラグ初期化
		m_FadeInSet = false;
	}

	SceneBase* ThreeDays::UpdateScene(const float deltaTime)
	{
		object::ObjectManager::UpdateAllObj(deltaTime);

		//ゲームクリアしたら
		if (object::GameClear== object::ObjectManager::GetNowGameState() || object::GameOver == object::ObjectManager::GetNowGameState())
		{
			object::ObjectManager::ReleaseAllObj();
			return new Result;
		}

		return this;
	}

	void ThreeDays::DrawScene()
	{
		DrawFormatString(0, 0, GetColor(255, 255, 255), "3Days");

		//ゲームステータスが変わったら
		if (object::ObjectManager::GetNowGameState() != object::ObjectManager::GetNextGameState())
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
		object::NumDays::DrawNumDays();
	}
}
