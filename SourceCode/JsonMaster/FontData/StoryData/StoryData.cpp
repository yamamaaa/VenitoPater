#include "StoryData.h"

namespace json_fontdata
{
	StoryData::StoryData(Json json)
	{
		font = json["font"];
		fonttag = json["fonttag"];
	}

	StoryData::~StoryData()
	{
		//ˆ—‚È‚µ
	}
}