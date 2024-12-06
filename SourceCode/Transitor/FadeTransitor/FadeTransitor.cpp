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

	void FadeTransitor::WaitTimerStart()
	{
		if (!m_WaitDone)
		{
			m_WaitCount += 1.0f;

			if (m_WaitCount >= 50.0f)
			{
				m_WaitDone = true;
			}
		}
	}

	void FadeTransitor::LoadObject()
	{
		m_DropCollar = m_COLLARCODE;	//�J���[�R�[�h���������l
		m_IsFadeDone = false;			//�I���X�e�[�^�X�����l
		m_WaitDone = false;				//�ҋ@��ԏ�����
		m_WaitCount = 0.0f;
	}

	void FadeTransitor::FadeOutStart(bool wait)
	{
		static int drop;
		static bool iswait = wait;

		if (iswait)
		{
			WaitTimerStart();
		}
		else
		{
			m_WaitDone = true;
		}

		if (m_WaitDone)
		{
			//���񂾂��ʂ��Â�����
			SetDrawBright(m_DropCollar, m_DropCollar, m_DropCollar);
			m_DropCollar -= drop;
			drop += m_DROPSPEED;

			if (m_DropCollar <= 0)
			{
				m_IsFadeDone = true;	//�����̊���
				m_WaitDone = false;		//�ҋ@��ԏ�����
			}
		}
	}
}