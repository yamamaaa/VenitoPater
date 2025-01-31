#include "Memini.h"
#include "../../../ObjectTag/Global_ObjectTag.h"
#include "../../../CharaObj/AvoidStatus/AvoidStatus.h"
#include "../../LightController/LightController.h"
#include "../../../ObjectManager/ObjectManager.h"
#include "../../../../NumDays/NumDays.h"

namespace object
{
	Memini::Memini()
		:EnemyBase(global_objecttag.MEMINI)
	{
		//読み込み関連
		LoadObject();
	}

	Memini::~Memini()
	{
		//処理なし
	}

	void Memini::LoadObject()
	{
		m_IDnumber = memini;

		m_DrawObjPos[appear] = { 850.0f,505.0f };
		m_DrawObjPos[replace] = { 1020.0f,538.0f };
		m_DrawObjPos[replace_2] = { 720.0f,214.0f };

		m_MoveSpeed[0] = 12.0f;
		m_MoveSpeed[1] = 24.0f;
		m_MoveSpeed[2] = 25.0f;

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

		m_ObjDrawArea = 2;

		m_ObjImg[0] = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetMeminiData(0).c_str());
		m_ObjImg[1] = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetMeminiData(1).c_str());
		m_ObjImg[2] = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetMeminiData(2).c_str());
		m_ObjImg[3] = -1;
	}

	void Memini::UpdateObj(const float deltatime)
	{
		//タイムオーバーしていたら処理なし
		if (TimeStatus::GetIsTimeOver())
			return;

		EnemyManager::EmyAppearSetting(deltatime);

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
			LightController::SetIsBlinking(true);
			ExitObj(deltatime);
		}
	}

	void Memini::DrawObj()
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
		DrawFormatString(static_cast<int>(m_EnemyBoxPos.x), static_cast<int>(m_EnemyBoxPos.y), GetColor(255, 255, 255), "Memini");
		DrawBox(static_cast<int>(m_EnemyBoxPos.x), static_cast<int>(m_EnemyBoxPos.y), static_cast<int>(m_EnemyBoxPos.x) + static_cast<int>(m_EMYBOX_SIZE.x), static_cast<int>(m_EnemyBoxPos.y) + static_cast<int>(m_EMYBOX_SIZE.y), GetColor(static_cast<int>(m_emybox_collar.x), static_cast<int>(m_emybox_collar.y), static_cast<int>(m_emybox_collar.z)), FALSE);
#endif
	}

	void Memini::MoveObj(const float deltatime)
	{
		m_EnemyBoxPos.y += m_NowMoveSpeed* deltatime;	//移動速度計算
	}
}