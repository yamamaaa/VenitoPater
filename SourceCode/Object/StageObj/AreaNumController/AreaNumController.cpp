#include "AreaNumController.h"

namespace object
{
	//���Ԃ����
	std::unique_ptr<AreaNumController>AreaNumController::areanum_controller = nullptr;

	AreaNumController::AreaNumController()
	{
		//�����Ȃ�
	}

	AreaNumController::~AreaNumController()
	{
		//�����Ȃ�
	}

	void AreaNumController::Initialize()
	{
		//���Ԃ���Ȃ�C���X�^���X����
		if (!areanum_controller)
		{
			areanum_controller.reset(new AreaNumController);
		}

		LoadObject();
	}

	void AreaNumController::LoadObject()
	{
		//�G���A�ԍ������l�Z�b�g
		areanum_controller->m_NowAreaNum = 1;
	}
}