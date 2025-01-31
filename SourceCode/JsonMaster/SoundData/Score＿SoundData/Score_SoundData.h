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
		const std::string GetBgmPathData()const { return  bgm.path; }

		const std::string GetButtonNameData()const { return button.name; }
		const std::string GetButtonPathData()const { return button.path; }

		const std::string GetFanfare_NameData()const { return fanfare.name; }
		const std::string GetFanfare_PathData()const { return fanfare.path; }

		const std::string GetItem_NameData()const { return item.name; }
		const std::string GetItem_PathData()const { return item.path; }

		const std::string GetRoll_NameData()const { return roll.name; }
		const std::string GetRoll_PathData()const { return roll.path; }

		const std::string GetScore_NameData()const { return score.name; }
		const std::string GetScore_PathData()const { return score.path; }

	private:

		struct SoundData
		{
			std::string name;
			std::string path;
		};

		SoundData bgm;
		SoundData button;
		SoundData fanfare;
		SoundData item;
		SoundData roll;
		SoundData score;
	};
}

