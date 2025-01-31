#include "Score_SoundData.h"

namespace json_sounddata
{
    Score_SoundData::Score_SoundData(Json json)
    {
        Json def = json["bgm"];
        bgm.name = def["name"];
        bgm.path = def["path"];

        def = json["button"];
        button.name = def["name"];
        button.path = def["path"];

        def = json["fanfare"];
        fanfare.name = def["name"];
        fanfare.path = def["path"];

        def = json["item"];
        item.name = def["name"];
        item.path = def["path"];

        def = json["roll"];
        roll.name = def["name"];
        roll.path = def["path"];

        def = json["score"];
        score.name = def["name"];
        score.path = def["path"];
    }

    Score_SoundData::~Score_SoundData()
    {
        //èàóùÇ»Çµ
    }
}