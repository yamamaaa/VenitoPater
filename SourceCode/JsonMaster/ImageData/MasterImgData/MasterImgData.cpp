#include "MasterImgData.h"

#include "../../IOUtility/IOUtility.h"

namespace json_imgdata
{
	MasterImgData::MasterImgData()
		:ioutility(new jsonmaster::IOUtility)
	{
		//ファイルを読み込みインスタンス生成
		Json titlejson = ioutility->Analysis("../Asset/jsonFile/image/title.json");
		titledata.reset(new TitleData(titlejson["title"]));

		Json playjson = ioutility->Analysis("../Asset/jsonFile/image/play.json");
		playdata.reset(new PlayData(playjson["play"]));

		Json storyimgjson = ioutility->Analysis("../Asset/jsonFile/image/story.json");
		storyimgdata.reset(new StoryImgData(storyimgjson["story"]));

		Json resultjson = ioutility->Analysis("../Asset/jsonFile/image/result.json");
		resultdata.reset(new ResultData(resultjson["result"]));
	}

	MasterImgData::~MasterImgData()
	{
		//メモリ解放
		delete ioutility;
	}
}