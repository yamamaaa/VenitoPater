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
		const std::string GetBackPathData()const { return back.path; }

		const std::string GetBgmNameData()const { return  bgm.name; }
		const std::string GetBgmPathData()const { return  bgm.path; }

		const std::string GetButtonNameData()const { return button.name; }
		const std::string GetButtonPathData()const { return button.path; }

	private:

		struct SoundData
		{
			std::string name;
			std::string path;
		};

		SoundData back;
		SoundData bgm;
		SoundData button;
	};
}
