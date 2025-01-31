#pragma once
#include<string>
#include"../json.hpp"

using Json = nlohmann::json;

namespace json_sounddata
{
	/// <summary>
	/// TutorialのJsonSoundデータ管理クラス
	/// </summary>
	class  Tutorial_SoundData
	{
	public:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="json">Jsonファイル</param>
		Tutorial_SoundData(Json json);

		/// <summary>
		/// デストラクタ
		/// </summary>
		~Tutorial_SoundData();

		const std::string GetBgmNameData()const { return  bgm.name; }
		const std::string GetBgmPathData()const { return  bgm.path; }

		const std::string GetBack_NameData()const { return back.name; }
		const std::string GetBack_PathData()const { return back.path; }

		const std::string GetButton_NameData()const { return button.name; }
		const std::string GetButton_PathData()const { return button.path; }

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

