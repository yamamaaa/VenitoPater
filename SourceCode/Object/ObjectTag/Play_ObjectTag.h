#pragma once
#include <vector>
#include <string>

namespace objecttag
{
    /// <summary>
    /// ゲーム内の種類別タグ
    /// </summary>
    static struct Play_ObjectTag
    {
        std::string AREA = "area";
        std::string ClOCKWORK = "clockwork";
        std::string ITEM = "item";
        std::string FAMILIA = "familia";
        std::string MEMINI = "memini";
        std::string NIL = "nil";
        std::string SPERO = "spero";
        std::string IRA = "ira";
        std::string AVOID = "avoid";
        std::string PLAYER = "player";
        std::string MOVEAREA = "movearea";
        std::string ITEMUI = "itemui";
        std::string RPMHPUi = "rpmhpui";
        std::string AVOIDUI = "avoidui";
        std::string WARNINGUI = "warningUi";
        std::string TIME = "time";
        std::string ENEMYACTION = "enemyaction";
        std::string TEXTDRAW = "textdraw";
        std::string MENU = "menu";
    } play_ObjectTag;


    /// <summary>
    /// ループ制御用
    /// </summary>
    static std::vector<std::string>Play_ObjectTagAll
    {
        play_ObjectTag.AREA,
        play_ObjectTag.ClOCKWORK,
        play_ObjectTag.ITEM,
        play_ObjectTag.FAMILIA,
        play_ObjectTag.MEMINI,
        play_ObjectTag.NIL,
        play_ObjectTag.SPERO,
        play_ObjectTag.IRA,
        play_ObjectTag.AVOID,
        play_ObjectTag.PLAYER,
        play_ObjectTag.MOVEAREA,
        play_ObjectTag.ITEMUI,
        play_ObjectTag.RPMHPUi,
        play_ObjectTag.AVOIDUI,
        play_ObjectTag.WARNINGUI,
        play_ObjectTag.TIME,
        play_ObjectTag.ENEMYACTION,
        play_ObjectTag.MENU,
    };
}