#pragma once
#include <fstream>

#include"../ObjectBase/ObjectBase.h"

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
        /// 更新
        /// </summary>
        /// <param name="deltatime">デルタタイム</param>
        void UpdateObj(const float deltatime) override;

        /// <summary>
        /// 表示状態の更新
        /// </summary>
        void UpdateDrawStatus();

        /// <summary>
        /// 描画テキストのセット
        /// </summary>
        void DrawTextSet();

        /// <summary>
        /// 描画テキストのアニメーション
        /// </summary>
        void TextAnim();

        /// <summary>
        /// 描画
        /// </summary>
        void DrawObj()override;

        const std::string m_END = "null";   //ファイル末端コード

        std::ifstream m_TxtFile;//読み込まれたファイル

        LPCSTR m_FontPath;      //フォントタイプ
        std::string m_Line;     //ファイルから取得した文字
        std::string m_DrawText; //表示する文字

        const float m_WAITCOU_MAX = 3.0f;    //スタートしてから表示まで待ち時間
        float m_StartCount;                   //スタートカウント
        bool m_WaitDone;                      //待ち時間終了したか

        const float m_RISESPEED = 0.01f;			//増化速度

        int m_TxtNum;           //表示中の文字数

        bool m_IsLineSet;       //表示文字をセットしたか
        bool m_IslineAnim;      //表示文字がアニメ中か？

        bool m_IsLoadDone;       //文字の読み込みを終えるか
        bool m_IsDraw;           //文字の表示をするか

        float m_DrawCount;                        //文字の表示を終えるまで
        const float m_DRAW_COUNTMAX = 0.8f;       //文字の表示時間

        float m_AnimCount;      //文字のアニメカウント
        float m_AnimSpeed;      //アニメスピード

        const float m_ANIMFPS = 0.1f;   //アニメFPS
        const float m_SPEED_DEFAULT = 0.02f;    //アニメスピード(default)

        VECTOR m_NowCollar;                             //現在の文字色
        const VECTOR m_COLLAR_DEFAULT = VGet(255, 255, 255);  //白色
    };
}