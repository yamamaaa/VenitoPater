#include "RPMController.h"

namespace object
{
	//���Ԃ����
	std::unique_ptr<RPMController>RPMController::rpm_controller = nullptr;

	RPMController::RPMController()
	{
		//�����Ȃ�
	}

	RPMController::~RPMController()
	{
		//�����Ȃ�
	}

	void RPMController::Initialize()
	{
		//���Ԃ���Ȃ�C���X�^���X����
		if (!rpm_controller)
		{
			rpm_controller.reset(new RPMController);
		}

		LoadObjec();
	}

	void RPMController::LoadObjec()
	{
		//��]�ʏ�ԏ�����
		rpm_controller->m_IsRPMLost = false;
		rpm_controller->m_RPMHp = rpm_controller->m_RPMHPMAX;
	}
}