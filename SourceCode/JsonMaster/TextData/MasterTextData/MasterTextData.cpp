#include "MasterTextData.h"

#include "../../IOUtility/IOUtility.h"

namespace json_textdata
{
	MasterTextData::MasterTextData()
		:ioutility(new jsonmaster::IOUtility)
	{
		//ファイルを読み込みインスタンス生成
		Json characterjson = ioutility->Analysis("../Asset/jsonfile/text/character.json");
		characterdata.reset(new CharacterData(characterjson["character"]));

		Json stilljson = ioutility->Analysis("../Asset/jsonfile/text/still.json");
		stilldata.reset(new StillData(stilljson["still"]));

		Json gameoverjson = ioutility->Analysis("../Asset/jsonfile/text/gameover.json");
		gameoverdata.reset(new GameOverData(gameoverjson["gameover"]));
	}

	MasterTextData::~MasterTextData()
	{
		//メモリ解放
		delete ioutility;
	}
}