#pragma once
#include<string>
#include"../json.hpp"

using Json = nlohmann::json;

namespace json_sounddata
{
	/// <summary>
	/// Clear��JsonSound�f�[�^�Ǘ��N���X
	/// </summary>
	class Clear_SoundData
	{
	public:

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		/// <param name="json">Json�t�@�C��</param>
		Clear_SoundData(Json json);

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~Clear_SoundData();

		const std::string GetApplauseNameData()const { return applause.name; }
		const int GetApplauseVolumeData()const { return applause.volume; }
		const bool GetApplauseTypeData()const { return applause.type; }
		const std::string GetApplausePathData()const { return applause.path; }

		const std::string GetBgmNameData()const { return  bgm.name; }
		const int GetBgmVolumeData()const { return  bgm.volume; }
		const bool GetBgmTypeData()const { return  bgm.type; }
		const std::string GetBgmPathData()const { return  bgm.path; }

	private:

		struct SoundData
		{
			std::string name;
			int volume;
			bool type;
			std::string path;
		};

		void JsonSet(Json json, SoundData& data);

		SoundData applause;
		SoundData bgm;
	};
}

