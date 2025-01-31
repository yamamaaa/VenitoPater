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
		const std::string GetBgmPathData()const { return  bgm.path; }

		const std::string GetClockwork_NameData()const { return clockwork.name; }
		const std::string GetClockwork_PathData()const { return clockwork.path; }

		const std::string GetDuck_0_NameData()const { return duck_0.name; }
		const std::string GetDuck_0_PathData()const { return duck_0.path; }

		const std::string GetDuck_1_NameData()const { return duck_1.name; }
		const std::string GetDuck_1_PathData()const { return duck_1.path; }

		const std::string GetDuck_2_NameData()const { return duck_2.name; }
		const std::string GetDuck_2_PathData()const { return duck_2.path; }

		const std::string GetEmyAction_NameData()const { return emyaction.name; }
		const std::string GetEmyAction_PathData()const { return emyaction.path; }

		const std::string GeyEnemyt_NameData()const { return enemy.name; }
		const std::string GetEnemy_PathData()const { return enemy.path; }

		const std::string GetHat_NameData()const { return hat.name; }
		const std::string GetHat_PathData()const { return hat.path; }

		const std::string GetIra_NameData()const { return ira.name; }
		const std::string GetIra_PathData()const { return ira.path; }

		const std::string GetLight_NameData()const { return light.name; }
		const std::string GetLight_PathData()const { return light.path; }

		const std::string GetMusicbox_NameData()const { return musicbox.name; }
		const std::string GetMusicbox_PathData()const { return musicbox.path; }

	private:

		struct SoundData
		{
			std::string name;
			std::string path;
		};

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

