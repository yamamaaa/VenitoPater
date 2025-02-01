#include "Story_SoundData.h"

namespace json_sounddata
{
    Story_SoundData::Story_SoundData(Json json)
    {
        JsonSet(json["button"], button);
        JsonSet(json["still_day_0_bgm"], still_day_0_bgm);
        JsonSet(json["still_day_1_bgm"], still_day_1_bgm);
        JsonSet(json["still_day_2_bgm"], still_day_2_bgm);
        JsonSet(json["still_day_3_bgm"], still_day_3_bgm);
        JsonSet(json["still_day_4_bgm"], still_day_4_bgm);
        JsonSet(json["story_bgm"], story_bgm);
    }

    Story_SoundData::~Story_SoundData()
    {
        //èàóùÇ»Çµ
    }

    void Story_SoundData::JsonSet(Json json, SoundData& data)
    {
        data.name = json["name"];
        data.volume = json["volume"];
        data.type = json["type"];
        data.path = json["path"];
    }
}