#include<Dxlib.h>
#include "WarningUi.h"

namespace object
{
	WarningUi::WarningUi()
	{
		//読み込み関連
		LoadUi();
	}

	WarningUi::~WarningUi()
	{
		//処理なし
	}

	void WarningUi::LoadUi()
	{
		m_UiPos = { 870,10 };
		m_DrawCount = 0;
		m_UiHandol = 0;
		m_IsWarning = false;
		m_IsBlinking = false;

		//画像の読み込み
		m_UiHandol = LoadGraph("../Asset/image/ui/warning_marc/warning_marc.png");
	}

	void WarningUi::DrawUi()
	{
		//画像の点滅を行うか
		if (m_IsBlinking)
		{
			//20カウントのうち10回表示
			m_DrawCount = (m_DrawCount + 1) % m_PWRIOD;
			if (m_DrawCount < m_NUMTIMES)
			{
				DrawGraph(m_UiPos.x, m_UiPos.y, m_UiHandol, TRUE);
			}
		}
		else
		{
			DrawGraph(m_UiPos.x, m_UiPos.y, m_UiHandol, TRUE);
		}
	}
}