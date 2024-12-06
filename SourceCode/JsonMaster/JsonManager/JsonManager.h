#pragma once
#include<memory>

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

		/// <summary>
		/// �C���[�W�C���X�^���X
		/// </summary>
		/// <returns>�C���[�W�f�[�^</returns>
		//static class MasterImgData* ImgDataInstance() { return json_manager->masterimgdata.get(); }
		
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

		//std::unique_ptr<class MasterImgData> master_img_data;//ImgJson�̎���
	};
}