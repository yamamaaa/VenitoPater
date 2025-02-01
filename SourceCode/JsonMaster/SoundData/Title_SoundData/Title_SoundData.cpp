#include "Title_SoundData.h"

namespace json_sounddata
{
    Title_SoundData::Title_SoundData(Json json)
    {
        JsonSet(json["bgm"], bgm);
        JsonSet(json["button"], button);
        JsonSet(json["select"], select);
        JsonSet(json["transition"], transition);
    }

    Title_SoundData::~Title_SoundData()
    {
        //èàóùÇ»Çµ
    }

    void Title_SoundData::JsonSet(Json json, SoundData& data)
    {
        data.name = json["name"];
        data.volume = json["volume"];
        data.type = json["type"];
        data.path = json["path"];
    }
}