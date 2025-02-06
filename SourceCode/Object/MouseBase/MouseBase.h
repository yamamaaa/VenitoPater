#pragma once
#include"../ObjectBase/ObjectBase.h"

namespace object
{
    /// <summary>
    /// マウス操作基底クラス
    /// </summary>
    class MouseBase:public ObjectBase
    {
    public:
      
        /// <summary>
        /// コンストラクタ
        /// </summary>
        /// <param name="tagname">タグ名</param>
        MouseBase(std::string tagname);

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~MouseBase();

    protected:

        /// <summary>
        /// 左クリック入力状態取得
        /// </summary>
        /// <returns>入力時:true|未入力時:false</returns>
        const bool GetStateClick() const { return  m_StateClick; }

        /// <summary>
        /// カーソルがオブジェクトに当たっているか
        /// </summary>
        /// <returns>当たっている:true|当たっていない:false</returns>
        const bool GetCursorHit() const { return  m_CursorHit; }

        /// <summary>
        /// クリックできるか？
        /// </summary>
        void CanClick();

        /// <summary>
        /// クリックしたら
        /// </summary>
        void MouseClick();

        /// <summary>
        /// マウスとオブジェクトの当たり判定
        /// </summary>
        void CursorHit();

#if DEBUG
        /// <summary>
        /// デバック用座標状態表示 削除予定
        /// </summary>
        void Debug_DrawObj();
#endif
        bool m_StateClick;        //マウスクリック状態
        bool m_CanClick;          //クリック可能状態
        bool m_CursorHit;         //カーソルがオブジェクトに当たっているか？

    private:

        /// <summary>
        /// 読み込み関連
        /// </summary>
        void LoadObject() override ;

        /// <summary>
        /// 更新
        /// </summary>
        /// <param name="deltatime"></param>
        void UpdateObj(float deltatime) override {};

        /// <summary>
        /// 描画
        /// </summary>
        void DrawObj()override {};

        int m_MousePosX;    //カーソル座標X
        int m_MousePosY;    //カーソル座標Y
    };
}


