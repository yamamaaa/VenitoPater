#include "PlayData.h"
#include <Iostream>

namespace json_imgdata 
{
	PlayData::PlayData(Json json)
	{
		SetJsonData_Enemy(json["enemy"]);
		SetJsonData_Item(json["item"]);

		lightData.black = json["light"]["black"];
		lightData.light = json["light"]["light"];
		lightData.shadow = json["light"]["shadow"];

		SetJsonData_Stage(json["stage"]);

		clockwork = json["clockwork"];

		uiData.aboido = json["ui"]["aboido"];
		uiData.duck = json["ui"]["duck"];
		uiData.hat = json["ui"]["hat"];
		uiData.nekoinu = json["ui"]["nekoinu"];
		uiData.warning = json["ui"]["warning"];
	}

	PlayData::~PlayData()
	{
		//èàóùÇ»Çµ
	}

	void PlayData::SetJsonData_Enemy(Json json)
	{
		for (int i = 0; i < 2; i++)
		{
			enemyData.familia[i]= json["familia"][i];
			enemyData.ira[i] = json["ira"][i];
		}

		for (int i = 0; i < 3; i++)
		{
			enemyData.memini[i] = json["memini"][i];
			enemyData.nil[i] = json["nil"][i];
			enemyData.spero[i] = json["spero"][i];
		}
	}

	void PlayData::SetJsonData_Item(Json json)
	{
		for (int i = 0; i < 6; i++)
		{
			itemData.area_0[i] = json["area_0"][i];
			itemData.area_1[i] = json["area_1"][i];
			itemData.area_2[i] = json["area_2"][i];
		}
	}

	void PlayData::SetJsonData_Stage(Json json)
	{
		for (int i = 0; i < 4; i++)
		{
			stage[i] = json[i];
		}
	}
}