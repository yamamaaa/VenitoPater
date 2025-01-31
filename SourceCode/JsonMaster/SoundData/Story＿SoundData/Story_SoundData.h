#pragma once
#include<string>
#include"../json.hpp"

using Json = nlohmann::json;

namespace json_sounddata
{
	/// <summary>
	/// StoryのJsonSoundデータ管理クラス
	/// </summary>
	class Story_SoundData
	{
	public:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="json">Jsonファイル</param>
		Story_SoundData(Json json);

		/// <summary>
		/// デストラクタ
		/// </summary>
		~Story_SoundData();

		const std::string GetButtonNameData()const { return button.path; }
		const std::string GetButtonPathData()const { return button.path; }

		const std::string GetStill_Day_0_NameData()const { return still_day_0_bgm.name; }
		const std::string GetStill_Day_0_PathData()const { return still_day_0_bgm.path; }

		const std::string GetStill_Day_1_NameData()const { return still_day_1_bgm.name; }
		const std::string GetStill_Day_1_PathData()const { return still_day_1_bgm.path; }

		const std::string GetStill_Day_2_NameData()const { return still_day_2_bgm.name; }
		const std::string GetStill_Day_2_PathData()const { return still_day_2_bgm.path; }

		const std::string GetStill_Day_3_NameData()const { return still_day_3_bgm.name; }
		const std::string GetStill_Day_3_PathData()const { return still_day_3_bgm.path; }

		const std::string GetStill_Day_4_NameData()const { return still_day_4_bgm.name; }
		const std::string GetStill_Day_4_PathData()const { return still_day_4_bgm.path; }

		const std::string GetStory_NameData()const { return story_bgm.name; }
		const std::string GetStory_PathData()const { return story_bgm.path; }

	private:

		struct SoundData
		{
			std::string name;
			std::string path;
		};

		SoundData button;

		SoundData still_day_0_bgm;
		SoundData still_day_1_bgm;
		SoundData still_day_2_bgm;
		SoundData still_day_3_bgm;
		SoundData still_day_4_bgm;

		SoundData story_bgm;
	};
}

