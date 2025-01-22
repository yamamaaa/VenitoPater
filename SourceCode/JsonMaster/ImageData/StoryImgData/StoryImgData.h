#pragma once
#include<string>
#include"../json.hpp"

using Json = nlohmann::json;

namespace json_imgdata
{
	/// <summary>
	/// Story中のJsonImgデータ管理クラス
	/// </summary>
	class StoryImgData
	{
	public:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="json">Jsonファイル</param>
		StoryImgData(Json json);

		/// <summary>
		/// デストラクタ
		/// </summary>
		~StoryImgData();

		const std::string GetFlameData()const { return flame; }

		const std::string GetBackgroundData_Lounge()const { return backgroundData.lounge; }
		const std::string GetBackgroundData_Stage()const { return backgroundData.stage; }

		const std::string GetFamiliaData_Name(int index)const { return familiaData.name[index]; }
		const std::string GetFamiliaData_Image(int index)const { return familiaData.image[index]; }

		const std::string GetItemData_BackFade()const { return itemdata.backfade; }
		const std::string GetItemData_Duck()const { return itemdata.duck; }
		const std::string GetItemData_Guard_Set()const { return itemdata.guard_set; }
		const std::string GetItemData_Medicine()const { return itemdata.medicine; }

		const std::string GetStillData_Day_0(int index)const { return stillData.day_0[index]; }
		const std::string GetStillData_Day_1(int index)const { return stillData.day_1[index]; }
		const std::string GetStillData_Day_2(int index)const { return stillData.day_2[index]; }
		const std::string GetStillData_Day_3(int index)const { return stillData.day_3[index]; }
		const std::string GetStillData_Day_4(int index)const { return stillData.day_4[index]; }

	private:

		std::string flame;

		struct BackgroundData
		{
			std::string lounge;
			std::string stage;
		}backgroundData;

		struct FamiliaData
		{
			std::string name[9];
			std::string image[9];
		}familiaData;

		void SetJsonData_Familia(Json json);

		struct ItemData
		{
			std::string backfade;
			std::string duck;
			std::string guard_set;
			std::string medicine;
		}itemdata;

		struct StillData
		{
			std::string day_0[2];
			std::string day_1[3];
			std::string day_2[6];
			std::string day_3[8];
			std::string day_4[2];
		}stillData;

		void SetJsonData_Still(Json json);
	};
}