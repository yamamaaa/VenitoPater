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
		const std::string GetBgmPathData()const { return  bgm.path; }

		const std::string GetButton_NameData()const { return button.name; }
		const std::string GetButton_PathData()const { return button.path; }

		const std::string GetSelect_NameData()const { return select.name; }
		const std::string GetSelect_PathData()const { return select.path; }

		const std::string GetTransiton_NameData()const { return transiton.name; }
		const std::string GetTransiton_PathData()const { return transiton.path; }

	private:

		struct SoundData
		{
			std::string name;
			std::string path;
		};

		SoundData bgm;
		SoundData button;
		SoundData select;
		SoundData transiton;
	};
}
