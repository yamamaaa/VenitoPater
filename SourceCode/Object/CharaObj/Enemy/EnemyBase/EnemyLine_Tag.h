#pragma once
#include <vector>
#include <string>

namespace objecttag
{
    /// <summary>
    /// 敵の行動ラインタグ
    /// </summary>
    static struct EnemyLine_Tag
    {
        std::string APPEAR = "appear";
        std::string REPLACE = "replace";
        std::string REPLACE_2 = "replace_2";
        std::string ACTION = "action";
    }enemyline_tag;


    /// <summary>
    /// ループ制御用
    /// </summary>
    static std::vector<std::string>EnemyLine_TagAll
    {
        enemyline_tag.APPEAR,       //敵の出現ライン
        enemyline_tag.REPLACE,      //画像の差し替えライン
        enemyline_tag.REPLACE_2,    //画像の差し替えライン
        enemyline_tag.ACTION,       //攻撃ライン
    };

    /// <summary>
    /// 列挙型用
    /// </summary>
    enum EnemyLine_TagNum
    {
        appear,
        replace,
        replace_2,
        action,
    };
}