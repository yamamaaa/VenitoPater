#include "JsonManager.h"

namespace jsonmaster
{
	std::unique_ptr<JsonManager>JsonManager::json_manager = nullptr;

	JsonManager::JsonManager()
		: master_img_data(new json_imgdata::MasterImgData),
		master_text_data(new json_textdata::MasterTextData),
		master_font_data(new json_fontdata::MasterFontData)
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
		//�����Ȃ�
	}
}
