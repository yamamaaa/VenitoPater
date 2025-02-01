#include "MasterSoundData.h"

#include "../../IOUtility/IOUtility.h"

namespace json_sounddata
{
	MasterSoundData::MasterSoundData()
		:ioutility(new jsonmaster::IOUtility)
	{
		//ファイルを読み込みインスタンス生成
		Json tutorialjson = ioutility->Analysis("../Asset/jsonfile/sound/tutorial.json");
		tutorial_sounddata.reset(new Tutorial_SoundData(tutorialjson["tutorial"]));

		Json titlejson = ioutility->Analysis("../Asset/jsonfile/sound/title.json");
		title_sounddata.reset(new Title_SoundData(titlejson["title"]));

		Json resultjson = ioutility->Analysis("../Asset/jsonfile/sound/result.json");
		result_sounddata.reset(new Result_SoundData(resultjson["result"]));

		Json clearjson = ioutility->Analysis("../Asset/jsonfile/sound/clear.json");
		clear_sounddata.reset(new Clear_SoundData(clearjson["clear"]));

		Json storyjson = ioutility->Analysis("../Asset/jsonfile/sound/story.json");
		story_sounddata.reset(new Story_SoundData(storyjson["story"]));

		Json scorejson = ioutility->Analysis("../Asset/jsonfile/sound/score.json");
		score_sounddata.reset(new Score_SoundData(scorejson["score"]));

		Json playjson = ioutility->Analysis("../Asset/jsonfile/sound/play.json");
		play_sounddata.reset(new Play_SoundData(playjson["play"]));
	}

	MasterSoundData::~MasterSoundData()
	{
		//メモリ解放
		delete ioutility;
	}
}