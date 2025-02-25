#include "Tutorial_SoundData.h"

namespace json_sounddata
{
    Tutorial_SoundData::Tutorial_SoundData(Json json)
    {
        JsonSet(json["back"], back);
        JsonSet(json["bgm"], bgm);
        JsonSet(json["button"], button);
    }

    Tutorial_SoundData::~Tutorial_SoundData()
    {
        //èàóùÇ»Çµ
    }

    void Tutorial_SoundData::JsonSet(Json json, SoundData& data)
    {
        data.name = json["name"];
        data.volume = json["volume"];
        data.type = json["type"];
        data.path = json["path"];
    }
}