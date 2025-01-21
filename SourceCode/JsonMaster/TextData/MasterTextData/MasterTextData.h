#pragma once
#include<memory>
#include "../CharacterData/CharacterData.h"
#include "../StillData/StillData.h"

namespace jsonmaster
{
	/// <summary>
	/// ファイル解析関連
	/// </summary>
	class IOUtility;
}

namespace json_textdata
{
	/// <summary>
	/// MasterTextデータ管理クラス
	/// </summary>
	class MasterTextData
	{
	public:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		MasterTextData();

		/// <summary>
		/// デストラクタ
		/// </summary>
		~MasterTextData();

		/// <summary>
		/// CharacterDataインスタンス
		/// </summary>
		/// <returns>Characterデータ</returns>
		class CharacterData* Get_CharacterData_Instance() { return characterdata.get(); }

		/// <summary>
		/// StillDataインスタンス
		/// </summary>
		/// <returns>Stillデータ</returns>
		class StillData* Get_StillData_Instance() { return stilldata.get(); }

	private:

		jsonmaster::IOUtility* ioutility;							//IOUtilityインスタンス

		std::unique_ptr<class CharacterData> characterdata;
		std::unique_ptr<class StillData> stilldata;
	};
}