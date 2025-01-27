#pragma once
#include "../../MouseBase/MouseBase.h"

/// <summary>
/// 画面サイズ関連
/// </summary>
namespace GameSystem
{
    class Window;
}

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

        GameSystem::Window* window;

        POINTFLOAT m_ResultLogo_Pos;    //リザルトロゴ表示座標

        POINTFLOAT m_SelectUi_Pos[2];       //セレクトUi座標
        POINTFLOAT m_UiOffset[2];           //座標ずらし量
        POINTFLOAT m_Uipos;                 //Ui位置

        int m_FontHandle;          //フォントハンドル(タイトル)
        int m_FontHandle_Ui;       //フォントハンドル(Ui)

        const POINTS m_FONTSIZE = { 150,60 };     //フォントサイズ(タイトル)
        const POINTS m_FONTSIZE_Ui = { 30,10 };    //フォントサイズ(Ui)

        const int m_COLOR = 255;       //カラーコード

        const std::string m_Title = "GameOver";
        const std::string m_SelectText[2] = { "コンテニュー" ,"タイトルへ" };

#ifdef DEBUG
        std::string m_selectstatus = "";
#endif // DEBUG
    };
}

