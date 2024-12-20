#pragma once
#include <vector>
#include <string>

namespace objecttag
{
    /// <summary>
    /// 3Daysモード内の種類別タグ
    /// </summary>
    static struct ThreeDays_ObjTag
    {
        std::string AREA = "area";
        std::string MOVEAREA = "movearea";
        std::string ClOCKWORK = "clockwork";
        std::string ITEM = "item";
        std::string FAMILIA = "familia";
        std::string MEMINI = "memini";
        std::string NIL = "nil";
        std::string SPERO = "spero";
        std::string IRA = "ira";
        std::string AVOID = "avoid";
        std::string PLAYER = "player";
    } threedays_objtag;


    /// <summary>
    /// ループ制御用
    /// </summary>
    static std::vector<std::string>ThreeDays_ObjTagAll
    {
        threedays_objtag.AREA,
        threedays_objtag.MOVEAREA,
        threedays_objtag.ClOCKWORK,
        threedays_objtag.ITEM,
        threedays_objtag.FAMILIA,
        threedays_objtag.MEMINI,
        threedays_objtag.NIL,
        threedays_objtag.SPERO,
        threedays_objtag.IRA,
        threedays_objtag.AVOID,
        threedays_objtag.PLAYER,
    };
}