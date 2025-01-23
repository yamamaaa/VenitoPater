#pragma once
#include<memory>
#include"../StoryData/StoryData.h"

namespace jsonmaster
{
	/// <summary>
	/// ファイル解析関連
	/// </summary>
	class IOUtility;
}

namespace json_fontdata
{
	/// <summary>
	/// MasterFontデータ管理クラス
	/// </summary>
	class MasterFontData
	{
	public:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		MasterFontData();

		/// <summary>
		/// デストラクタ
		/// </summary>
		~MasterFontData();

		/// <summary>
		/// StoryDatインスタンス
		/// </summary>
		/// <returns>Storyデータ</returns>
		class StoryData* Get_StoryDat_Instance() { return storydata.get(); }

	private:

		jsonmaster::IOUtility* ioutility;							//IOUtilityインスタンス

		std::unique_ptr<class StoryData> storydata;
	};
}