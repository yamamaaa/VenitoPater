#pragma once
#include "../../ObjectBase/ObjectBase.h"

namespace object
{
	/// <summary>
	/// 回避Ui関連
	/// </summary>
	class AvoidUi :public ObjectBase
	{
    public:

        /// <summary>
        /// コンストラクタ
        /// </summary>
        AvoidUi();

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~AvoidUi();

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

        const int m_Hide_DrawArea = 3;  //Uiを表示できないエリア
        bool m_CanDraw;                 //表示できる状態か？
	};
}