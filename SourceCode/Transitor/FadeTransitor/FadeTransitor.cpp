#include <Dxlib.h>
#include "FadeTransitor.h"
#include "../../MouseStatus/MouseStatus.h"
#include "../../SoundController/SoundController.h"

namespace transitor
{
	std::unique_ptr<FadeTransitor>FadeTransitor::fadetransitor = nullptr;

	FadeTransitor::FadeTransitor()
	{
		//�����Ȃ�
	}

	FadeTransitor::~FadeTransitor()
	{
		//�����Ȃ�
	}

	void FadeTransitor::Initialize()
	{
		//���Ԃ���Ȃ�C���X�^���X����
		if (!fadetransitor)
		{
			fadetransitor.reset(new FadeTransitor);
		}

		//�ǂݍ��݊֘A
		LoadObject();
	}

	void FadeTransitor::LoadObject()
	{
		fadetransitor->m_IsFadeDone = false;						//�I���X�e�[�^�X�����l
		fadetransitor->m_IsWait = false;							//�ҋ@��ԏ�����
		fadetransitor->m_CanFade = false;							//�J�n��ԏ�����
		fadetransitor->m_WaitCount = fadetransitor->m_WAITMAX;		//�҂����ԃJ�E���g������
		fadetransitor->m_Calculation = 0.0f;
		fadetransitor->m_Color = 0;
	}

	void FadeTransitor::FadeInStart(const float deltatime)
	{
		if (!fadetransitor->m_CanFade)
		{
			fadetransitor->m_Color = 0;	//�J���[�R�[�h�����l
			fadetransitor->m_CanFade = true;
			mousestatus::MouseStatus::SetIsFadeDone(false);		//���͂̎�t���~
		}

		if (fadetransitor->m_CanFade)
		{
			if (fadetransitor->m_Color >= m_COLORCODE)
			{
				fadetransitor->m_IsFadeDone = true;			//�����̊���
				fadetransitor->m_Color = m_COLORCODE;		//�덷�̏C��
				mousestatus::MouseStatus::SetIsFadeDone(true);		//���͂̎�t���J�n
			}
			else
			{
				fadetransitor->m_Color += static_cast<int>(fadetransitor->m_Calculation);
				fadetransitor->m_Calculation += fadetransitor->m_RISESPEED * deltatime;
			}
		}
	}

	void FadeTransitor::FadeOutStart(const float deltatime)
	{
		//�X�^�[�g��x�点��
		if (!fadetransitor->m_IsWait)
		{
			WaitTime(deltatime);
		}

		if (!fadetransitor->m_CanFade)
		{
			fadetransitor->m_Color = m_COLORCODE;	//�J���[�R�[�h�����l
			fadetransitor->m_CanFade = true;
			mousestatus::MouseStatus::SetIsFadeDone(false);		//���͂̎�t���~
		}

		if (fadetransitor->m_IsWait)
		{
			sound_controller::SoundController::BGMSoundFadeOut(deltatime);

			if (fadetransitor->m_Color <= 0)
			{
				if (!sound_controller::SoundController::IsDoneSoundFade())
					return;

				fadetransitor->m_IsFadeDone = true;	//�����̊���
				fadetransitor->m_Color = 0;			//�덷�̏C��
				sound_controller::SoundController::FadeSoundProcessing();
				mousestatus::MouseStatus::SetIsFadeDone(true);		//���͂̎�t���J�n
			}
			else
			{
				//���񂾂��ʂ��Â�����
				fadetransitor->m_Color -= static_cast<int>(fadetransitor->m_Calculation);
				fadetransitor->m_Calculation += fadetransitor->m_DROPSPEED * deltatime;
			}
		}
	}

	void FadeTransitor::DrawFade()
	{
		SetDrawBright(fadetransitor->m_Color, fadetransitor->m_Color, fadetransitor->m_Color);
		DrawFormatString(700, 300, GetColor(255, 255, 255), "�J���[�R�[�h:%d", fadetransitor->m_Color);
	}

	void FadeTransitor::WaitTime(const float deltatime)
	{
		fadetransitor->m_WaitCount -= fadetransitor->m_COUNT_DECREMENT* deltatime;

		if (fadetransitor->m_WaitCount <= 0.0f)
		{
			fadetransitor->m_IsWait = true;
		}
	}

	void FadeTransitor::FadeProcessing()
	{
		//�ǂݍ��݊֘A
		LoadObject();
	}
}