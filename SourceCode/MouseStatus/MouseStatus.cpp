#include "MouseStatus.h"

namespace mousestatus
{
	std::unique_ptr<MouseStatus>MouseStatus::mousestatus = nullptr;

	MouseStatus::MouseStatus()
	{
		//�����Ȃ�
	}

	MouseStatus::~MouseStatus()
	{
		//�����Ȃ�
	}

	void MouseStatus::Initialize()
	{
		//���Ԃ���Ȃ�C���X�^���X����
		if (!mousestatus)
		{
			mousestatus.reset(new MouseStatus);
		}

		//�ǂݍ��݊֘A
		LoadObject();
	}

	void MouseStatus::LoadObject()
	{
		//������
		mousestatus->m_IsInput = false;
	}
}