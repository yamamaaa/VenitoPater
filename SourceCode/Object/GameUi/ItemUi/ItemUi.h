#pragma once
#include "../../ObjectBase/ObjectBase.h"

namespace object
{
    /// <summary>
    /// アイテムUi関連
    /// </summary>
    class ItemUi:public ObjectBase
    {
    public:

        /// <summary>
        /// コンストラクタ
        /// </summary>
        ItemUi();

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~ItemUi();

    private:

        /// <summary>
        /// 読み込み関連
        /// </summary>
        void LoadObject() override;

        /// <summary>
        /// 更新
        /// </summary>
        /// <param name="deltatime">デルタタイム</param>
        void UpdateObj(const float deltatime) override {};

        /// <summary>
        /// 描画
        /// </summary>
        void DrawObj()override ;

        int m_RItem_Handole; //レアアイテム画像ハンドル

        POINTFLOAT m_RItem_ObjPos;           //レアアイテム画像位置

        POINTFLOAT m_NItemNum_Pos;           //アイテム獲得数表示位置
        POINTFLOAT m_RItemNum_Pos;           //レアアイテム獲得数表示位置

        const int m_COLLARCODE = 255;        //カラーコード
        const int m_FONTSIZE = 35;           //フォントサイズ
    };
}