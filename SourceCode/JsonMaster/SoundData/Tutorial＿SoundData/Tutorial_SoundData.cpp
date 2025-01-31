#include "Tutorial_SoundData.h"

namespace json_sounddata
{
    Tutorial_SoundData::Tutorial_SoundData(Json json)
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

    Tutorial_SoundData::~Tutorial_SoundData()
    {
        //ˆ—‚È‚µ
    }
}