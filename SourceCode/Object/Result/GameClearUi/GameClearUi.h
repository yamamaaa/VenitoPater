#pragma once
#include "../../ObjectBase/ObjectBase.h"

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


        const float m_DRAWCOUNT_MAX = 50.0f;    //表示時間
        const float m_COUNT_DECREMENT = 0.1f;	//カウント減分値
        const int m_FONTSIZE = 150;             //フォントサイズ
        const int m_CORRER_CODE = 255;          //カラーコード

        float m_DrawCount;  //表示時間カウント
	};
}