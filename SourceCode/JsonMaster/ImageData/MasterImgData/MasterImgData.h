#pragma once
#include <memory>

#include "../TitleData/TitleData.h"
#include "../PlayData/PlayData.h"
#include "../StoryImgData/StoryImgData.h"
#include "../ResultData/ResultData.h"

namespace jsonmaster
{
	/// <summary>
	/// ファイル解析関連
	/// </summary>
	class IOUtility;
}

namespace json_imgdata
{
	/// <summary>
	/// JsonImageデータ管理クラス
	/// </summary>
	class MasterImgData final
	{
	public:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		MasterImgData();

		/// <summary>
		/// デストラクタ
		/// </summary>
		~MasterImgData();

		/// <summary>
		/// TitleDataインスタンス
		/// </summary>
		/// <returns>titleデータ</returns>
		class TitleData* Get_TitleData_Instance() { return titledata.get(); }

		/// <summary>
		/// PlayDataインスタンス
		/// </summary>
		/// <returns>Playデータ</returns>
		class PlayData* Get_PlayData_Instance() { return playdata.get(); }

		/// <summary>
		/// StoryDataインスタンス
		/// </summary>
		/// <returns>Storyデータ</returns>
		class StoryImgData* Get_StoryImgData_Instance() { return storyimgdata.get(); }

		/// <summary>
		/// ResultDataインスタンス
		/// </summary>
		/// <returns>Resultデータ</returns>
		class ResultData* Get_ResultData_Instance() { return resultdata.get(); }

	private:

		jsonmaster::IOUtility* ioutility;							//IOUtilityインスタンス

		std::unique_ptr<class TitleData> titledata;
		std::unique_ptr<class PlayData> playdata;
		std::unique_ptr<class StoryImgData> storyimgdata;
		std::unique_ptr<class ResultData> resultdata;
	};
}

