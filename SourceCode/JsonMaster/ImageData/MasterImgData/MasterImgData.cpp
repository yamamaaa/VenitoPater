#include "MasterImgData.h"

#include "../../IOUtility/IOUtility.h"

namespace json_imgdata
{
	MasterImgData::MasterImgData()
		:ioutility(new jsonmaster::IOUtility)
	{
		//�t�@�C����ǂݍ��݃C���X�^���X����
		Json titlejson = ioutility->Analysis("../SourceCode/JsonMaster/JsonFile/Image/title.json");
		titledata.reset(new TitleData(titlejson["title"]));

		Json playjson = ioutility->Analysis("../SourceCode/JsonMaster/JsonFile/Image/play.json");
		playdata.reset(new PlayData(playjson["play"]));

		Json storyimgjson = ioutility->Analysis("../SourceCode/JsonMaster/JsonFile/Image/story.json");
		storyimgdata.reset(new StoryImgData(storyimgjson["story"]));

		Json resultjson = ioutility->Analysis("../SourceCode/JsonMaster/JsonFile/Image/result.json");
		resultdata.reset(new ResultData(resultjson["result"]));
	}

	MasterImgData::~MasterImgData()
	{
		//���������
		delete ioutility;
	}
}