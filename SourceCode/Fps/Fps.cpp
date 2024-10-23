#include "Fps.h"

namespace Fps
{
	Fps::Fps()
		:m_nowTime(static_cast<float>(GetNowCount()))
		, m_prevTime(m_nowTime)
		, m_deltaTime(0.0f)
	{
		//�����Ȃ�
	}

	Fps::~Fps()
	{
		//�����Ȃ�
	}

	void Fps::Update()
	{
		//�t���[�����[�g�Z�o
		m_nowTime = static_cast<float>(GetNowCount());
		m_deltaTime = (m_nowTime - m_prevTime) / 1000.0f;
		m_prevTime = m_nowTime;
	}
}
