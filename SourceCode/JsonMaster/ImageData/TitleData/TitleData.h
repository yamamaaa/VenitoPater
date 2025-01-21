#pragma once
#include<string>
#include"../json.hpp"

using Json = nlohmann::json;

namespace json_imgdata 
{
	/// <summary>
	/// Play中のJsonImgデータ管理クラス
	/// </summary>
	class TitleData
	{
	public:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="json">Jsonファイル</param>
		TitleData(Json json);

		/// <summary>
		/// デストラクタ
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