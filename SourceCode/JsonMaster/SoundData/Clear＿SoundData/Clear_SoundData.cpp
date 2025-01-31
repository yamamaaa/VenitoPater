#include "Clear_SoundData.h"

namespace json_sounddata
{
    Clear_SoundData::Clear_SoundData(Json json)
    {
        Json def = json["applause"];
        applause.name = def["name"];
        applause.path = def["path"];

        def = json["bgm"];
        bgm.name = def["name"];
        bgm.path = def["path"];
    }

    Clear_SoundData::~Clear_SoundData()
    {
        //ˆ—‚È‚µ
    }
}