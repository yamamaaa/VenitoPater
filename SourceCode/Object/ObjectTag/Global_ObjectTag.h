#pragma once
#include <vector>
#include <string>

namespace objecttag
{
    /// <summary>
    /// オブジェクトの種類別タグ
    /// </summary>
    static struct Global_ObjectTag
    {
        std::string STAGE = "stage";
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
    } global_objecttag;


    /// <summary>
    /// ループ制御用
    /// </summary>
    static std::vector<std::string>Global_ObjectTagAll
    {
        global_objecttag.STAGE,
        global_objecttag.MOVEAREA,
        global_objecttag.ClOCKWORK,
        global_objecttag.ITEM,
        global_objecttag.FAMILIA,
        global_objecttag.MEMINI,
        global_objecttag.NIL,
        global_objecttag.SPERO,
        global_objecttag.IRA,
        global_objecttag.AVOID,
        global_objecttag.PLAYER,
    };
}