#include "ClockWork.h"
#include "../../../ObjectTag/Play_ObjectTag.h"
#include "../../../ObjectManager/ObjectManager.h"
#include "../../AreaNumController/AreaNumController.h"
#include "../../ClockWork/RPMController/RPMController.h"
#include "../../../CharaObj/Enemy/EnemyManager/EnemyManager.h"
#include "../../../Time/TimeStatus/TimeStatus.h"
#include "../../../../SoundController/SoundController.h"

namespace object
{
	ClockWork::ClockWork()
		:MouseBase(play_ObjectTag.ClOCKWORK)
	{
		//読み込み関連
		LoadObject();
	}

	ClockWork::~ClockWork()
	{
		for(int i= 0; i < m_AnimPattern; i++)
		{
			DeleteGraph(m_Handle[i]);
		}
	}

	void ClockWork::LoadObject()
	{
		m_AnimNowPattern = 0;
		m_AnimTimer = 0.0f;
		m_AnimNowIndex = 0;

		RPMController::Initialize();

		m_ObjPos.x = 892.0f;	//座標初期値セット
		m_ObjPos.y = 660.0f;

		m_ObjSize.x = 130;	//当たり判定サイズセット
		m_ObjSize.y = 200;

		m_DrawOffset.x = -19;	//当たり判定ずらし量セット
		m_DrawOffset.y = 20;

		m_AnimationFPS = m_DEFAULT_FPS;       // アニメーションFPS初期値

		//画像の読み込み
		LoadDivGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetClockWork().c_str(), m_AnimPattern * m_AnimType, m_AnimPattern, m_AnimType, m_colwidth, m_colheight, m_Handle);
		auto json = JsonManager::SoundData_Instance()->Get_Play_SoundData_Instance();
		m_JsonTag[0] = json->GetMusicbox_NameData();
		m_JsonTag[1] = json->GetClockwork_NameData();
		sound_controller::SoundController::AddSoundData(json->GetMusicbox_PathData(), m_JsonTag[0], json->GetMusicbox_VolumeData(), json->GetMusicbox_TypeData());
		sound_controller::SoundController::AddSoundData(json->GetClockwork_PathData(), m_JsonTag[1], json->GetClockwork_VolumeData(), json->GetClockwork_TypeData());
	}

	void ClockWork::UpdateObj(const float deltatime)
	{
		float rpmhp = RPMController::GetRPMHp();

		//オブジェクトが表示されているとき
		if (m_CanDraw)
		{
			CheckHitMouse();

			if (m_IsClickNow)
			{
				sound_controller::SoundController::StartSound(m_JsonTag[1]);
				rpmhp+= m_RPMHP_COUNTSPEED *deltatime;		//回転量Hpを増やす
				m_AnimationFPS = m_CLICK_FPS;				//アニメーション設定
				MoveObj(deltatime);
			}
			m_IsClickNow = false;
			m_AnimationFPS = m_DEFAULT_FPS;
		}

		//現在のエリア番号を取得
		int infodata = AreaNumController::GetAreaNum();

		//表示可能か
		if (infodata == m_DrawAreaNum)
		{
			m_CanDraw = true;
		}
		else
		{
			m_CanDraw = false;
			sound_controller::SoundController::StopSound(m_JsonTag[0]);
		}

		//回転量が0以下の場合処理なし
		if (RPMController::GetIsRPMLost())
			return;

		//回転量Hpが0以上の時
		if (rpmhp > 0.0f)
		{
			float decrement = RPMController::GetRPMDecrement();

			//強化モンスターがアクションを起こしたら
			if (EnemyManager::GetBeefUpEmyIsAction())
			{
				//HP減らし量を増加する
				decrement += m_EMYRPM_DECREMENT*deltatime;
			}

			rpmhp -= decrement * deltatime; 		//Hp減らし続ける
			MoveObj(deltatime);

			if (TimeStatus::GetIsTimeOver())//タイムオーバーしていたらHPを0に
			{
				rpmhp = 0;
			}
		}
		else
		{
			sound_controller::SoundController::StopSound(m_JsonTag[0]);
			RPMController::SetIsRPMLost(true);
		}

		RPMController::SetRPMHp(rpmhp);		//Hpをセット
	}

	void ClockWork::MoveObj(const float deltatime)
	{
		//表示不可の時処理なし
		if (!m_CanDraw)
			return;

		sound_controller::SoundController::StartSound(m_JsonTag[0]);
		m_AnimTimer += deltatime;

		//アニメーションの計算
		if (m_AnimTimer > m_ANIMTIMER_MAX / m_AnimationFPS)
		{
			m_AnimTimer = 0.0f;
			m_AnimNowPattern++;
			m_AnimNowPattern %= m_AnimPattern;
		}

		m_AnimNowIndex = m_AnimNowPattern;
	}

	void ClockWork::CheckHitMouse()
	{
		CursorHit();	//カーソルとの当たり判定

		if (GetCursorHit())	//当たっていたら
		{
			CanClick();				//クリックできるか？

			//クリック状態で尚且つHPが0以上の時
			if (GetStateClick() && !RPMController::GetIsRPMLost())
			{
				//HPがm_RPMHPMAX(500)以下だったら
				if (RPMController::GetRPMHp() <= RPMController::GetRPMHpMax())
				{
					m_IsClickNow = true;	//クリック状態をtrueに
				}
			}
		}
	}

	void ClockWork::DrawObj()
	{
		//表示できる状態なら
		if (m_CanDraw)
		{
			DrawGraph(static_cast<int>(m_ObjPos.x) + m_DrawOffset.x, static_cast<int>(m_ObjPos.y) + m_DrawOffset.y, m_Handle[m_AnimNowIndex], TRUE);
		}
#if DEBUG
		DrawFormatString(0, 360, GetColor(255, 255, 255), "m_AnimNowIndex:%d", m_AnimNowIndex);
		DrawFormatString(0, 380, GetColor(255, 255, 255), "Hp:%f", RPMController::GetRPMHp());
#endif
	}
}