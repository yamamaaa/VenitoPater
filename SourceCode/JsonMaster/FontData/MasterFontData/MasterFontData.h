#pragma once
#include<memory>
#include"../StoryData/StoryData.h"

namespace jsonmaster
{
	/// <summary>
	/// �t�@�C����͊֘A
	/// </summary>
	class IOUtility;
}

namespace json_fontdata
{
	/// <summary>
	/// MasterFont�f�[�^�Ǘ��N���X
	/// </summary>
	class MasterFontData
	{
	public:

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		MasterFontData();

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~MasterFontData();

		/// <summary>
		/// StoryDat�C���X�^���X
		/// </summary>
		/// <returns>Story�f�[�^</returns>
		class StoryData* Get_StoryDat_Instance() { return storydata.get(); }

	private:

		jsonmaster::IOUtility* ioutility;							//IOUtility�C���X�^���X

		std::unique_ptr<class StoryData> storydata;
	};
}