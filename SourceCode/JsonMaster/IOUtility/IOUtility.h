#pragma once

#include<iostream>
#include<future>
#include<fstream>
#include "../json.hpp"

using Json = nlohmann::json;

namespace jsonmaster
{
	class IOUtility final
	{
	public:

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		IOUtility();

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~IOUtility();

		/// <summary>
		/// json�t�@�C���̃f�[�^���
		/// </summary>
		/// <param name="fileName">�t�@�C����</param>
		/// <returns>��͍ς݂̃t�@�C���f�[�^</returns>
		Json Analysis(std::string fileName);
	};
}

