#include "WarningUi.h"
#include "../../ObjectTag/Play_ObjectTag.h"
#include "../../StageObj/ClockWork/RPMController/RPMController.h"
#include "../../StageObj/AreaNumController/AreaNumController.h"

namespace object
{
	WarningUi::WarningUi()
		:ObjectBase(play_ObjectTag.WARNINGUI)
	{
		//�ǂݍ��݊֘A
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

		//�摜�̓ǂݍ���
		m_ObjHandle = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetUiData_Warning().c_str());
	}

	void WarningUi::UpdateObj(const float deltatime)
	{
		float rpmhp = RPMController::GetRPMHp();

		//��]�ʂ��x���l�ɒB������x�����o��
		if (rpmhp <= m_WARNING_VALUE)
		{
			if (AreaNumController::GetAreaNum() != m_Hide_DrawArea)
			{
				m_CanDraw = true;	//�\����Ԃ̃Z�b�g
			}
			else
			{
				m_CanDraw = false;
			}
			m_IsBlinking = true;		//Ui�_�ŏ�Ԃ̃Z�b�g
		}
		if (rpmhp <= 0.0f) //0�ȉ��͌x��Ui��_�ł����Ȃ�
		{
			m_IsBlinking = false;
		}
	}

	void WarningUi::DrawObj()
	{
		if (!m_CanDraw)	//�\���ł��Ȃ��Ƃ������Ȃ�
			return;

		//�摜�̓_�ł��s����
		if (m_IsBlinking)
		{
			//20�J�E���g�̂���10��\��
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