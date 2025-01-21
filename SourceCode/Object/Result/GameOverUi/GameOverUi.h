#pragma once
#include "../../MouseBase/MouseBase.h"

namespace object
{
    /// <summary>
    /// ゲームオーバー画面関連
    /// </summary>
    class GameOverUi :public MouseBase
    {
    public:

        /// <summary>
        /// コンストラクタ
        /// </summary>
        GameOverUi();

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~GameOverUi();

    private:

        /// <summary>
        /// 読み込み関連
        /// </summary>
        void LoadObject() override ;

        /// <summary>
        /// オブジェクトの更新
        /// </summary>
        /// <param name="deltatime">デルタタイム</param>
        void UpdateObj(const float deltatime) override;

        /// <summary>
        /// オブジェクトの描画
        /// </summary>
        void DrawObj() override;

        POINTS m_ResultLogo_Pos;    //リザルトロゴ表示座標

        POINTS m_SelectUi_Pos[2];       //セレクトUi座標
        POINTS m_UiOffset[2];           //座標ずらし量
        POINTS m_Uipos;

#ifdef DEBUG
        std::string m_selectstatus = "";
#endif // DEBUG
    };
}

