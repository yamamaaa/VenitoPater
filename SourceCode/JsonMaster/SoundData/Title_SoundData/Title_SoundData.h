#pragma once
#pragma once
#include<string>
#include"../json.hpp"

using Json = nlohmann::json;

namespace json_sounddata
{
	/// <summary>
	/// TitleのJsonSoundデータ管理クラス
	/// </summary>
	class  Title_SoundData
	{
	public:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="json">Jsonファイル</param>
		Title_SoundData(Json json);

		/// <summary>
		/// デストラクタ
		/// </summary>
		~Title_SoundData();

		const std::string GetBgmNameData()const { return  bgm.name; }
		const int GetBgmVolumeData()const { return  bgm.volume; }
		const bool GetBgmTypeData()const { return  bgm.type; }
		const std::string GetBgmPathData()const { return  bgm.path; }

		const std::string GetButton_NameData()const { return button.name; }
		const int GetButton_VolumeData()const { return button.volume; }
		const bool GetButton_TypeData()const { return button.type; }
		const std::string GetButton_PathData()const { return button.path; }

		const std::string GetSelect_NameData()const { return select.name; }
		const int GetSelect_VolumeData()const { return select.volume; }
		const bool GetSelect_TypeData()const { return select.type; }
		const std::string GetSelect_PathData()const { return select.path; }

		const std::string GetTransition_NameData()const { return transition.name; }
		const int GetTransition_VolumeData()const { return transition.volume; }
		const bool GetTransition_TypeData()const { return transition.type; }
		const std::string GetTransition_PathData()const { return transition.path; }

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
		SoundData select;
		SoundData transition;
	};
}
