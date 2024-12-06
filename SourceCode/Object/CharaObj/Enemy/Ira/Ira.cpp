#include "Ira.h"
#include "../../../ObjectTag/Global_ObjectTag.h"
#include "../../../CharaObj/AvoidStatus/AvoidStatus.h"
#include "../../LightController/LightController.h"

namespace object
{
	Ira::Ira()
		:EnemyBase(global_objecttag.IRA)
	{
		//読み込み関連
		LoadObject();
	}

	Ira::~Ira()
	{
		//処理なし
	}

	void Ira::LoadObject()
	{
		m_Idnumber = ira;

		m_DrawObjPos[appear] = { 1000.0f,630.0f };
		m_DrawObjPos[replace] = { 632.0f,525.0f };
		m_DrawObjPos[replace_2] = m_DrawObjPos[replace];
		m_DrawObjPos[action] = { 0.0f,665.0f };

		m_MoveSpeed = 10.0f;
		m_ObjDrawArea = 0;

		m_ObjImg[0] = LoadGraph("../Asset/image/enemy/ira/place_0.png");
		m_ObjImg[1] = LoadGraph("../Asset/image/enemy/ira/place_1.png");
		m_ObjImg[2] = m_ObjImg[1];
		m_ObjImg[3] = LoadGraph("../Asset/image/enemy/ira/place_2.png");
	}

	void Ira::UpdateObj(const float deltatime)
	{
		//出現状態取得
		bool is_appear = EnemyManager::GetIsAppear(m_Idnumber);

		//出現してないなら以下の処理なし
		if (!is_appear)
			return;

		//プレイヤーが回避行動をしたら
		if (AvoidStatus::GetIsAvoid())
		{
			if (!EnemyManager::GetBeefUpEmyIsAction())
			{
				AvoidAction();	//回避行動時処理
			}
		}

		//動ける状態なら
		if (EnemyManager::GetCanMove())
		{
			MoveObj(deltatime);	//移動処理
			IsHitEnemyLine();	//enemyline当たり判定
			ObjStatusUp();		//hitしたらobjのセット
		}

		//当たったラインを調べる
		int linenum=GetHitLineIndex();

		//actionlineに当たっていたら敵全体の強化
		if (action == linenum)
		{
			EnemyManager::SetBeefUpEmyIsAction(true);
		}

		//プレイヤーが回避成功したらobjのリセット
		if (m_IsEmyReset)
		{
			ExitObj();
		}
	}

	void Ira::DrawObj()
	{
		//表示できる状態の時
		if (IsObjDraw())
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
		DrawFormatString(static_cast<int>(m_EnemyBoxPos.x), static_cast<int>(m_EnemyBoxPos.y), GetColor(255, 255, 255), "Ira");
		DrawBox(static_cast<int>(m_EnemyBoxPos.x), static_cast<int>(m_EnemyBoxPos.y), static_cast<int>(m_EnemyBoxPos.x) + static_cast<int>(m_EMYBOX_SIZE.x), static_cast<int>(m_EnemyBoxPos.y) + static_cast<int>(m_EMYBOX_SIZE.y), GetColor(static_cast<int>(m_emybox_collar.x), static_cast<int>(m_emybox_collar.y), static_cast<int>(m_emybox_collar.z)), FALSE);
#endif
	}

	void Ira::MoveObj(const float deltatime)
	{
		m_EnemyBoxPos.y += m_MoveSpeed;	//移動速度計算
	}
}