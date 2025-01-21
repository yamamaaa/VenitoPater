#include "StoryImgData.h"

namespace json_imgdata
{
	StoryImgData::StoryImgData(Json json)
	{
		flame = json["global"]["flame"];

		backgroundData.lounge = json["character"]["background"]["lounge"];
		backgroundData.stage = json["character"]["background"]["stage"];

		SetJsonData_Familia(json["character"]["familia"]);

		itemdata.backfade = json["character"]["item"]["backfade"];
		itemdata.duck = json["character"]["item"]["duck"];
		itemdata.guard_set = json["character"]["item"]["guard_set"];
		itemdata.medicine = json["character"]["item"]["medicine"];

		SetJsonData_Still(json["still"]);
	}

	StoryImgData::~StoryImgData()
	{
		//èàóùÇ»Çµ
	}

	void StoryImgData::SetJsonData_Familia(Json json)
	{
		for (int i = 0; i < 9; i++)
		{
			familiaData.name[i] = json["name"][i];
			familiaData.image[i] = json["image"][i];
		}
	}

	void StoryImgData::SetJsonData_Still(Json json)
	{
		int i;
		for (i = 0; i < 2; i++)
		{
			stillData.day_0[i] = json["day_0"][i];
			stillData.day_4[i] = json["day_4"][i];
		}

		for (i = 0; i < 3; i++)
		{
			stillData.day_1[i] = json["day_1"][i];
		}

		for (i = 0; i < 6; i++)
		{
			stillData.day_2[i] = json["day_2"][i];
		}

		for (i = 0; i < 8; i++)
		{
			stillData.day_3[i] = json["day_3"][i];
		}
	}
}