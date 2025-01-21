#pragma once
#include <memory>

#include "../TitleData/TitleData.h"
#include "../PlayData/PlayData.h"
#include "../StoryData/StoryData.h"
#include "../ResultData/ResultData.h"

namespace jsonmaster
{
	/// <summary>
	/// �t�@�C����͊֘A
	/// </summary>
	class IOUtility;
}

namespace json_imgdata
{
	/// <summary>
	/// JsonImage�f�[�^�Ǘ��N���X
	/// </summary>
	class MasterImgData final
	{
	public:

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		MasterImgData();

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~MasterImgData();

		/// <summary>
		/// TitleData�C���X�^���X
		/// </summary>
		/// <returns>title�f�[�^</returns>
		class TitleData* Get_TitleData_Instance() { return titledata.get(); }

		/// <summary>
		/// PlayData�C���X�^���X
		/// </summary>
		/// <returns>Play�f�[�^</returns>
		class PlayData* Get_PlayData_Instance() { return playdata.get(); }

		/// <summary>
		/// StoryData�C���X�^���X
		/// </summary>
		/// <returns>Story�f�[�^</returns>
		class StoryData* Get_StoryData_Instance() { return storydata.get(); }

		/// <summary>
		/// ResultData�C���X�^���X
		/// </summary>
		/// <returns>Result�f�[�^</returns>
		class ResultData* Get_ResultData_Instance() { return resultdata.get(); }

	private:

		jsonmaster::IOUtility* ioutility;							//IOUtility�C���X�^���X

		std::unique_ptr<class TitleData> titledata;
		std::unique_ptr<class PlayData> playdata;
		std::unique_ptr<class StoryData> storydata;
		std::unique_ptr<class ResultData> resultdata;
	};
}

