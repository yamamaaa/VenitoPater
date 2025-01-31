#include "Result_SoundData.h"

namespace json_sounddata
{
    Result_SoundData::Result_SoundData(Json json)
    {
        Json def = json["back"];
        back.name = def["name"];
        back.path = def["path"];

        def = json["bgm"];
        bgm.name = def["name"];
        bgm.path = def["path"];

        def = json["button"];
        button.name = def["name"];
        button.path = def["path"];
    }

    Result_SoundData::~Result_SoundData()
    {
       //ˆ—‚È‚µ
    }
}