#pragma once
#include<string>
#include"../json.hpp"

using Json = nlohmann::json;

namespace json_textdata
{
	/// <summary>
	/// CharacterのJsonTextデータ管理クラス
	/// </summary>
	class CharacterData
	{
	public:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="json">Jsonファイル</param>
		CharacterData(Json json);

		/// <summary>
		/// デストラクタ
		/// </summary>
		~CharacterData();

		const std::string GetExpressionData_Day_0()const { return expressionData.day_0; }
		const std::string GetExpressionData_Day_1()const { return expressionData.day_1; }
		const std::string GetExpressionData_Day_4()const { return expressionData.day_4; }

		const std::string GetItemData_Day_0()const { return itemData.day_0; }
		const std::string GetItemData_Day_4()const { return itemData.day_4; }

		const std::string GetLineData_Day_0()const { return lineData.day_0; }
		const std::string GetLineData_Day_1()const { return lineData.day_1; }
		const std::string GetLineData_Day_4()const { return lineData.day_4; }
		const std::string GetLineData_GameOver()const { return lineData.gameover; }

	private:

		struct ExpressionData
		{
			std::string day_0;
			std::string day_1;
			std::string day_4;
		}expressionData;

		struct ItemData
		{
			std::string day_0;
			std::string day_4;
		}itemData;

		struct LineData
		{
			std::string day_0;
			std::string day_1;
			std::string day_4;
			std::string gameover;
		}lineData;
	};
}