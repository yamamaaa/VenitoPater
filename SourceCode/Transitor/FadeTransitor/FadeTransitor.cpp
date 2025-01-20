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

	void FadeTransitor::WaitTime()
	{
		if (!m_WaitDone)
		{
			m_WaitCount -= m_COUNT_DECREMENT;

			if (m_WaitCount == 0)
			{
				m_WaitDone = true;
				m_WaitCount = m_WAITMAX;
			}
		}
	}

	void FadeTransitor::LoadObject()
	{
		m_DropCollar = m_COLLARCODE;	//�J���[�R�[�h���������l
		m_IsFadeDone = false;			//�I���X�e�[�^�X�����l
		m_WaitDone = false;				//�ҋ@��ԏ�����
		m_WaitCount = m_WAITMAX;		//�҂����ԃJ�E���g������
	}

	void FadeTransitor::FadeOutStart(bool wait)
	{
		static int drop;

		//�X�^�[�g��x�点�邩
		if (wait)
		{
			WaitTime();	//�x�点��Ȃ�J�E���g
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

	void FadeTransitor::FadeInStart(bool wait)
	{
		static int drop;

		//�X�^�[�g��x�点�邩
		if (wait)
		{
			WaitTime();		//�x�点��Ȃ�J�E���g
		}
		else
		{
			m_WaitDone = true;
		}

		if (m_WaitDone)
		{
			//���񂾂��ʂ𖾂邭
			SetDrawBright(m_DropCollar, m_DropCollar, m_DropCollar);
			m_DropCollar += drop;
			drop -= m_DROPSPEED;

			if (m_DropCollar == m_COLLARCODE)
			{
				m_IsFadeDone = true;	//�����̊���
				m_WaitDone = false;		//�ҋ@��ԏ�����
			}
		}
	}
}