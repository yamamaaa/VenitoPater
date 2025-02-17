#include "EnemyBase.h"
#include "../../../../GameSystem/Window/Window.h"
#include "../../../StageObj/AreaNumController/AreaNumController.h"
#include"../../../ObjectManager/ObjectManager.h"
#include "../../LightController/LightController.h"
#include "../../../../SoundController/SoundController.h"

namespace object
{
	EnemyBase::EnemyBase(std::string tagname)
		:ObjectBase(tagname),
		m_ObjImg(),
		m_HitLineIndex(-1),
		m_ObjDrawArea(-1),
		m_IsActionLine(false),
		m_CanAvoid(false),
		m_IsAppear(false),
		m_BlinkingCount(0.0f),
		m_ResetCount(0.0f),
		m_IsEmyReset(false),
		m_DrawObjPos(0)
	{
		//読み込み関連
		LoadObject();
	}

	EnemyBase::~EnemyBase()
	{
		//メモリの解放
		delete window;
		EnemyManager::Processing();
		m_DrawObjPos.clear();
		m_EmyLine_Pos.clear();
#if DEBUG
		m_collarcode.clear();
#endif // DEBUG
	}

	void EnemyBase::LoadObject()
	{
		window = nullptr;	//windowのインスタンス生成

		m_ObjSize = window->GetWindowSize();	//windowサイズの取得
		m_ObjSize.y = 0;

		auto json = JsonManager::SoundData_Instance()->Get_Play_SoundData_Instance();
		m_JsonTag = json->GetLight_NameData();
		sound_controller::SoundController::AddSoundData(json->GetLight_PathData(), m_JsonTag, json->GetLight_VolumeData(), json->GetLight_TypeData());
	}

	void EnemyBase::IsHitEnemyLine()
	{
		bool hitstatus = false;	//Hit状態
		m_HitLineIndex = 0;		//Index初期化

		//enemylineとの当たり判定を調べる
		for (std::string& tag : EnemyLine_TagAll)
		{
			hitstatus = CheckHitSquare(m_EmyLine_Pos[tag].x, m_EmyLine_Pos[tag].y, m_ObjSize.x, m_ObjSize.y, m_EnemyBoxPos.x, m_EnemyBoxPos.y, m_EMYBOX_SIZE.x, m_EMYBOX_SIZE.y);

			//当たっていたら
			if (hitstatus)
			{
				return;
			}
			m_HitLineIndex++;
		}
	}

	const bool EnemyBase::IsObjDraw()
	{
		//タイムオーバーしていたら
		if (TimeStatus::GetIsTimeOver())
		{
			//familia以外表示不可
			if (m_IDnumber != familia)
			{
				return false;
			}
		}

		//エリア番号の取得
		int infodata = AreaNumController::GetAreaNum();

		//enemyの表示ができるか
		if (infodata == m_ObjDrawArea)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void EnemyBase::AvoidAction(const float deltatime)
	{
		//回避できないなら処理なし
		if (!m_CanAvoid)
			return;

		//敵が出現中で表示できるとき
		if (m_IsAppear && IsObjDraw())
		{
			m_ResetCount+= m_COUNTSPPED_RESET *deltatime;
			if (m_ResetCount >= m_COUNTRESET_MAX)	//カウントが規定値に達したらリセット
			{
				m_IsEmyReset = true;
				m_ResetCount = 0.0f;
			}
		}
	}

	void EnemyBase::AvoidReset()
	{
		//カウントのリセット
		m_ResetCount = 0.0f;
	}

	void EnemyBase::ObjStatusUp()
	{
		//当たったEmylineによって状態切り替え
		switch (GetHitLineIndex())
		{
		case appear:
			m_IsAppear = true;					//オブジェクトを出現中に
			m_ObjHandle = m_ObjImg[0];			//表示画像のセット
			m_ObjPos = m_DrawObjPos[appear];	//画像の表示位置更新
			break;
		case replace:
			m_ObjHandle = m_ObjImg[1];
			m_ObjPos = m_DrawObjPos[replace];
			m_CanAvoid = true;					//回避できる状態に
			break;
		case replace_2:
			m_ObjHandle = m_ObjImg[2];
			m_ObjPos = m_DrawObjPos[replace_2];
			break;
		case action:
			m_ObjHandle = m_ObjImg[3];
			m_ObjPos = m_DrawObjPos[action];
			m_IsActionLine = true;	//フラグをtrueに
			break;
		}
	}

	void EnemyBase::ExitObj(const float deltatime)
	{
		//敵の退出時画面を点滅させる
		LightController::SetIsBlinking(true);
		sound_controller::SoundController::StartSound(m_JsonTag);
		m_BlinkingCount+= m_COUSPPED_BLINKING*deltatime;
		if (m_BlinkingCount >= m_BLINKING_COUMAX)
		{
			ResetObj();
			m_IsEmyReset = false;
			LightController::SetIsBlinking(false);
		}
	}

	void EnemyBase::ResetObj()
	{
		//敵情報の初期化
		m_IsAppear = false;
		m_CanAvoid = false;
		m_EnemyBoxPos = m_EMYBOX_RESETPOS;
		m_ObjHandle = -0;
		m_ObjPos = { 0.0f,0.0f };
		m_BlinkingCount = 0;
		EnemyManager::SetIsAppear(m_IDnumber, false);

		//敵の出現総数を減らす
		int num = EnemyManager::GetAppearNumNow();
		num--;
		EnemyManager::SetAppearNumNow(num);
	}

	void EnemyBase::EnemyInAction()
	{
		//ゲーム状態をゲームオーバーに
		ObjectManager::SetNextGameState(GameOver);
	}

#if DEBUG
	void EnemyBase::EnemyLineDraw()
	{
		//enemylineの表示
		for (std::string& tag : EnemyLine_TagAll)
		{
			DrawLine(m_EmyLine_Pos[tag].x, m_EmyLine_Pos[tag].y, m_EmyLine_Pos[tag].x + m_ObjSize.x, m_EmyLine_Pos[tag].y + m_ObjSize.y, GetColor(static_cast<int>(m_collarcode[tag].x), static_cast<int>(m_collarcode[tag].y), static_cast<int>(m_collarcode[tag].z)), FALSE);
		}
		DrawFormatString(0, 800, GetColor(255, 255, 255), "敵のリセットまで:%f", m_ResetCount);
	}
#endif
}