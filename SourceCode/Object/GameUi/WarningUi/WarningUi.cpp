#include "WarningUi.h"
#include "../../ObjectTag/Play_ObjectTag.h"
#include "../../StageObj/ClockWork/RPMController/RPMController.h"
#include "../../StageObj/AreaNumController/AreaNumController.h"

namespace object
{
	WarningUi::WarningUi()
		:ObjectBase(play_ObjectTag.WARNINGUI)
	{
		//読み込み関連
		LoadObject();
	}

	WarningUi::~WarningUi()
	{
		DeleteGraph(m_ObjHandle);
	}

	void WarningUi::LoadObject()
	{
		m_ObjPos = { 879,10 };
		m_DrawCount = 0;
		m_CanDraw = false;
		m_IsBlinking = false;

		//画像の読み込み
		m_ObjHandle = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetUiData_Warning().c_str());
	}

	void WarningUi::UpdateObj(const float deltatime)
	{
		float rpmhp = RPMController::GetRPMHp();

		//回転量が警告値に達したら警告を出す
		if (rpmhp <= m_WARNING_VALUE)
		{
			if (AreaNumController::GetAreaNum() != m_Hide_DrawArea)
			{
				m_CanDraw = true;	//表示状態のセット
			}
			else
			{
				m_CanDraw = false;
			}
			m_IsBlinking = true;		//Ui点滅状態のセット
		}
		if (rpmhp <= 0.0f) //0以下は警告Uiを点滅させない
		{
			m_IsBlinking = false;
		}
	}

	void WarningUi::DrawObj()
	{
		if (!m_CanDraw)	//表示できないとき処理なし
			return;

		//画像の点滅を行うか
		if (m_IsBlinking)
		{
			//20カウントのうち10回表示
			m_DrawCount = (m_DrawCount + 1) % m_PWRIOD;
			if (m_DrawCount < m_NUMTIMES)
			{
				DrawGraph(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), m_ObjHandle, TRUE);
			}
		}
		else
		{
			DrawGraph(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), m_ObjHandle, TRUE);
		}
	}
}