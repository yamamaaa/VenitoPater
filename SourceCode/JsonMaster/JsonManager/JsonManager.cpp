#include "JsonManager.h"
//#include "../Image/MasterImgData/MasterImgData.h"

namespace jsonmaster
{
	std::unique_ptr<JsonManager>JsonManager::json_manager = nullptr;

	JsonManager::JsonManager()
		//:masterimgdata(new MasterImgData)
	{
		//処理なし
	}

	void JsonManager::InitJsonManager()
	{
		//実態が空だったらインスタンス生成
		if (!json_manager)
		{
			json_manager.reset(new JsonManager);
		}
	}

	JsonManager::~JsonManager()
	{
		//解放
		//masterimgdata.release();
	}
}
