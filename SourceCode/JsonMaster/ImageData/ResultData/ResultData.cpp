#include "ResultData.h"

namespace json_imgdata
{
	ResultData::ResultData(Json json)
	{
		gameClearData.background = json["gameclear"]["background"];

		gameOverData.background = json["gameover"]["background"];
		gameOverData.select = json["gameover"]["select"];
	}

	ResultData::~ResultData()
	{
		//ˆ—‚È‚µ
	}
}