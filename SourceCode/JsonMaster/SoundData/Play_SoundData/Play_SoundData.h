#pragma once
#pragma once
#include<string>
#include"../json.hpp"

using Json = nlohmann::json;

namespace json_sounddata
{
	/// <summary>
	/// PlayのJsonSoundデータ管理クラス
	/// </summary>
	class  Play_SoundData
	{
	public:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="json">Jsonファイル</param>
		Play_SoundData(Json json);

		/// <summary>
		/// デストラクタ
		/// </summary>
		~Play_SoundData();

		const std::string GetBgmNameData()const { return  bgm.name; }
		const int GetBgmVolumeData()const { return  bgm.volume; }
		const bool GetBgmTypeData()const { return  bgm.type; }
		const std::string GetBgmPathData()const { return  bgm.path; }

		const std::string GetClockwork_NameData()const { return clockwork.name; }
		const int GetClockwork_VolumeData()const { return clockwork.volume; }
		const bool GetClockwork_TypeData()const { return clockwork.type; }
		const std::string GetClockwork_PathData()const { return clockwork.path; }

		const std::string GetDuck_0_NameData()const { return duck_0.name; }
		const int GetDuck_0_VolumeData()const { return duck_0.volume; }
		const bool GetDuck_0_TypeData()const { return duck_0.type; }
		const std::string GetDuck_0_PathData()const { return duck_0.path; }

		const std::string GetDuck_1_NameData()const { return duck_1.name; }
		const int GetDuck_1_VolumeData()const { return duck_1.volume; }
		const bool GetDuck_1_TypeData()const { return duck_1.type; }
		const std::string GetDuck_1_PathData()const { return duck_1.path; }

		const std::string GetDuck_2_NameData()const { return duck_2.name; }
		const int GetDuck_2_VolumeData()const { return duck_2.volume; }
		const bool GetDuck_2_TypeData()const { return duck_2.type; }
		const std::string GetDuck_2_PathData()const { return duck_2.path; }

		const std::string GetEmyAction_NameData()const { return emyaction.name; }
		const int GetEmyAction_VolumeData()const { return emyaction.volume; }
		const bool GetEmyAction_TypeData()const { return emyaction.type; }
		const std::string GetEmyAction_PathData()const { return emyaction.path; }

		const std::string GeyEnemy_NameData()const { return enemy.name; }
		const int GeyEnemy_VolumeData()const { return enemy.volume; }
		const bool GeyEnemy_TypeData()const { return enemy.type; }
		const std::string GetEnemy_PathData()const { return enemy.path; }

		const std::string GetHat_NameData()const { return hat.name; }
		const int GetHat_VolumeData()const { return hat.volume; }
		const bool GetHat_TypeData()const { return hat.type; }
		const std::string GetHat_PathData()const { return hat.path; }

		const std::string GetIra_NameData()const { return ira.name; }
		const int GetIra_VolumeData()const { return ira.volume; }
		const bool GetIra_TypeData()const { return ira.type; }
		const std::string GetIra_PathData()const { return ira.path; }

		const std::string GetLight_NameData()const { return light.name; }
		const int GetLight_VolumeData()const { return light.volume; }
		const bool GetLight_TypeData()const { return light.type; }
		const std::string GetLight_PathData()const { return light.path; }

		const std::string GetMusicbox_NameData()const { return musicbox.name; }
		const int GetMusicbox_VolumeData()const { return musicbox.volume; }
		const bool GetMusicbox_TypeData()const { return musicbox.type; }
		const std::string GetMusicbox_PathData()const { return musicbox.path; }
		
	private:

		struct SoundData
		{
			std::string name;
			int volume;
			bool type;
			std::string path;
		};

		void JsonSet(Json json, SoundData& data);

		SoundData bgm;
		SoundData clockwork;
		SoundData duck_0;
		SoundData duck_1;
		SoundData duck_2;
		SoundData emyaction;
		SoundData enemy;
		SoundData hat;
		SoundData ira;
		SoundData light;
		SoundData musicbox;
	};
}

