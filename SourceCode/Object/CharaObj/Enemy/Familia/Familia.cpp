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
		m_MoveSpeed = 0.5f;
		m_ObjDrawArea = 3;

		m_DrawObjPos[appear] = { 400.0f,0.0f };
		m_DrawObjPos[replace] = m_DrawObjPos[appear];
		m_DrawObjPos[replace_2] = { 230.0f,0.0f };
		m_DrawObjPos[action] = { 0.0f,0.0f };

		m_ObjImg[0] = -1;
		m_ObjImg[1] = LoadGraph("../Asset/image/enemy/familia/place_0.png");
		m_ObjImg[2] = LoadGraph("../Asset/image/enemy/familia/place_1.png");
		m_ObjImg[3] = LoadGraph("../Asset/image/enemy/familia/place_2.png");
	}

	void Familia::UpdateObj(const float deltatime)
	{
		//回転量が0以下になった時出現
		if (!RPMController::GetIsRPMLost())
			return;

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

	}

	void Familia::DrawObj()
	{
		//回転量が0以下になった時出現
		if (!RPMController::GetIsRPMLost())
			return;

		//表示できる時orアクションライン到達時
		if (IsObjDraw()|| m_IsActionLine)
		{
			DrawGraph(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y),m_ObjHandle, TRUE);
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