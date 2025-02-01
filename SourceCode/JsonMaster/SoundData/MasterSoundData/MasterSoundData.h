#pragma once
#include <memory>

#include "../Tutorial_SoundData/Tutorial_SoundData.h"
#include "../Title_SoundData/Title_SoundData.h"
#include "../Result_SoundData/Result_SoundData.h"
#include "../Clear_SoundData/Clear_SoundData.h"
#include "../Story_SoundData/Story_SoundData.h"
#include "../Score_SoundData/Score_SoundData.h"
#include "../Play_SoundData/Play_SoundData.h"

namespace jsonmaster
{
	/// <summary>
	/// ファイル解析関連
	/// </summary>
	class IOUtility;
}

namespace json_sounddata
{
	/// <summary>
	/// SoundJsonデータ管理クラス
	/// </summary>
	class MasterSoundData final
	{
	public:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		MasterSoundData();

		/// <summary>
		/// デストラクタ
		/// </summary>
		~MasterSoundData();

		/// <summary>
		/// Tutorial_SoundDataインスタンス
		/// </summary>
		/// <returns>Tutorialデータ</returns>
		class Tutorial_SoundData* Get_Tutorial_SoundData_Instance() { return tutorial_sounddata.get(); }

		/// <summary>
		/// Title_SoundDataインスタンス
		/// </summary>
		/// <returns>Titleデータ</returns>
		class Title_SoundData* Get_Title_SoundData_Instance() { return title_sounddata.get(); }

		/// <summary>
		/// Result_SoundDataインスタンス
		/// </summary>
		/// <returns>Resultデータ</returns>
		class Result_SoundData* Get_Result_SoundData_Instance() { return result_sounddata.get(); }

		/// <summary>
		/// Clear_SoundDataインスタンス
		/// </summary>
		/// <returns>Clearデータ</returns>
		class Clear_SoundData* Get_Clear_SoundData_Instance() { return clear_sounddata.get(); }

		/// <summary>
		/// Story_SoundDataインスタンス
		/// </summary>
		/// <returns>Storyデータ</returns>
		class Story_SoundData* Get_Story_SoundData_Instance() { return story_sounddata.get(); }

		/// <summary>
		/// Score_SoundDataインスタンス
		/// </summary>
		/// <returns>Scoreデータ</returns>
		class Score_SoundData* Get_Score_SoundData_Instance() { return score_sounddata.get(); }

		/// <summary>
		/// Play_SoundDataインスタンス
		/// </summary>
		/// <returns>Playデータ</returns>
		class Play_SoundData* Get_Play_SoundData_Instance() { return play_sounddata.get(); }

	private:

		jsonmaster::IOUtility* ioutility;							//IOUtilityインスタンス

		std::unique_ptr<class Tutorial_SoundData> tutorial_sounddata;
		std::unique_ptr<class Title_SoundData> title_sounddata;
		std::unique_ptr<class Result_SoundData> result_sounddata;
		std::unique_ptr<class Clear_SoundData> clear_sounddata;
		std::unique_ptr<class Story_SoundData> story_sounddata;
		std::unique_ptr<class  Score_SoundData> score_sounddata;
		std::unique_ptr<class  Play_SoundData> play_sounddata;
	};
}

