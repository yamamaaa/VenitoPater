#include "Spero.h"
#include "../../../ObjectTag/Play_ObjectTag.h"
#include "../../../CharaObj/AvoidStatus/AvoidStatus.h"
#include "../../LightController/LightController.h"
#include "../../../ObjectManager/ObjectManager.h"
#include "../../../../NumDays/NumDays.h"

namespace object
{
	Spero::Spero()
		:EnemyBase(play_ObjectTag.SPERO)
	{
		//読み込み関連
		LoadObject();
	}

	Spero::~Spero()
	{
		DeleteGraph(m_ObjHandle);

		for (int i = 0; i < 4; i++)
		{
			DeleteGraph(m_ObjImg[i]);
		}
	}

	void Spero::LoadObject()
	{
		m_IDnumber = spero;

		m_DrawObjPos[appear] = { 860.0f,530.0f };
		m_DrawObjPos[replace] = { 600.0f,505.0f };
		m_DrawObjPos[replace_2] = { 1028.0f,450.0 };

		m_MoveSpeed[0] = 12.0f;
		m_MoveSpeed[1] = 16.0f;
		m_MoveSpeed[2] = 18.0f;

		//プレイモード別に初期設定
		PlayMenu menu = ObjectManager::GetPlayMode();
		if (menu == PlayNewGame)
		{
			//現在が何日目か取得
			int day = NumDays::GetNumDays();

			//カウント値の初期化
			m_NowMoveSpeed = m_MoveSpeed[day-1];
		}
		else
		{
			//カウント値の初期化
			m_NowMoveSpeed = m_MoveSpeed[2];
		}
		m_ObjDrawArea = 0;

		m_ObjImg[0] = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetSperoData(0).c_str());
		m_ObjImg[1] = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetSperoData(1).c_str());
		m_ObjImg[2] = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetSperoData(2).c_str());
		m_ObjImg[3] = -1;
	}

	void Spero::UpdateObj(const float deltatime)
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
		else
		{
			AvoidReset();
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

	void Spero::DrawObj()
	{
		//表示できる状態の時
		if (IsObjDraw() || m_IsActionLine)
		{
			DrawGraph(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), m_ObjHandle, TRUE);
		}

#if DEBUG
		//emyline,box名,enemybox表示
		EnemyManager::D_DrawStatus();
		EnemyLineDraw();
		DrawFormatString(static_cast<int>(m_EnemyBoxPos.x), static_cast<int>(m_EnemyBoxPos.y), GetColor(255, 255, 255), "Spero");
		DrawBox(static_cast<int>(m_EnemyBoxPos.x), static_cast<int>(m_EnemyBoxPos.y), static_cast<int>(m_EnemyBoxPos.x) + static_cast<int>(m_EMYBOX_SIZE.x), static_cast<int>(m_EnemyBoxPos.y) + static_cast<int>(m_EMYBOX_SIZE.y), GetColor(static_cast<int>(m_emybox_collar.x), static_cast<int>(m_emybox_collar.y), static_cast<int>(m_emybox_collar.z)), FALSE);
#endif
	}

	void Spero::MoveObj(const float deltatime)
	{
		m_EnemyBoxPos.y += m_NowMoveSpeed* deltatime;	//移動速度計算
	}
}