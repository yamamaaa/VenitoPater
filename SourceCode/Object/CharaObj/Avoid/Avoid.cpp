#include<Dxlib.h>
#include "Avoid.h"
#include"../../ObjectTag/Global_ObjectTag.h"
#include"../AvoidStatus/AvoidStatus.h"
#include"../HatUi/HatUi.h"

namespace object
{
	Avoid::Avoid()
		:MouseBase(global_objecttag.AVOID)
	{
		//読み込み関連
		LoadObject();
	}

	Avoid::~Avoid()
	{
		//処理なし
	}

	void Avoid::LoadObject()
	{
		m_ObjPos.x = 170;
		m_ObjPos.y = 880;

		m_ObjSize.x = 600;
		m_ObjSize.y = 200;

		m_DrawOffset.x = 0;
		m_DrawOffset.y = 0;

		m_ClickCount = m_CLICKCOUNT_MAX;

		//HatUiの初期化
		HatUi::Initialize();
	}

	void Avoid::UpdateObj(const float deltatime)
	{
		CursorHit();	//カーソルとの当たり判定

		if (GetCursorHit())	//当たっていたら
		{
			CanClick();		//クリックできるか？

			//クリック状態の時
			if (GetStateClick()&& m_IsClick)
			{
				if (!AvoidStatus::GetIsAvoid())
				{
					HatUi::SetMove();
					//回避行動フラグをtrueに
					AvoidStatus::SetIsAvoid(true);
#ifdef DEBUG
					m_avoid_status = "回避行動中";
#endif
				}
				else
				{
					HatUi::SetMove();
#ifdef DEBUG
					m_avoid_status = "通常状態";
#endif
				}
				
				m_IsClick = false;
			}
		}

		//Uiの動き処理
		if (!HatUi::GetIsMoveDone())
		{
			MoveObj(deltatime);
		}

		//再びクリックできるまでカウント
		if (!m_IsClick)
		{
			m_ClickCount -- ;
			if (m_ClickCount == 0.0f)
			{
				m_ClickCount = m_CLICKCOUNT_MAX;
				m_IsClick = true;
			}
		}
	}

	void Avoid::DrawObj()
	{
		//回避行動中はUiを表示
		if (AvoidStatus::GetIsAvoid())
		{
			HatUi::DrawUi();
		}
#ifdef DEBUG
		DrawBox(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), static_cast<int>(m_ObjPos.x) + m_ObjSize.x, static_cast<int>(m_ObjPos.y) + m_ObjSize.y, GetColor(static_cast<int>(m_collarcode.x), static_cast<int>(m_collarcode.y), static_cast<int>(m_collarcode.z)), FALSE);
		DrawFormatString(0, 400, GetColor(255, 255, 255), "回避状態:%s", m_avoid_status.c_str());
		DrawFormatString(0, 420, GetColor(255, 255, 255), "再び回避できるまで:%f", m_ClickCount);
#endif
	}

	void Avoid::MoveObj(const float deltatime)
	{
		HatUi::MoveUi();
	}
}
