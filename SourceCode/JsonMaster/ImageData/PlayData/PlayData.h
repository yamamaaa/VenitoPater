#pragma once
#include<string>
#include"../json.hpp"

using Json = nlohmann::json;

namespace json_imgdata
{
	/// <summary>
	/// Play中のJsonImgデータ管理クラス
	/// </summary>
	class PlayData
	{
	public:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="json">Jsonファイル</param>
		PlayData(Json json);

		/// <summary>
		/// デストラクタ
		/// </summary>
		~PlayData();

		const std::string GetFamiliaData(int index)const { return enemyData.familia[index]; }
		const std::string GetIraData(int index)const { return enemyData.ira[index]; }
		const std::string GetMeminiData(int index)const { return enemyData.memini[index]; }
		const std::string GetNilData(int index)const { return enemyData.nil[index]; }
		const std::string GetSperoData(int index)const { return enemyData.spero[index]; }

		const std::string Get_ItemData_Area_0(int index)const { return itemData.area_0[index]; }
		const std::string Get_ItemData_Area_1(int index)const { return itemData.area_1[index]; }
		const std::string Get_ItemData_Area_2(int index)const { return itemData.area_2[index]; }

		const std::string GetLightData_Black()const { return lightData.black; }
		const std::string GetLightData_Light()const { return lightData.light; }
		const std::string GetLightData_Shadow()const { return lightData.shadow; }

		const std::string GetStageData(int index)const { return stage[index]; }

		const std::string GetClockWork()const { return clockwork; }

		const std::string GetUiData_Aboido()const { return uiData.aboido; }
		const std::string GetUiData_Duck()const { return uiData.duck; }
		const std::string GetUiData_Hat()const { return uiData.hat; }
		const std::string GetUiData_Nekoinu()const { return uiData.nekoinu; }
		const std::string GetUiData_Warning()const { return uiData.warning; }

	private:

		struct EnemyData
		{
			std::string familia[2];
			std::string ira[2];
			std::string memini[3];
			std::string nil[3];
			std::string spero[3];
		}enemyData;

		void SetJsonData_Enemy(Json json);

		struct ItemData
		{
			std::string area_0[6];
			std::string area_1[6];
			std::string area_2[6];
		}itemData;

		void SetJsonData_Item(Json json);

		struct LightData
		{
			std::string black;
			std::string light;
			std::string shadow;
		}lightData;

		std::string stage[4];
		void SetJsonData_Stage(Json json);

		std::string clockwork;

		struct UiData
		{
			std::string aboido;
			std::string duck;
			std::string hat;
			std::string nekoinu;
			std::string warning;
		}uiData;
	};
}