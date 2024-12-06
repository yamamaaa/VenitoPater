#include "Nil.h"
#include "../../../ObjectTag/Global_ObjectTag.h"
#include "../../../CharaObj/AvoidStatus/AvoidStatus.h"
#include "../../LightController/LightController.h"

namespace object
{
    Nil::Nil()
		:EnemyBase(global_objecttag.NIL)
    {
		//読み込み関連
		LoadObject();
    }

    Nil::~Nil()
    {
		//処理なし
    }

	void Nil::LoadObject()
	{
		m_Idnumber = nil;

		m_DrawObjPos[appear] = { 940.0f,500.0 };
		m_DrawObjPos[replace] = { 900.0f,450.0f };
		m_DrawObjPos[replace_2] = { 770.0f,270.0f };
		m_DrawObjPos[action] = { 0.0f,0.0f };

		m_MoveSpeed = 0.1f;
		m_ObjDrawArea = 1;

		m_ObjImg[0] = LoadGraph("../Asset/image/enemy/nil/place_0.png");
		m_ObjImg[1] = LoadGraph("../Asset/image/enemy/nil/place_1.png");
		m_ObjImg[2] = LoadGraph("../Asset/image/enemy/nil/place_2.png");
		m_ObjImg[3] = LoadGraph("../Asset/image/enemy/nil/place_3.png");
	}

	void Nil::UpdateObj(const float deltatime)
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

	void Nil::DrawObj()
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
		EnemyLineDraw();
		DrawFormatString(static_cast<int>(m_EnemyBoxPos.x), static_cast<int>(m_EnemyBoxPos.y), GetColor(255, 255, 255), "Nil");
		DrawBox(static_cast<int>(m_EnemyBoxPos.x), static_cast<int>(m_EnemyBoxPos.y), static_cast<int>(m_EnemyBoxPos.x) + static_cast<int>(m_EMYBOX_SIZE.x), static_cast<int>(m_EnemyBoxPos.y) + static_cast<int>(m_EMYBOX_SIZE.y), GetColor(static_cast<int>(m_emybox_collar.x), static_cast<int>(m_emybox_collar.y), static_cast<int>(m_emybox_collar.z)), FALSE);
#endif
	}

	void Nil::MoveObj(const float deltatime)
	{
		m_EnemyBoxPos.y += m_MoveSpeed;	//移動速度計算
	}
}