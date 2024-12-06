#include "Spero.h"
#include "../../../ObjectTag/Global_ObjectTag.h"
#include "../../../CharaObj/AvoidStatus/AvoidStatus.h"
#include "../../LightController/LightController.h"

namespace object
{
	Spero::Spero()
		:EnemyBase(global_objecttag.SPERO)
	{
		//読み込み関連
		LoadObject();
	}

	Spero::~Spero()
	{
		//処理なし
	}

	void Spero::LoadObject()
	{
		m_Idnumber = spero;

		m_DrawObjPos[appear] = { 860.0f,530.0f };
		m_DrawObjPos[replace] = { 600.0f,505.0f };
		m_DrawObjPos[replace_2] = { 1028.0f,450.0 };
		m_DrawObjPos[action] = { 0.0f,0.0f };

		m_MoveSpeed = 20.0f;
		m_ObjDrawArea = 0;

		m_ObjImg[0] = LoadGraph("../Asset/image/enemy/spero/place_0.png");
		m_ObjImg[1] = LoadGraph("../Asset/image/enemy/spero/place_1.png");
		m_ObjImg[2] = LoadGraph("../Asset/image/enemy/spero/place_2.png");
		m_ObjImg[3] = LoadGraph("../Asset/image/enemy/spero/place_3.png");
	}

	void Spero::UpdateObj(const float deltatime)
	{
		//出現状態取得
		bool is_appear = EnemyManager::GetIsAppear(m_Idnumber);

		//出現してないなら以下の処理なし
		if (!is_appear)
			return;

		//プレイヤーが回避行動をしたら
		if (AvoidStatus::GetIsAvoid())
		{
			AvoidAction();	//回避行動時処理
		}

		//強化モンスターがアクションを起こしたら
		if (EnemyManager::GetBeefUpEmyIsAction())
		{
			BeefUpEmyAction();	//自身の強化
		}

		//動ける状態なら
		if (EnemyManager::GetCanMove())
		{
			MoveObj(deltatime);	//移動処理
			IsHitEnemyLine();	//enemyline当たり判定
			ObjStatusUp();		//hitしたらobjのセット
		}

		//アクションラインに到達したら
		if (m_IsActionLine)
		{
			EnemyManager::SetCanMove(false);	//全敵の更新を止める
			EnemyInAction();
		}

		//プレイヤーが回避成功したらobjのリセット
		if (m_IsEmyReset)
		{
			ExitObj();
		}
	}

	void Spero::DrawObj()
	{
		//表示できる状態の時
		if (IsObjDraw() || m_IsActionLine)
		{
			DrawGraph(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), m_ObjHandle, TRUE);
		}

		//リセット時画面の明暗
		if (m_IsEmyReset)
		{
			LightController::ScreenBlinking();
		}

#ifdef DEBUG
		//emyline,box名,enemybox表示
		EnemyManager::D_DrawStatus();
		EnemyLineDraw();
		DrawFormatString(static_cast<int>(m_EnemyBoxPos.x), static_cast<int>(m_EnemyBoxPos.y), GetColor(255, 255, 255), "Spero");
		DrawBox(static_cast<int>(m_EnemyBoxPos.x), static_cast<int>(m_EnemyBoxPos.y), static_cast<int>(m_EnemyBoxPos.x) + static_cast<int>(m_EMYBOX_SIZE.x), static_cast<int>(m_EnemyBoxPos.y) + static_cast<int>(m_EMYBOX_SIZE.y), GetColor(static_cast<int>(m_emybox_collar.x), static_cast<int>(m_emybox_collar.y), static_cast<int>(m_emybox_collar.z)), FALSE);
#endif
	}

	void Spero::MoveObj(const float deltatime)
	{
		m_EnemyBoxPos.y += m_MoveSpeed;	//移動速度計算
	}
}