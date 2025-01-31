#include "Title_SoundData.h"

namespace json_sounddata
{
    Title_SoundData::Title_SoundData(Json json)
    {
        Json def = json["bgm"];
        bgm.name = def["name"];
        bgm.path = def["path"];

        def = json["button"];
        button.name = def["name"];
        button.path = def["path"];

        def = json["select"];
        select.name = def["name"];
        select.path = def["path"];

        def = json["transiton"];
        transiton.name = def["name"];
        transiton.path = def["path"];
    }

    Title_SoundData::~Title_SoundData()
    {
        //ˆ—‚È‚µ
    }
}