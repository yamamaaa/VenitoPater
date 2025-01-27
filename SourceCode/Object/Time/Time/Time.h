#pragma once
#include "../../ObjectBase/ObjectBase.h"

namespace object
{
    /// <summary>
    /// ゲーム内時間関連
    /// </summary>
    class Time :public ObjectBase
    {
    public:

        /// <summary>
        /// コンストラクタ
        /// </summary>
        Time();

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~Time();

    private:

        /// <summary>
        /// 読み込み関連
        /// </summary>
        void LoadObject() override;

        /// <summary>
        /// 更新
        /// </summary>
        /// <param name="deltatime"></param>
        void UpdateObj(float deltatime) override;

        /// <summary>
        /// 描画
        /// </summary>
        void DrawObj()override;

        const float m_TIMEMAX = 300.0f;
        const float m_RISETIME = 0.01f;    //増化分

        const float m_TIMER_MAX = 1.0f;    // タイマー最大値
        const float m_TIMERFPS = 0.1f;     // タイマーFPS

        const int m_MINUTES_RISETIME =10;    //表示用分増化分
        const int m_MINUTES_MAX = 60;    //表示用分増化最大値

        const POINTS m_FONTSIZE_AM = { 35,20 };      //フォントサイズ_am
        const POINTS m_FONTSIZE_TIME = { 60,20 };    //フォントサイズ_時刻

        int m_FontHandle_Am;    //フォントハンドル(am)
        int m_FontHandle_Time;  //フォントハンドル(time)

        const int m_PLAYTIME_MAX = 5;       //プレイタイムの終了時刻

        POINTFLOAT m_TimePos;   //時刻表示位置

        float m_NowTime;   //実際の経過時間
        int m_DrawTime;       //表示用_時間
        int m_DrawMinutes;    //表示用_分

        float m_DrawCount;   //表示時刻の算出

        std::string m_AmText = "AM";            //表示テキスト(am)
        std::string m_TimeText = "%d:%d";       //表示テキスト(time)
        std::string m_TimeText_Zero = "%d:00";  //表示テキスト(time_zeromin)

        VECTOR m_NowColor;                             //現在の文字色
        VECTOR m_COLOR_DEFAULT = VGet(255, 255, 255);  //白色
        VECTOR m_COLOR_RED = VGet(255, 0, 0);          //赤色
    };
}