#include "LineStatus.h"

namespace object
{
	std::unique_ptr<LineStatus>LineStatus::linestatus = nullptr;

	LineStatus::LineStatus()
	{
		//�����Ȃ�
	}

	LineStatus::~LineStatus()
	{
		//�����Ȃ�
	}

	void LineStatus::Initialize()
	{
		//���Ԃ���Ȃ�C���X�^���X����
		if (!linestatus)
		{
			linestatus.reset(new LineStatus);
		}

		LoadObject();
	}

	void LineStatus::LoadObject()
	{
		linestatus->m_IsDoneAnim = false;
	}
}