#include "GameOverData.h"

namespace json_textdata
{
    GameOverData::GameOverData(Json json)
    {
        line_0 = json["line_0"];
        line_1 = json["line_1"];
        line_2 = json["line_2"];
        line_3 = json["line_3"];

        timeover = json["timeover"];
    }

    GameOverData::~GameOverData()
    {
        //ˆ—‚È‚µ
    }
}