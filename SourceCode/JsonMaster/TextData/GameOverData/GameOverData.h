#pragma once
#include<string>
#include"../json.hpp"

using Json = nlohmann::json;

namespace json_textdata
{
    /// <summary>
    /// ameOverのJsonTextデータ管理クラス
    /// </summary>
    class GameOverData
    {
	public:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="json">Jsonファイル</param>
		GameOverData(Json json);

		/// <summary>
		/// デストラクタ
		/// </summary>
		~GameOverData();

		const std::string GetGameOverData_line_0()const { return line_0; }
		const std::string GetGameOverData_line_1()const { return line_1; }
		const std::string GetGameOverData_line_2()const { return line_2; }
		const std::string GetGameOverData_line_3()const { return line_3; }

		const std::string GetGameOverData_TimeOver()const { return timeover; }

	private:

		std::string line_0;
		std::string line_1;
		std::string line_2;
		std::string line_3;

		std::string timeover;
    };
}

