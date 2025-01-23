#include "StillData.h"

namespace json_textdata
{
	StillData::StillData(Json json)
	{
		lineData.day_0 = json["line"]["day_0"];
		lineData.day_1 = json["line"]["day_1"];
		lineData.day_2 = json["line"]["day_2"];
		lineData.day_3 = json["line"]["day_3"];
		lineData.day_4 = json["line"]["day_4"];

		drawImgData.day_0 = json["drawimg"]["day_0"];
		drawImgData.day_1 = json["drawimg"]["day_1"];
		drawImgData.day_2 = json["drawimg"]["day_2"];
		drawImgData.day_3 = json["drawimg"]["day_3"];
		drawImgData.day_4 = json["drawimg"]["day_4"];
	}

	StillData::~StillData()
	{
		//ˆ—‚È‚µ
	}
}