#pragma once

namespace collision
{
    /// <summary>
    /// 四角形同士の当たり判定
    /// </summary>
    /// <param name="x1">判定Aのｘ座標</param>
    /// <param name="y1">判定Aのy座標</param>
    /// <param name="w1">判定Aのあたり判定　横幅</param>
    /// <param name="h1">判定Aのあたり判定　縦幅</param>
    /// <param name="x2">判定Bのｘ座標</param>
    /// <param name="y2">判定Bのy座標</param>
    /// <param name="w2">判定Bのあたり判定　横幅</param>
    /// <param name="h2">判定Bのあたり判定　縦幅</param>
    bool CheckHitSquare(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2);

    /// <summary>
    /// 点と四角形の当たり判定
    /// </summary>
    /// <param name="x1">判定Aのｘ座標</param>
    /// <param name="y1">判定Aのy座標</param>
    /// <param name="x2">判定Bのｘ座標</param>
    /// <param name="y2">判定Bのy座標</param>
    /// <param name="w2">判定Bのあたり判定　横幅</param>
    /// <param name="h2">判定Bのあたり判定　縦幅</param>
    bool CheckHitPoint_Square(float x1, float y1,float x2, float y2, float w2, float h2);
}

