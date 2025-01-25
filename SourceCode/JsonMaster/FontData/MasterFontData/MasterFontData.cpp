#include "MasterFontData.h"

#include "../../IOUtility/IOUtility.h"

namespace json_fontdata
{
	MasterFontData::MasterFontData()
		:ioutility(new jsonmaster::IOUtility)
	{
		//�t�@�C����ǂݍ��݃C���X�^���X����
		Json storyjson = ioutility->Analysis("../SourceCode/JsonMaster/JsonFile/Font/story.json");
		storydata.reset(new StoryData(storyjson["story"]));
		//../SourceCode/JsonMaster/JsonFile/Font/story.json
	}

	MasterFontData::~MasterFontData()
	{
		//���������
		delete ioutility;
	}
}