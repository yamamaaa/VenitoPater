#include "Clear_SoundData.h"

namespace json_sounddata
{
    Clear_SoundData::Clear_SoundData(Json json)
    {
        JsonSet(json["applause"], applause);
        JsonSet(json["bgm"], bgm);
    }

    Clear_SoundData::~Clear_SoundData()
    {
        //ˆ—‚È‚µ
    }

    void Clear_SoundData::JsonSet(Json json,SoundData& data)
    {
        data.name = json["name"];
        data.volume = json["volume"];
        data.type = json["type"];
        data.path = json["path"];
    }
}