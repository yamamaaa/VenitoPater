#pragma once
#include<string>
#include"../json.hpp"

using Json = nlohmann::json;

namespace json_imgdata
{
	/// <summary>
	/// Result中のJsonImgデータ管理クラス
	/// </summary>
	class ResultData
	{
	public:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="json">Jsonファイル</param>
		ResultData(Json json);

		/// <summary>
		/// デストラクタ
		/// </summary>
		~ResultData();

		const std::string GetClearData_BackGround()const { return gameClearData.background; }

		const std::string GetOverData_BackGround()const { return gameOverData.background; }
		const std::string GetOverData_Select()const { return gameOverData.select; }

	private:

		struct GameClearData
		{
			std::string background;
		}gameClearData;

		struct GameOverData
		{
			std::string background;
			std::string select;
		}gameOverData;
	};
}