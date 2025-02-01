#pragma once
#include<string>
#include"../json.hpp"

using Json = nlohmann::json;

namespace json_sounddata
{
	/// <summary>
	/// ResultのJsonSoundデータ管理クラス
	/// </summary>
	class Result_SoundData
	{
	public:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="json">Jsonファイル</param>
		Result_SoundData(Json json);

		/// <summary>
		/// デストラクタ
		/// </summary>
		~Result_SoundData();

		const std::string GetBackNameData()const { return back.name; }
		const int GetBackVolumeData()const { return back.volume; }
		const bool GetBackTypeData()const { return back.type; }
		const std::string GetBackPathData()const { return back.path; }

		const std::string GetBgmNameData()const { return  bgm.name; }
		const int GetBgmVolumeData()const { return  bgm.volume; }
		const bool GetBgmTypeData()const { return  bgm.type; }
		const std::string GetBgmPathData()const { return  bgm.path; }

		const std::string GetButtonNameData()const { return button.name; }
		const int GetButtonVolumeData()const { return button.volume; }
		const bool GetButtonTypeData()const { return button.type; }
		const std::string GetButtonPathData()const { return button.path; }

	private:

		struct SoundData
		{
			std::string name;
			int volume;
			bool type;
			std::string path;
		};

		void JsonSet(Json json, SoundData& data);

		SoundData back;
		SoundData bgm;
		SoundData button;
	};
}
