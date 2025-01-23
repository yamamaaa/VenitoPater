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

		const std::string GetFontData()const { return font; }
		const std::string Get_FontTagData()const { return fonttag; }

	private:

		std::string font;
		std::string fonttag;
	};
}