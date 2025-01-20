#pragma once
#include "../../ObjectBase/ObjectBase.h"

namespace object
{
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
        /// オブジェクトの描画
        /// </summary>
        void DrawObj() override;

        const float m_DRAWCOUNT_MAX = 50.0f;   //表示時間
        const float m_COUNT_DECREMENT = 0.1f;	//カウント減分値

        float m_DrawCount;  //表示時間カウント
	};
}