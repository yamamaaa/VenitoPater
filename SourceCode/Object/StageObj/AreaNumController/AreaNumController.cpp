#include "AreaNumController.h"

namespace object
{
	//実態を空に
	std::unique_ptr<AreaNumController>AreaNumController::areanum_controller = nullptr;

	AreaNumController::AreaNumController()
	{
		//処理なし
	}

	AreaNumController::~AreaNumController()
	{
		//処理なし
	}

	void AreaNumController::Initialize()
	{
		//実態が空ならインスタンス生成
		if (!areanum_controller)
		{
			areanum_controller.reset(new AreaNumController);
		}

		LoadObjec();
	}

	void AreaNumController::LoadObjec()
	{
		//エリア番号初期値セット
		areanum_controller->m_NowAreaNum = 1;
	}
}