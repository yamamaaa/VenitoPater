#include "ClockWork.h"
#include "../../../ObjectTag/Global_ObjectTag.h"
#include "../../../ObjectManager/ObjectManager.h"
#include "../../AreaNumController/AreaNumController.h"
#include "../../ClockWork/RPMController/RPMController.h"
#include "../../../CharaObj/Enemy/EnemyManager/EnemyManager.h"

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
		//�����Ȃ�
	}

	void ClockWork::LoadObject()
	{
		m_AnimNowPattern = 0;
		m_AnimTimer = 0.0f;
		m_AnimNowIndex = 0;

		RPMController::Initialize();

		m_ObjPos.x = 892.0f;	//���W�����l�Z�b�g
		m_ObjPos.y = 660.0f;

		m_ObjSize.x = 130;	//�����蔻��T�C�Y�Z�b�g
		m_ObjSize.y = 200;

		m_DrawOffset.x = -19;	//�����蔻�肸�炵�ʃZ�b�g
		m_DrawOffset.y = 20;

		m_AnimationFPS = m_DEFAULT_FPS;       // �A�j���[�V����FPS�����l

		//�摜�̓ǂݍ���
		LoadDivGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetClockWork().c_str(), m_AnimPattern * m_AnimType, m_AnimPattern, m_AnimType, m_colwidth, m_colheight, m_Handle);
	}

	void ClockWork::UpdateObj(const float deltatime)
	{
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

		//��]�ʂ�0�ȉ��̏ꍇ�����Ȃ�
		if (RPMController::GetIsRPMLost())
			return;

		//��]��Hp��0�ȏ�̎�
		if (rpmhp > 0.0f)
		{
			float decrement = RPMController::GetRPMDecrement();

			//���������X�^�[���A�N�V�������N��������
			if (EnemyManager::GetBeefUpEmyIsAction())
			{
				//HP���炵�ʂ𑝉�����
				decrement *= m_EMYRPM_DECREMENT;
			}

			rpmhp -= decrement; 		//Hp���炵������
			MoveObj(deltatime);
		}
		else
		{
			RPMController::SetIsRPMLost(true);
		}

		RPMController::SetRPMHp(rpmhp);		//Hp���Z�b�g
	}

	void ClockWork::MoveObj(const float deltatime)
	{
		//�\���s�̎������Ȃ�
		if (!m_CanDraw)
			return;

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
	}

	void ClockWork::DrawObj()
	{
		//�\���ł����ԂȂ�
		if (m_CanDraw)
		{
			DrawGraph(static_cast<int>(m_ObjPos.x) + m_DrawOffset.x, static_cast<int>(m_ObjPos.y) + m_DrawOffset.y, m_Handle[m_AnimNowIndex], TRUE);
#ifdef DEBUG
			DrawBox(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), static_cast<int>(m_ObjPos.x) + m_ObjSize.x, static_cast<int>(m_ObjPos.y) + m_ObjSize.y, GetColor(255, 40, 0), FALSE);
#endif
		}
#ifdef DEBUG
		DrawFormatString(0, 360, GetColor(255, 255, 255), "m_AnimNowIndex:%d", m_AnimNowIndex);
		DrawFormatString(0, 380, GetColor(255, 255, 255), "Hp:%f", RPMController::GetRPMHp());
#endif
	}
}