#pragma once
#include<string>
#include"../json.hpp"

using Json = nlohmann::json;

namespace json_imgdata 
{
	/// <summary>
	/// Play����JsonImg�f�[�^�Ǘ��N���X
	/// </summary>
	class TitleData
	{
	public:

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		/// <param name="json">Json�t�@�C��</param>
		TitleData(Json json);

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~TitleData();

		const std::string GetMenuData()const { return menu; }
		const std::string GetScreenData()const { return screen; }
		const std::string GetSelectData()const { return select; }
		const std::string GetTVData()const { return tv; }

	private:

		std::string menu;
		std::string screen;
		std::string select;
		std::string tv;
	};
}