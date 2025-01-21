#pragma once
#include<memory>
#include "../CharacterData/CharacterData.h"
#include "../StillData/StillData.h"

namespace jsonmaster
{
	/// <summary>
	/// �t�@�C����͊֘A
	/// </summary>
	class IOUtility;
}

namespace json_textdata
{
	/// <summary>
	/// MasterText�f�[�^�Ǘ��N���X
	/// </summary>
	class MasterTextData
	{
	public:

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		MasterTextData();

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~MasterTextData();

		/// <summary>
		/// CharacterData�C���X�^���X
		/// </summary>
		/// <returns>Character�f�[�^</returns>
		class CharacterData* Get_CharacterData_Instance() { return characterdata.get(); }

		/// <summary>
		/// StillData�C���X�^���X
		/// </summary>
		/// <returns>Still�f�[�^</returns>
		class StillData* Get_StillData_Instance() { return stilldata.get(); }

	private:

		jsonmaster::IOUtility* ioutility;							//IOUtility�C���X�^���X

		std::unique_ptr<class CharacterData> characterdata;
		std::unique_ptr<class StillData> stilldata;
	};
}