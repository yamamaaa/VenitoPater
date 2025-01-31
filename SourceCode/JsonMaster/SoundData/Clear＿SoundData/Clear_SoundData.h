#pragma once
#include<string>
#include"../json.hpp"

using Json = nlohmann::json;

namespace json_sounddata
{
	/// <summary>
	/// ClearのJsonSoundデータ管理クラス
	/// </summary>
	class Clear_SoundData
	{
	public:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="json">Jsonファイル</param>
		Clear_SoundData(Json json);

		/// <summary>
		/// デストラクタ
		/// </summary>
		~Clear_SoundData();

		const std::string GetApplauseNameData()const { return applause.name; }
		const std::string GetApplausePathData()const { return applause.path; }

		const std::string GetBgmNameData()const { return  bgm.name; }
		const std::string GetBgmPathData()const { return  bgm.path; }

	private:

		struct SoundData
		{
			std::string name;
			std::string path;
		};

		SoundData applause;
		SoundData bgm;
	};
}

