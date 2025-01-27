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
		m_IDnumber = nil;

		m_DrawObjPos[appear] = { 940.0f,500.0 };
		m_DrawObjPos[replace] = { 900.0f,450.0f };
		m_DrawObjPos[replace_2] = { 770.0f,270.0f };

		m_MoveSpeed = 24.0f;
		m_ObjDrawArea = 1;

		m_ObjImg[0] = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetNilData(0).c_str());
		m_ObjImg[1] = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetNilData(1).c_str());
		m_ObjImg[2] = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetNilData(2).c_str());
		m_ObjImg[3] = -1;
	}

	void Nil::UpdateObj(const float deltatime)
	{
		//タイムオーバーしていたら処理なし
		if (TimeStatus::GetIsTimeOver())
			return;
		//出現状態取得
		bool is_appear = EnemyManager::GetIsAppear(m_IDnumber);

		//出現してないなら以下の処理なし
		if (!is_appear)
			return;

		//プレイヤーが回避行動をしたら
		if (AvoidStatus::GetIsAvoid())
		{
			AvoidAction(deltatime);	//回避行動時処理
		}

		//他の敵がアクションを起こしてなかったら
		if (!EnemyManager::GetEmyIsAction())
		{
			MoveObj(deltatime);	//移動処理
			IsHitEnemyLine();	//enemyline当たり判定
			ObjStatusUp();		//hitしたらobjのセット
		}

		//アクションラインに到達したら
		if (m_IsActionLine)
		{
			EnemyManager::SetEmyIsAction(true);
			EnemyManager::SetEmyIDAction(m_IDnumber);
			EnemyInAction();
		}

		//プレイヤーが回避成功したらobjのリセット
		if (m_IsEmyReset)
		{
			ExitObj(deltatime);
		}
	}

	void Nil::DrawObj()
	{
		//表示できる状態の時
		if (IsObjDraw())
		{
			DrawGraph(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), m_ObjHandle, TRUE);
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
		m_EnemyBoxPos.y += m_MoveSpeed* deltatime;	//移動速度計算
	}
}