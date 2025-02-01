#include "AvoidStatus.h"

namespace object
{
	//���Ԃ����
	std::unique_ptr<AvoidStatus>AvoidStatus::avoidstatus = nullptr;

	AvoidStatus::AvoidStatus()
	{
		//�����Ȃ�
	}

	AvoidStatus::~AvoidStatus()
	{
		//�����Ȃ�
	}

	void AvoidStatus::Initialize()
	{
		//�������̂��Ȃ�������C���X�^���X����
		if (!avoidstatus)
		{
			avoidstatus.reset(new AvoidStatus);
		}

		LoadObjec();
	}

	void AvoidStatus::LoadObjec()
	{
		avoidstatus->m_IsAvoid = false;
	}

	void AvoidStatus::Processing()
	{
		avoidstatus.reset();
	}
}