#pragma once
#include <fstream>

#include"../ObjectBase/ObjectBase.h"
#include "../ObjectManager/ObjectManager.h"

/// <summary>
/// 画面サイズ関連
/// </summary>
namespace GameSystem
{
    class Window;
}

namespace object
{
    class TextDraw:public ObjectBase
    {
    public:

        /// <summary>
        /// コンストラクタ
        /// </summary>
        TextDraw();

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~TextDraw();

    private:

        /// <summary>
        /// 読み込み関連
        /// </summary>
        void LoadObject() override;

        /// <summary>
        /// ランダムで表示するセリフをセット
        /// </summary>
        void RandomLineSet();

        /// <summary>
        /// 更新
        /// </summary>
        /// <param name="deltatime">デルタタイム</param>
        void UpdateObj(const float deltatime) override;

        /// <summary>
        /// 表示状態の更新
        /// </summary>
        /// <param name="deltatime">デルタタイム</param
        void UpdateDrawStatus(const float deltatime);

        /// <summary>
        /// 描画テキストのセット
        /// </summary>
        void DrawTextSet();

        /// <summary>
        /// 描画テキストのアニメーション
        /// </summary>
        /// <param name="deltatime">デルタタイム</param>
        void TextAnim(const float deltatime);

        /// <summary>
        /// 日数の表示時間をカウント
        /// </summary>
        /// <param name="deltatime">デルタタイム</param>
        void NumDayDrawCount(const float deltatime);

        /// <summary>
        /// セリフの表示
        /// </summary>
        void LineDraw();

        /// <summary>
        /// 日数の表示
        /// </summary>
        void NumDayDraw();

        /// <summary>
        /// 描画
        /// </summary>
        void DrawObj()override;

        GameSystem::Window* window;
        POINTS m_WindowSize;

        GameStatus m_Status;        //現在のステータス

        const std::string m_END = "null";   //ファイル末端コード

        std::ifstream m_TxtFile;//読み込まれたファイル

        LPCSTR m_FontPath;      //フォントタイプ
        std::string m_Line;     //ファイルから取得した文字
        std::string m_DrawText; //表示する文字

        const POINTS m_FONTSIZE_Line = { 30,5 };      //フォントサイズ_セリフ
        const POINTS m_FONTSIZE_Day = { 90,20 };     //フォントサイズ_日数

        bool m_IsReleaseObj;        //処理を終わるか

        const float m_DROPSPEED = 70.0f;		      //減分速度
        const float m_COUNTSPEED = 5.0f;              //タイムカウントスピード
        const float m_COUNTMAX = 40.0f;               //カウント最大値

        float m_DrawCount;              //文字の透過を開始or文字の表示を終えるまで

        int m_FontHandle;               //フォントハンドル

        const float m_WAITCOU_MAX = 3.0f;     //スタートしてから表示まで待ち時間
        float m_StartCount;                   //スタートカウント
        bool m_WaitDone;                      //待ち時間終了したか

        const float m_RISESPEED = 0.6f;			//増化速度

        int m_TxtNum;           //表示中の文字数

        bool m_IsLineSet;       //表示文字をセットしたか
        bool m_IslineAnim;      //表示文字がアニメ中か？

        const float m_DRAW_COUNTMAX = 2.4f;       //文字の表示時間

        float m_AnimCount;      //文字のアニメカウント
        float m_AnimSpeed;      //アニメスピード

        const float m_ANIMFPS = 0.1f;           //アニメFPS
        const float m_SPEED_DEFAULT = 2.0f;    //アニメスピード(default)

        VECTOR m_NowColor;                             //現在の文字色
        const VECTOR m_COLOR_DEFAULT = VGet(255, 255, 255);  //白色

    };
}