#include "MasterTextData.h"

#include "../../IOUtility/IOUtility.h"

namespace json_textdata
{
	MasterTextData::MasterTextData()
		:ioutility(new jsonmaster::IOUtility)
	{
		//�t�@�C����ǂݍ��݃C���X�^���X����
		Json characterjson = ioutility->Analysis("../Asset/jsonfile/text/character.json");
		characterdata.reset(new CharacterData(characterjson["character"]));

		Json stilljson = ioutility->Analysis("../Asset/jsonfile/text/still.json");
		stilldata.reset(new StillData(stilljson["still"]));

		Json gameoverjson = ioutility->Analysis("../Asset/jsonfile/text/gameover.json");
		gameoverdata.reset(new GameOverData(gameoverjson["gameover"]));
	}

	MasterTextData::~MasterTextData()
	{
		//���������
		delete ioutility;
	}
}