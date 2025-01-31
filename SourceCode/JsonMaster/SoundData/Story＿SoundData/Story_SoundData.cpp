#include "Story_SoundData.h"

namespace json_sounddata
{
    Story_SoundData::Story_SoundData(Json json)
    {
        Json def = json["button"];
        button.name = def["name"];
        button.path = def["path"];

        def = json["still_day_0_bgm"];
        still_day_0_bgm.name = def["name"];
        still_day_0_bgm.path = def["path"];

        def = json["still_day_1_bgm"];
        still_day_1_bgm.name = def["name"];
        still_day_1_bgm.path = def["path"];

        def = json["still_day_2_bgm"];
        still_day_2_bgm.name = def["name"];
        still_day_2_bgm.path = def["path"];

        def = json["still_day_3_bgm"];
        still_day_3_bgm.name = def["name"];
        still_day_3_bgm.path = def["path"];

        def = json["still_day_4_bgm"];
        still_day_4_bgm.name = def["name"];
        still_day_4_bgm.path = def["path"];

        def = json["story_bgm"];
        story_bgm.name = def["name"];
        story_bgm.path = def["path"];
    }

    Story_SoundData::~Story_SoundData()
    {
        //ˆ—‚È‚µ
    }
}