#pragma once
#include "../../MouseBase/MouseBase.h"

namespace object
{
    //回転量HPUi関連
	class RPMHPUi :public MouseBase
	{
    public:

        /// <summary>
        /// コンストラクタ
        /// </summary>
        RPMHPUi();

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~RPMHPUi();

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

        const int m_DrawArea = 3;  //Uiを表示できるエリア

        POINTS m_HPDrawPos;       //回転量Hpバー表示位置

        POINTS m_FillBoxSize;     //回転量HP残量表示サイズ
        POINTS m_LineBoxSize;     //HPバーの囲いサイズ

        VECTOR m_FillBox_Color;    //カラーコード
        VECTOR m_LineBox_Color;

        float m_DrawValue;       //HP残量表示用
        bool m_CanDraw; //表示できるか
	};
}