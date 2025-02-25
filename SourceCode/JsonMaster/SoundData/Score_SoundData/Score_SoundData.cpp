#include "Score_SoundData.h"

namespace json_sounddata
{
    Score_SoundData::Score_SoundData(Json json)
    {
        JsonSet(json["bgm"], bgm);
        JsonSet(json["button"], button);
        JsonSet(json["fanfare"], fanfare);
        JsonSet(json["item"], item);
        JsonSet(json["roll"], roll);
        JsonSet(json["score"], score);
    }

    Score_SoundData::~Score_SoundData()
    {
        //èàóùÇ»Çµ
    }

    void Score_SoundData::JsonSet(Json json, SoundData& data)
    {
        data.name = json["name"];
        data.volume = json["volume"];
        data.type = json["type"];
        data.path = json["path"];
    }
}