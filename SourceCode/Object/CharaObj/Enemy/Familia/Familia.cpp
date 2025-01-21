#include "Familia.h"
#include "../../../ObjectTag/Global_ObjectTag.h"
#include "../../../StageObj/ClockWork/RPMController/RPMController.h"

namespace object
{
	Familia::Familia()
		:EnemyBase(global_objecttag.FAMILIA)
	{
		//読み込み関連
		LoadObject();
	}

	Familia::~Familia()
	{
		//処理なし
	}

	void Familia::LoadObject()
	{
		m_MoveSpeed = 0.3f;
		m_ObjDrawArea = 3;

		m_IDnumber = familia;

		m_DrawObjPos[appear] = { 400.0f,0.0f };
		m_DrawObjPos[replace] = m_DrawObjPos[appear];
		m_DrawObjPos[replace_2] = { 230.0f,0.0f };
		m_DrawObjPos[action] = { 0.0f,0.0f };

		m_ObjImg[0] = -1;
		m_ObjImg[1] = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetFamiliaData(0).c_str());
		m_ObjImg[2] = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetFamiliaData(1).c_str());
		m_ObjImg[3] = -1;
	}

	void Familia::UpdateObj(const float deltatime)
	{
		//回転量が0以下になった時出現
		if (!RPMController::GetIsRPMLost())
			return;

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
	}

	void Familia::DrawObj()
	{
		//回転量が0以下になった時出現
		if (!RPMController::GetIsRPMLost())
			return;

		//表示できる時
		if (IsObjDraw())
		{
			DrawGraph(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), m_ObjHandle, TRUE);
		}


#ifdef DEBUG
		//emyline,box名,enemybox表示
		EnemyLineDraw();
		DrawFormatString(static_cast<int>(m_EnemyBoxPos.x), static_cast<int>(m_EnemyBoxPos.y), GetColor(255, 255, 255), "Familia");
		DrawBox(static_cast<int>(m_EnemyBoxPos.x), static_cast<int>(m_EnemyBoxPos.y), static_cast<int>(m_EnemyBoxPos.x) + static_cast<int>(m_EMYBOX_SIZE.x), static_cast<int>(m_EnemyBoxPos.y) + static_cast<int>(m_EMYBOX_SIZE.y), GetColor(static_cast<int>(m_emybox_collar.x), static_cast<int>(m_emybox_collar.y), static_cast<int>(m_emybox_collar.z)), FALSE);
#endif
	}

	void Familia::MoveObj(const float deltatime)
	{
		m_EnemyBoxPos.y += m_MoveSpeed;	//移動速度計算
	}
}