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
		m_IDnumber = ira;

		m_DrawObjPos[replace] = { 1000.0f,630.0f };
		m_DrawObjPos[replace_2] = { 632.0f,525.0f };
		m_DrawObjPos[action] = { 0.0f,665.0f };

		m_MoveSpeed = 0.3f;
		m_ObjDrawArea = 0;

		m_ObjImg[0] = -1;
		m_ObjImg[1] = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetIraData(0).c_str());
		m_ObjImg[2] = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetIraData(1).c_str());
		m_ObjImg[3] = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetIraData(2).c_str());
	}

	void Ira::UpdateObj(const float deltatime)
	{
		//出現状態取得
		bool is_appear = EnemyManager::GetIsAppear(m_IDnumber);

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

		//他の敵がアクションを起こしてなかったら
		if (!EnemyManager::GetEmyIsAction())
		{
			MoveObj(deltatime);	//移動処理
			IsHitEnemyLine();	//enemyline当たり判定
			ObjStatusUp();		//hitしたらobjのセット
		}

		//当たったラインを調べる
		int linenum = GetHitLineIndex();

		//actionlineに当たっていたらゼンマイ回転を早める
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