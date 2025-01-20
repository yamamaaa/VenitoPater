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
        /// 描画
        /// </summary>
        void DrawObj()override;

        //ゲームステータス変更コード
        const std::string m_GAMEPLAY = "GamePlay";
        const std::string m_STORY = "Story";
        const std::string m_STILL = "Still";

        //日数変更コード
        const std::string m_DEY = "Dey";

        std::string m_EndTxt;   //ファイル末端コード

        std::ifstream m_TxtFile;//読み込まれたファイル

        LPCSTR m_FontPath;      //フォントタイプ
        std::string m_Line;     //表示する文字

        int m_TxtNum;           //表示中の文字数

        bool m_IsClick;         //クリックしたか
        bool m_IsLineSet;       //表示文字をセットしたか
        bool m_IslineAnim;      //表示文字がアニメ中か？

        float m_ClickCount;     //再度クリックできるまで
        float m_AnimCount;      //文字のアニメカウント
	};
}


