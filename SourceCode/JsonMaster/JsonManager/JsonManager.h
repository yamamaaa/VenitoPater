#pragma once
#include<memory>

#include "../ImageData/MasterImgData/MasterImgData.h"
#include "../TextData/MasterTextData/MasterTextData.h"

namespace jsonmaster
{
	/// <summary>
	/// Json�f�[�^�Ǘ��N���X
	/// </summary>
	class JsonManager final
	{
	public:

		/// <summary>
		/// ������
		/// </summary>
		static void InitJsonManager();

		///<summary>
		///�C���[�W�C���X�^���X
		///</summary>
		///<returns>�C���[�W�f�[�^</returns>
		static class json_imgdata::MasterImgData* ImgData_Instance() { return json_manager->master_img_data.get(); }

		///<summary>
		///�e�L�X�g�C���X�^���X
		///</summary>
		///<returns>�e�L�X�g�f�[�^</returns>
		static class json_textdata::MasterTextData* TextData_Instance() { return json_manager->master_text_data.get(); }

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~JsonManager();

	private:

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		JsonManager();

		static std::unique_ptr<class JsonManager> json_manager;//���g�̎���

		std::unique_ptr<class json_imgdata::MasterImgData> master_img_data;
		std::unique_ptr<class json_textdata::MasterTextData> master_text_data;
	};
}