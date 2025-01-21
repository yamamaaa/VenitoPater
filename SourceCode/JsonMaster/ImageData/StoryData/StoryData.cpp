#include "StoryData.h"

namespace json_imgdata
{
	StoryData::StoryData(Json json)
	{
		flame = json["global"];

		backgroundData.lounge = json["character"]["background"]["lounge"];
		backgroundData.stage = json["character"]["background"]["stage"];

		SetJsonData_Familia(json["character"]["familia"]);

		itemdata.backfade = json["character"]["item"];
		itemdata.duck = json["character"]["duck"];
		itemdata.guard_set = json["character"]["guard_set"];
		itemdata.medicine = json["character"]["medicine"];

		SetJsonData_Still(json["still"]);
	}

	StoryData::~StoryData()
	{
		//èàóùÇ»Çµ
	}

	void StoryData::SetJsonData_Familia(Json json)
	{
		for (int i = 0; i < 9; i++)
		{
			familiaData.name[i] = json["name"];
			familiaData.image[i] = json["image"];
		}
	}

	void StoryData::SetJsonData_Still(Json json)
	{
		int i;
		for (i = 0; i < 2; i++)
		{
			stillData.day_0[i] = json["day_0"];
			stillData.day_4[i] = json["day_4"];
		}

		for (i = 0; i < 3; i++)
		{
			stillData.day_1[i] = json["day_1"];
		}

		for (i = 0; i < 6; i++)
		{
			stillData.day_2[i] = json["day_2"];
		}

		for (i = 0; i < 8; i++)
		{
			stillData.day_3[i] = json["day_3"];
		}
	}
}