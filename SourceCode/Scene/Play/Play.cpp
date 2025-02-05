#include "Play.h"

#include"../../Object/ObjectManager/ObjectManager.h"
#include"../../Object/ObjectTag/Play_ObjectTag.h"

#include"../Clear/Clear.h"
#include"../Result/Result.h"
#include"../Title/Title.h"

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

#include"../../Object/Time/Time/Time.h"
#include"../../Object/Time/TimeStatus/TimeStatus.h"
#include"../../Object/TextDraw/TextDraw.h"
#include"../../Object/Menu/Menu.h"

#include"../../Object/CharaObj/Enemy/EnemyAction/EnemyAction.h"

#include"../../MouseStatus/MouseStatus.h"

namespace scene
{
	Play::Play()
		:SceneBase()
	{
		//読み込み関連
		LoadObject();
	}

	Play::~Play()
	{
		//処理なし
	}

	void Play::LoadObject()
	{
		//オブジェクトタグをセット
		object::ObjectManager::NowSceneSet(objecttag::Play_ObjectTagAll);
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

		//テキスト関連
		object::PlayMenu menu = object::ObjectManager::GetPlayMode();
		if (menu == object::PlayMenu::PlayNewGame)
		{
			object::ObjectManager::Entry(new object::TextDraw);
		}

		//メニュー関連
		object::ObjectManager::Entry(new object::Menu);

		//敵のアクション生成
		object::ObjectManager::Entry(new object::EnemyAction);
	}

	SceneBase* Play::UpdateScene(const float deltaTime)
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
			TransitorScene(deltaTime);
		}
		else
		{
			object::ObjectManager::UpdateAllObj(deltaTime);
		}

		//ゲームクリアしたら
		if (object::GameClear == status)
		{
			return new Clear;
			//return new a;
		}

		//ゲームオーバー
		if (object::GameOver == status || object::TimeOver == status)
		{
			return new Result;
		}

		//タイトル
		if (object::Title == status)
		{
			return new Title;
		}

		return this;
	}

	void Play::DrawScene()
	{
		if (m_IsChangeScene || !m_FadeInSet)
		{
			transitor::FadeTransitor::DrawFade();
		}

		object::ObjectManager::DrawAllObj();
	}
}
