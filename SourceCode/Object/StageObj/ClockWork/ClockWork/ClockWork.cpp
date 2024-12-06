#include "ClockWork.h"
#include "../../../ObjectTag/Global_ObjectTag.h"
#include "../../../ObjectManager/ObjectManager.h"
#include "../../../StageObj/WarningUi/WarningUi.h"
#include "../../AreaNumController/AreaNumController.h"
#include "../../ClockWork/RPMController/RPMController.h"

namespace object
{
	ClockWork::ClockWork()
		:MouseBase(global_objecttag.ClOCKWORK)
	{
		//読み込み関連
		LoadObject();
	}

	ClockWork::~ClockWork()
	{
		delete warningui;	//メモリ解放
	}

	void ClockWork::LoadObject()
	{
		m_AnimNowPattern = 0;
		m_AnimTimer = 0.0f;
		m_AnimNowIndex = 0;

		warningui = new WarningUi;
		RPMController::Initialize();

		m_ObjPos.x = 892.0f;	//座標初期値セット
		m_ObjPos.y = 660.0f;

		m_ObjSize.x = 130;	//当たり判定サイズセット
		m_ObjSize.y = 200;

		m_DrawOffset.x = -19;	//当たり判定ずらし量セット
		m_DrawOffset.y = 20;

		m_HPDrawPos.x = 710;
		m_HPDrawPos.y = 540;

		m_FillBoxSize.x = 0;
		m_FillBoxSize.y = 60;

		m_LineBoxSize.x = 500;
		m_LineBoxSize.y = 60;

		m_FillBox_Collar = VGet(255, 255, 0);
		m_LineBox_Collar = VGet(255, 255, 255);

		//画像の読み込み
		LoadDivGraph("../Asset/image/clockwork/clockwork.png", m_AnimPattern * m_AnimType, m_AnimPattern, m_AnimType, m_colwidth, m_colheight, m_Handle);
	}

	void ClockWork::UpdateObj(const float deltatime)
	{
		//HP表示状態初期化
		m_CanDrawHP = false;

		float rpmhp = RPMController::GetRPMHp();

		//オブジェクトが表示されているとき
		if (m_CanDraw)
		{	
			CheckHitMouse();

			if (m_IsClickNow)
			{
				rpmhp++;						//回転量Hpを増やす
				m_AnimationFPS = m_CLICK_FPS;	//アニメーション設定
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
		}

		//回転量が警告値に達したら警告を出す
		if (rpmhp <= m_WARNING_VALUE)
		{
			if (infodata != m_DrawAreaNum)
			{
				warningui->SetIsWarning(true);	//表示状態のセット
			}
			else
			{
				warningui->SetIsWarning(false);
			}
			warningui->SetIsBlinking(true);		//Ui点滅状態のセット
		}
		if (rpmhp <= 0.0f) //0以下は警告Uiを点滅させない
		{
			RPMController::SetIsRPMLost(true);
			warningui->SetIsBlinking(false);
		}

		//回転量が0以下の場合処理なし
		if (RPMController::GetIsRPMLost())
			return;

		//回転量Hpが0以上の時
		if (rpmhp > 0.0f)
		{
			float decrement=RPMController::GetRPMDecrement();
			rpmhp -= decrement; 		//Hp減らし続ける
			DrawValue = rpmhp;

			MoveObj(deltatime);
		}

		RPMController::SetRPMHp(rpmhp);		//Hpをセット
	}

	void ClockWork::MoveObj(const float deltatime)
	{
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
			m_CanDrawHP = true;		//HPを表示
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
		else
		{
			m_CanDrawHP = false;	//デフォルトは非表示
		}
	}

	void ClockWork::DrawObj()
	{
		//警告状態ならUiの表示
		if (warningui->GetIsWarning())
		{
			warningui->DrawUi();
		}
	
		//表示できる状態なら
		if (m_CanDraw)
		{
			DrawGraph(static_cast<int>(m_ObjPos.x)+ m_DrawOffset.x, static_cast<int>(m_ObjPos.y)+ m_DrawOffset.y, m_Handle[m_AnimNowIndex], TRUE);
			if (m_CanDrawHP)
			{
				DrawFillBox(static_cast<int>(m_HPDrawPos.x), static_cast<int>(m_HPDrawPos.y), static_cast<int>(m_HPDrawPos.x) + static_cast<int>(DrawValue), static_cast<int>(m_HPDrawPos.y) + m_FillBoxSize.y, GetColor(static_cast<int>(m_FillBox_Collar.x), static_cast<int>(m_FillBox_Collar.y), static_cast<int>(m_FillBox_Collar.z)));
				DrawLineBox(static_cast<int>(m_HPDrawPos.x), static_cast<int>(m_HPDrawPos.y), static_cast<int>(m_HPDrawPos.x) + m_LineBoxSize.x, static_cast<int>(m_HPDrawPos.y) + m_LineBoxSize.y, GetColor(static_cast<int>(m_LineBox_Collar.x), static_cast<int>(m_LineBox_Collar.y), static_cast<int>(m_LineBox_Collar.z)));
			}		
#ifdef DEBUG
			DrawBox(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), static_cast<int>(m_ObjPos.x) + m_ObjSize.x, static_cast<int>(m_ObjPos.y) + m_ObjSize.y, GetColor(255, 40, 0), FALSE);
#endif
		}
#ifdef DEBUG
		DrawFormatString(0, 360, GetColor(255,255,255), "m_AnimNowIndex:%d", m_AnimNowIndex);
		DrawFormatString(0, 380, GetColor(255, 255, 255), "Hp:%f", RPMController::GetRPMHp());
#endif
	}
}