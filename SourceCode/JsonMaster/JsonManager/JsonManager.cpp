#include "JsonManager.h"
//#include "../Image/MasterImgData/MasterImgData.h"

namespace jsonmaster
{
	std::unique_ptr<JsonManager>JsonManager::json_manager = nullptr;

	JsonManager::JsonManager()
		//:masterimgdata(new MasterImgData)
	{
		//�����Ȃ�
	}

	void JsonManager::InitJsonManager()
	{
		//���Ԃ��󂾂�����C���X�^���X����
		if (!json_manager)
		{
			json_manager.reset(new JsonManager);
		}
	}

	JsonManager::~JsonManager()
	{
		//���
		//masterimgdata.release();
	}
}
