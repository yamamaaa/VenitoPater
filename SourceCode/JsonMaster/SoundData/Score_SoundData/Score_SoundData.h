#pragma once
#include<string>
#include"../json.hpp"

using Json = nlohmann::json;

namespace json_sounddata
{
	/// <summary>
	/// ScoreのJsonSoundデータ管理クラス
	/// </summary>
	class Score_SoundData
	{
	public:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="json">Jsonファイル</param>
		Score_SoundData(Json json);

		/// <summary>
		/// デストラクタ
		/// </summary>
		~Score_SoundData();

		const std::string GetBgmNameData()const { return  bgm.name; }
		const int GetBgmVolumeData()const { return  bgm.volume; }
		const bool GetBgmTypeData()const { return  bgm.type; }
		const std::string GetBgmPathData()const { return  bgm.path; }

		const std::string GetButtonNameData()const { return button.name; }
		const int GetButtonVolumeData()const { return button.volume; }
		const bool GetButtonTypeData()const { return button.type; }
		const std::string GetButtonPathData()const { return button.path; }

		const std::string GetFanfare_NameData()const { return fanfare.name; }
		const int GetFanfare_VolumeData()const { return fanfare.volume; }
		const bool GetFanfare_TypeData()const { return fanfare.type; }
		const std::string GetFanfare_PathData()const { return fanfare.path; }

		const std::string GetItem_NameData()const { return item.name; }
		const int GetItem_VolumeData()const { return item.volume; }
		const bool GetItem_TypeData()const { return item.type; }
		const std::string GetItem_PathData()const { return item.path; }

		const std::string GetRoll_NameData()const { return roll.name; }
		const int GetRoll_VolumeData()const { return roll.volume; }
		const bool GetRoll_TypeData()const { return roll.type; }
		const std::string GetRoll_PathData()const { return roll.path; }

		const std::string GetScore_NameData()const { return score.name; }
		const int GetScore_VolumeData()const { return score.volume; }
		const bool GetScore_TypeData()const { return score.type; }
		const std::string GetScore_PathData()const { return score.path; }

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
		SoundData button;
		SoundData fanfare;
		SoundData item;
		SoundData roll;
		SoundData score;
	};
}

