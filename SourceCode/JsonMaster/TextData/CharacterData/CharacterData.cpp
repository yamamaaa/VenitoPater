#include "CharacterData.h"

namespace json_textdata
{
	CharacterData::CharacterData(Json json)
	{
		expressionData.day_0 = json["expression"]["day_0"];
		expressionData.day_1 = json["expression"]["day_1"];
		expressionData.day_4 = json["expression"]["day_4"];

		itemData.day_0 = json["item"]["day_0"];
		itemData.day_4 = json["item"]["day_4"];

		lineData.day_0 = json["line"]["day_0"];
		lineData.day_1 = json["line"]["day_1"];
		lineData.day_4 = json["line"]["day_4"];
		lineData.gameover = json["line"]["gameover"];
	}

	CharacterData::~CharacterData()
	{
		//ˆ—‚È‚µ
	}
}