#include "Play_SoundData.h"

namespace json_sounddata
{
    Play_SoundData::Play_SoundData(Json json)
    {
        Json def = json["bgm"];
        bgm.name = def["name"];
        bgm.path = def["path"];

        def = json["clockwork"];
        clockwork.name = def["name"];
        clockwork.path = def["path"];

        def = json["duck_0"];
        duck_0.name = def["name"];
        duck_0.path = def["path"];
        def = json["duck_1"];
        duck_1.name = def["name"];
        duck_1.path = def["path"];
        def = json["duck_2"];
        duck_2.name = def["name"];
        duck_2.path = def["path"];

        def = json["emyaction"];
        emyaction.name = def["name"];
        emyaction.path = def["path"];
        def = json["enemy"];
        enemy.name = def["name"];
        enemy.path = def["path"];

        def = json["hat"];
        hat.name = def["name"];
        hat.path = def["path"];

        def = json["ira"];
        ira.name = def["name"];
        ira.path = def["path"];

        def = json["light"];
        light.name = def["name"];
        light.path = def["path"];

        def = json["musicbox"];
        musicbox.name = def["name"];
        musicbox.path = def["path"];
    }

    Play_SoundData::~Play_SoundData()
    {
        //èàóùÇ»Çµ
    }
}