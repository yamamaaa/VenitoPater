#include "RPMHPUi.h"
#include "../../ObjectTag/Global_ObjectTag.h"
#include "../../StageObj/AreaNumController/AreaNumController.h"
#include "../../StageObj/ClockWork/RPMController/RPMController.h"

namespace object
{
	RPMHPUi::RPMHPUi()
		:MouseBase(global_objecttag.RPMHPUi)
	{
		//�ǂݍ��݊֘A
		LoadObject();
	}

	RPMHPUi::~RPMHPUi()
	{
	}

	void RPMHPUi::LoadObject()
	{
		m_ObjPos.x = 892.0f;	//���W�����l�Z�b�g
		m_ObjPos.y = 660.0f;

		m_ObjSize.x = 130;	    //�����蔻��T�C�Y�Z�b�g
		m_ObjSize.y = 200;

		m_HPDrawPos.x = 710;
		m_HPDrawPos.y = 540;

		m_FillBoxSize.x = 0;
		m_FillBoxSize.y = 60;

		m_LineBoxSize.x = 500;
		m_LineBoxSize.y = 60;

		m_FillBox_Color = VGet(255, 255, 0);
		m_LineBox_Color = VGet(255, 255, 255);

		m_CanDraw = false;
	}

	void RPMHPUi::UpdateObj(const float deltatime)
	{
		if (m_DrawArea == AreaNumController::GetAreaNum())
		{
			CursorHit();	//�J�[�\���Ƃ̓����蔻��

			if (GetCursorHit())	//�������Ă�����
			{
				m_CanDraw = true;	//HP��\��
			}
			else
			{
				m_CanDraw = false;
			}
			//HP�c�ʂ��擾
			m_DrawValue = RPMController::GetRPMHp();
		}
		else
		{
			m_CanDraw = false;	//�f�t�H���g�͔�\��
		}
	}

	void RPMHPUi::DrawObj()
	{
		if (m_CanDraw)
		{
			DrawFillBox(static_cast<int>(m_HPDrawPos.x), static_cast<int>(m_HPDrawPos.y), static_cast<int>(m_HPDrawPos.x) + static_cast<int>(m_DrawValue), static_cast<int>(m_HPDrawPos.y) + m_FillBoxSize.y, GetColor(static_cast<int>(m_FillBox_Color.x), static_cast<int>(m_FillBox_Color.y), static_cast<int>(m_FillBox_Color.z)));
			DrawLineBox(static_cast<int>(m_HPDrawPos.x), static_cast<int>(m_HPDrawPos.y), static_cast<int>(m_HPDrawPos.x) + m_LineBoxSize.x, static_cast<int>(m_HPDrawPos.y) + m_LineBoxSize.y, GetColor(static_cast<int>(m_LineBox_Color.x), static_cast<int>(m_LineBox_Color.y), static_cast<int>(m_LineBox_Color.z)));
		}
	}
}