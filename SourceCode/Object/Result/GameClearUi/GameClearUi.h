#pragma once
#include "../../ObjectBase/ObjectBase.h"

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
	/// ゲームクリア関連
	/// </summary>
	class GameClearUi:public ObjectBase
	{
    public:

        /// <summary>
        /// コンストラクタ
        /// </summary>
        GameClearUi();

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~GameClearUi();

    private:

        /// <summary>
        /// 読み込み関連
        /// </summary>
        void LoadObject() override;

        /// <summary>
        /// オブジェクトの更新
        /// </summary>
        /// <param name="deltatime">デルタタイム</param>
        void UpdateObj(const float deltatime) override;

        /// <summary>
        /// 次のゲームステータスをセット
        /// </summary>
        void SetNextGame_Status();

        /// <summary>
        /// オブジェクトの描画
        /// </summary>
        void DrawObj() override;

        GameSystem::Window* window;

        int m_FontHandle;                       //フォントハンドル
        const POINTS m_FONTSIZE = { 200,60 };   //フォントサイズ

        std::string m_TimeText = "5:00";        //表示テキスト

        bool m_IsSound;      //サウンドを再生したか

        const float m_DRAWCOUNT_MAX = 12.0f;    //表示時間
        const float m_COUNT_DECREMENT = 1.0f;	//カウント減分値
        const int m_COLOR = 255;                //カラーコード

        float m_DrawCount;  //表示時間カウント
	};
}