#include "RPMController.h"

namespace object
{
	//実態を空に
	std::unique_ptr<RPMController>RPMController::rpm_controller = nullptr;

	RPMController::RPMController()
	{
		//処理なし
	}

	RPMController::~RPMController()
	{
		//処理なし
	}

	void RPMController::Initialize()
	{
		//実態が空ならインスタンス生成
		if (!rpm_controller)
		{
			rpm_controller.reset(new RPMController);
		}

		LoadObjec();
	}

	void RPMController::LoadObjec()
	{
		//回転量状態初期化
		rpm_controller->m_IsRPMLost = false;
		rpm_controller->m_RPMHp = rpm_controller->m_RPMHPMAX;
	}
}