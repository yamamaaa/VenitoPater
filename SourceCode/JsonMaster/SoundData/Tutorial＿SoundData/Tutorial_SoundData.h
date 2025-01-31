#pragma once
#include<string>
#include"../json.hpp"

using Json = nlohmann::json;

namespace json_sounddata
{
	/// <summary>
	/// Tutorial��JsonSound�f�[�^�Ǘ��N���X
	/// </summary>
	class  Tutorial_SoundData
	{
	public:

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		/// <param name="json">Json�t�@�C��</param>
		Tutorial_SoundData(Json json);

		/// <summary>
		/// �f�X�g���N�^
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

