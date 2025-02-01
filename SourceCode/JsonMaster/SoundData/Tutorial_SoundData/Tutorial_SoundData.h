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
		const int GetBgmVolumeData()const { return  bgm.volume; }
		const bool GetBgmTypeData()const { return  bgm.type; }
		const std::string GetBgmPathData()const { return  bgm.path; }

		const std::string GetBack_NameData()const { return back.name; }
		const int GetBack_VolumeData()const { return back.volume; }
		const bool GetBack_TypeData()const { return back.type; }
		const std::string GetBack_PathData()const { return back.path; }

		const std::string GetButton_NameData()const { return button.name; }
		const int GetButton_VolumeData()const { return button.volume; }
		const bool GetButton_TypeData()const { return button.type; }
		const std::string GetButton_PathData()const { return button.path; }

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

