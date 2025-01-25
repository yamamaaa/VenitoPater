#pragma once
#include <fstream>

#include"../../ObjectBase/ObjectBase.h"

namespace object
{
	/// <summary>
	/// ストーリー中のセリフ関連
	/// </summary>
	class Line:public ObjectBase
	{
    public:

        /// <summary>
        /// コンストラクタ
        /// </summary>
        Line();

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~Line();

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
        /// クリック状態
        /// </summary>
        void ClickStatus();

        /// <summary>
        /// 描画テキストのセット
        /// </summary>
        void DrawTextSet();

        /// <summary>
        /// テキスト読み込み終了時処理_Story時
        /// </summary>
        void Text_Processing(std::string line);

        /// <summary>
        /// 描画テキストのアニメーション
        /// </summary>
        void TextAnim();

        /// <summary>
        /// 描画
        /// </summary>
        void DrawObj()override;

        //ゲームステータス変更コード
        const std::string m_GAMEPLAY = "gameplay";
        const std::string m_STORY = "story";
        const std::string m_STILL = "still";

        const std::string m_END = "null";   //ファイル末端コード
        const std::string m_DAY = "day";    //日数変更コード
        const std::string m_RED = "red";    //文字色変更コード
        const std::string m_SLOW = "slow";  //文字アニメスピード変更コード

        std::ifstream m_TxtFile;//読み込まれたファイル

        std::string m_Line;     //ファイルから取得した文字
        std::string m_DrawText; //表示する文字

        std::string m_FontTag;  //フォント名
        int m_FontHandol;       //フォントハンドル

        int m_TxtNum;           //表示中の文字数

        const float m_WAITCOU_MAX = 3.0f;     //スタートしてから表示まで待ち時間
        float m_StartCount;                   //スタートカウント
        bool m_WaitDone;                      //待ち時間終了したか

        const float m_COUNT_DECREMENT = 0.01f;	//カウント減らし量
        const float m_CLICKCOU_MAX = 0.5f;      //再度クリックできるまで
        const float m_CLICKCOU_WEIT = 2.0f;    //待機モード中の待ち時間

        bool m_IsClick;         //クリックしたか
        bool m_IsLineSet;       //表示文字をセットしたか
        bool m_IslineAnim;      //表示文字がアニメ中か？

        bool m_IsLineDone;      //ファイル末端コードまで読み込んだか

        bool m_IsWeitMode;      //表示が文字無し状態か(待機)

        float m_ClickCount;     //再度クリックできるまで
        float m_AnimCount;      //文字のアニメカウント
        float m_AnimSpeed;      //アニメスピード

        const float m_ANIMFPS = 0.1f;   //アニメFPS
        const float m_SPEED_DEFAULT = 0.1f;    //アニメスピード(default)
        const float m_SPEED_SLOW = 0.02f;       //アニメスピード(slow)

        VECTOR m_NowCollar;                             //現在の文字色
        VECTOR m_COLLAR_DEFAULT = VGet(255, 255, 255);  //白色
        VECTOR m_COLLAR_RED = VGet(255, 0, 0);          //赤色
	};
}


