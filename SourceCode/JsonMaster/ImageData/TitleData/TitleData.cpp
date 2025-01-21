#include "TitleData.h"

namespace json_imgdata
{
	TitleData::TitleData(Json json)
	{
		menu = json["menu"];
		screen = json["screen"];
		select = json["select"];
		tv = json["tv"];
	}

	TitleData::~TitleData()
	{
		//ˆ—‚È‚µ
	}
}