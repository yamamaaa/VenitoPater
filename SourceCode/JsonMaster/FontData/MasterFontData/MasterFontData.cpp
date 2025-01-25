#include "MasterFontData.h"

#include "../../IOUtility/IOUtility.h"

namespace json_fontdata
{
	MasterFontData::MasterFontData()
		:ioutility(new jsonmaster::IOUtility)
	{
		//ファイルを読み込みインスタンス生成
		Json storyjson = ioutility->Analysis("../SourceCode/JsonMaster/JsonFile/Font/story.json");
		storydata.reset(new StoryData(storyjson["story"]));
		//../SourceCode/JsonMaster/JsonFile/Font/story.json
	}

	MasterFontData::~MasterFontData()
	{
		//メモリ解放
		delete ioutility;
	}
}