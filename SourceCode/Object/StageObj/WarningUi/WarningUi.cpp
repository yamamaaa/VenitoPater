#include<Dxlib.h>
#include "WarningUi.h"

namespace object
{
	WarningUi::WarningUi()
	{
		//�ǂݍ��݊֘A
		LoadUi();
	}

	WarningUi::~WarningUi()
	{
		//�����Ȃ�
	}

	void WarningUi::LoadUi()
	{
		m_UiPos = { 870,10 };
		m_DrawCount = 0;
		m_UiHandol = 0;
		m_IsWarning = false;
		m_IsBlinking = false;

		//�摜�̓ǂݍ���
		m_UiHandol = LoadGraph("../Asset/image/ui/warning_marc/warning_marc.png");
	}

	void WarningUi::DrawUi()
	{
		//�摜�̓_�ł��s����
		if (m_IsBlinking)
		{
			//20�J�E���g�̂���10��\��
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