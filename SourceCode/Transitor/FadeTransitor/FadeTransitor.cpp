#include <Dxlib.h>
#include "FadeTransitor.h"

namespace transitor
{
	FadeTransitor::FadeTransitor()
	{
		//�ǂݍ��݊֘A
		LoadObject();
	}

	FadeTransitor::~FadeTransitor()
	{
		//��������
	}

	const void FadeTransitor::FadeProcessing()
	{
		//�ǂݍ��݊֘A
		LoadObject();
	}

	void FadeTransitor::WaitTime()
	{
		if (!m_WaitDone)
		{
			m_WaitCount -= m_COUNT_DECREMENT;

			if (m_WaitCount <= 0.0f)
			{
				m_WaitDone = true;
			}
		}
	}

	void FadeTransitor::LoadObject()
	{
		m_IsFadeDone = false;			//�I���X�e�[�^�X�����l
		m_WaitDone = false;				//�ҋ@��ԏ�����
		m_CanFade = false;				//�J�n��ԏ�����
		m_WaitCount = m_WAITMAX;		//�҂����ԃJ�E���g������
		m_Calculation = 0.0f;
	}

	void FadeTransitor::FadeOutStart(bool wait)
	{
		//�X�^�[�g��x�点�邩
		if (wait)
		{
			WaitTime();	//�x�点��Ȃ�J�E���g
		}
		else
		{
			m_WaitDone = true;
		}

		if (!m_CanFade)
		{
			m_Collar = m_COLLARCODE;	//�J���[�R�[�h�����l
			m_CanFade = true;
		}

		if (m_WaitDone)
		{
			//���񂾂��ʂ��Â�����
			SetDrawBright(m_Collar, m_Collar, m_Collar);
			m_Collar -= static_cast<int>(m_Calculation);
			m_Calculation += m_DROPSPEED;

			if (m_Collar <= 0)
			{
				m_IsFadeDone = true;	//�����̊���
				m_Collar = 0;			//�덷�̏C��
			}
		}

		DrawFormatString(700, 300, GetColor(255, 255, 255), "�J���[�R�[�h:%d", m_Collar);
	}

	void FadeTransitor::FadeInStart(bool wait)
	{
		//�X�^�[�g��x�点�邩
		if (wait)
		{
			WaitTime();		//�x�点��Ȃ�J�E���g
		}
		else
		{
			m_WaitDone = true;
		}

		if (!m_CanFade)
		{
			m_Collar = 0;	//�J���[�R�[�h�����l
			m_CanFade = true;
		}

		if (m_WaitDone)
		{
			//���񂾂��ʂ𖾂邭
			SetDrawBright(m_Collar, m_Collar, m_Collar);
			m_Collar += static_cast<int>(m_Calculation);
			m_Calculation += m_RISESPEED;

			if (m_Collar >= m_COLLARCODE)
			{
				m_IsFadeDone = true;			//�����̊���
				m_Collar = m_COLLARCODE;		//�덷�̏C��
			}
		}

		DrawFormatString(700, 300, GetColor(255, 255, 255), "�J���[�R�[�h:%d", m_Collar);
	}
}