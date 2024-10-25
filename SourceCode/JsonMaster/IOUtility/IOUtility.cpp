#include "IOUtility.h"

namespace jsonmaster
{
	IOUtility::IOUtility()
	{
		//処理なし
	}

	IOUtility::~IOUtility()
	{
		//処理なし
	}

	Json IOUtility::Analysis(std::string fileName)
	{
		Json result;

		//ファイル読み込み
		std::ifstream ifs(fileName.c_str());
		//ファイルの解析
		result = Json::parse(ifs);
		//ファイルを閉じる
		ifs.close();

		return result;
	}
}