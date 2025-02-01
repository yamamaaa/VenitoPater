#include "Result_SoundData.h"

namespace json_sounddata
{
    Result_SoundData::Result_SoundData(Json json)
    {
        JsonSet(json["back"], back);
        JsonSet(json["bgm"], bgm);
        JsonSet(json["button"], button);
    }

    Result_SoundData::~Result_SoundData()
    {
       //èàóùÇ»Çµ
    }

    void Result_SoundData::JsonSet(Json json, SoundData& data)
    {
        data.name = json["name"];
        data.volume = json["volume"];
        data.type = json["type"];
        data.path = json["path"];
    }
}