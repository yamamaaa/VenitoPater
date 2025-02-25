#pragma once
#include "../../ObjectBase/ObjectBase.h"

namespace object
{
	class TitleUi:public ObjectBase
	{
    public:

        /// <summary>
        /// コンストラクタ
        /// </summary>
        TitleUi();

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~TitleUi();

    private:

        /// <summary>
        /// 読み込み関連
        /// </summary>
        void LoadObject() override;

        /// <summary>
        /// オブジェクトの更新
        /// </summary>
        /// <param name="deltatime">デルタタイム</param>
        void UpdateObj(const float deltatime) override ;

        /// <summary>
        /// オブジェクトの描画
        /// </summary>
        void DrawObj() override;

        int m_TVScreen_Handle;      //テレビ画面画像ハンドル
        POINTFLOAT m_TVScreenPos;   //テレビ画面画像位置
	};
}