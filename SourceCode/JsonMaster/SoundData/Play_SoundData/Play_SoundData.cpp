#include "Play_SoundData.h"

namespace json_sounddata
{
    Play_SoundData::Play_SoundData(Json json)
    {
        JsonSet(json["bgm"], bgm);
        JsonSet(json["clockwork"], clockwork);
        JsonSet(json["duck_0"], duck_0);
        JsonSet(json["duck_1"], duck_1);
        JsonSet(json["duck_2"], duck_2);
        JsonSet(json["emyaction"], emyaction);
        JsonSet(json["enemy"], enemy);
        JsonSet(json["hat"], hat);
        JsonSet(json["ira"], ira);
        JsonSet(json["light"], light);
        JsonSet(json["musicbox"], musicbox);
    }

    Play_SoundData::~Play_SoundData()
    {
        //èàóùÇ»Çµ
    }

    void Play_SoundData::JsonSet(Json json, SoundData& data)
    {
        data.name = json["name"];
        data.volume = json["volume"];
        data.type = json["type"];
        data.path = json["path"];
    }
}