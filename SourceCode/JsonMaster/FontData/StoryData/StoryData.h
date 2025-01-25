#pragma once
#include<string>
#include"../json.hpp"

using Json = nlohmann::json;

namespace json_fontdata
{
	/// <summary>
	/// Story中のJsonFontデータ管理クラス
	/// </summary>
	class StoryData
	{
	public:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="json">Jsonファイル</param>
		StoryData(Json json);

		/// <summary>
		/// デストラクタ
		/// </summary>
		~StoryData();

		const std::string GetFontPath()const { return font; }
		const const char *Get_FontTagToChar()const { return fonttag.c_str(); }

	private:

		std::string font;
		std::string fonttag;
	};
}