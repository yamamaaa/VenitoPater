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
		//�ǂݍ��݊֘A
		LoadObject();
	}

	ClockWork::~ClockWork()
	{
		delete warningui;	//���������
	}

	void ClockWork::LoadObject()
	{
		m_AnimNowPattern = 0;
		m_AnimTimer = 0.0f;
		m_AnimNowIndex = 0;

		warningui = new WarningUi;
		RPMController::Initialize();

		m_ObjPos.x = 892.0f;	//���W�����l�Z�b�g
		m_ObjPos.y = 660.0f;

		m_ObjSize.x = 130;	//�����蔻��T�C�Y�Z�b�g
		m_ObjSize.y = 200;

		m_DrawOffset.x = -19;	//�����蔻�肸�炵�ʃZ�b�g
		m_DrawOffset.y = 20;

		m_HPDrawPos.x = 710;
		m_HPDrawPos.y = 540;

		m_FillBoxSize.x = 0;
		m_FillBoxSize.y = 60;

		m_LineBoxSize.x = 500;
		m_LineBoxSize.y = 60;

		m_FillBox_Collar = VGet(255, 255, 0);
		m_LineBox_Collar = VGet(255, 255, 255);

		//�摜�̓ǂݍ���
		LoadDivGraph("../Asset/image/clockwork/clockwork.png", m_AnimPattern * m_AnimType, m_AnimPattern, m_AnimType, m_colwidth, m_colheight, m_Handle);
	}

	void ClockWork::UpdateObj(const float deltatime)
	{
		//HP�\����ԏ�����
		m_CanDrawHP = false;

		float rpmhp = RPMController::GetRPMHp();

		//�I�u�W�F�N�g���\������Ă���Ƃ�
		if (m_CanDraw)
		{	
			CheckHitMouse();

			if (m_IsClickNow)
			{
				rpmhp++;						//��]��Hp�𑝂₷
				m_AnimationFPS = m_CLICK_FPS;	//�A�j���[�V�����ݒ�
				MoveObj(deltatime);
			}
			m_IsClickNow = false;
			m_AnimationFPS = m_DEFAULT_FPS;
		}

		//���݂̃G���A�ԍ����擾
		int infodata = AreaNumController::GetAreaNum();

		//�\���\��
		if (infodata == m_DrawAreaNum)
		{
			m_CanDraw = true;
		}
		else
		{
			m_CanDraw = false;
		}

		//��]�ʂ��x���l�ɒB������x�����o��
		if (rpmhp <= m_WARNING_VALUE)
		{
			if (infodata != m_DrawAreaNum)
			{
				warningui->SetIsWarning(true);	//�\����Ԃ̃Z�b�g
			}
			else
			{
				warningui->SetIsWarning(false);
			}
			warningui->SetIsBlinking(true);		//Ui�_�ŏ�Ԃ̃Z�b�g
		}
		if (rpmhp <= 0.0f) //0�ȉ��͌x��Ui��_�ł����Ȃ�
		{
			RPMController::SetIsRPMLost(true);
			warningui->SetIsBlinking(false);
		}

		//��]�ʂ�0�ȉ��̏ꍇ�����Ȃ�
		if (RPMController::GetIsRPMLost())
			return;

		//��]��Hp��0�ȏ�̎�
		if (rpmhp > 0.0f)
		{
			float decrement=RPMController::GetRPMDecrement();
			rpmhp -= decrement; 		//Hp���炵������
			DrawValue = rpmhp;

			MoveObj(deltatime);
		}

		RPMController::SetRPMHp(rpmhp);		//Hp���Z�b�g
	}

	void ClockWork::MoveObj(const float deltatime)
	{
		m_AnimTimer += deltatime;

		//�A�j���[�V�����̌v�Z
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
		CursorHit();	//�J�[�\���Ƃ̓����蔻��

		if (GetCursorHit())	//�������Ă�����
		{
			m_CanDrawHP = true;		//HP��\��
			CanClick();				//�N���b�N�ł��邩�H

			//�N���b�N��Ԃŏ�����HP��0�ȏ�̎�
			if (GetStateClick() && !RPMController::GetIsRPMLost())
			{
				//HP��m_RPMHPMAX(500)�ȉ���������
				if (RPMController::GetRPMHp() <= RPMController::GetRPMHpMax())
				{
					m_IsClickNow = true;	//�N���b�N��Ԃ�true��
				}
			}
		}
		else
		{
			m_CanDrawHP = false;	//�f�t�H���g�͔�\��
		}
	}

	void ClockWork::DrawObj()
	{
		//�x����ԂȂ�Ui�̕\��
		if (warningui->GetIsWarning())
		{
			warningui->DrawUi();
		}
	
		//�\���ł����ԂȂ�
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