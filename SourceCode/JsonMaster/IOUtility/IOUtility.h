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
		/// コンストラクタ
		/// </summary>
		IOUtility();

		/// <summary>
		/// デストラクタ
		/// </summary>
		~IOUtility();

		/// <summary>
		/// jsonファイルのデータ解析
		/// </summary>
		/// <param name="fileName">ファイル名</param>
		/// <returns>解析済みのファイルデータ</returns>
		Json Analysis(std::string fileName);
	};
}

