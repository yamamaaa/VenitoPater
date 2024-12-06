#pragma once
#include <unordered_map>
#include"../../MouseBase/MouseBase.h"
#include"../../StageObj/Stage/StageMove_PosTag.h"

namespace object
{
    /// <summary>
    /// エリア移動関連
    /// </summary>
    class MoveArea :public MouseBase
    {
    public:

        /// <summary>
        /// コンストラクタ
        /// </summary>
        MoveArea();

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~MoveArea();

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

        /// <summary>
        /// 現在のエリアナンバーを更新
        /// </summary>
        /// <param name="tagname">当たったBoxのタグ名</param>
        void Update_AreaNumber(const std::string tagname);

        /// <summary>
        /// カーソルのヒット状態を分ける
        /// </summary>
        void CursorHitControl();

        const int m_CEILINGAREA_NUM = 3;    //天井エリアナンバー
        const int m_FRONTAREA_NUM = 1;      //正面エリアナンバー

        const float m_MOVECOUNT_MAX = 30.0f;     //再び移動できるまで

        bool m_IsMove;       //エリア移動したか
        bool m_CanMove;       //エリア移動できるか
        float m_MoveCount;   //エリア移動した際のカウント

        //上左右下のHitPos
        std::unordered_map<std::string, POINTS> m_HitSize{
            {stagemove_postag.UP,{900,150}},
            {stagemove_postag.RIGHT,{150,800}},
            {stagemove_postag.LEFT,{150,800}},
            {stagemove_postag.DOWN,{900,150}},
        };

        //上左右下のMovePos
        std::unordered_map<std::string, POINTFLOAT> m_MovePos{
            {stagemove_postag.UP,{500.0f,0.0f}},
            {stagemove_postag.RIGHT,{0.0f,200.0f}},
            {stagemove_postag.LEFT,{1770.0f,200.0f}},
            {stagemove_postag.DOWN,{500.0f,930.0f}},
        };

        //カーソルのヒット状態
        std::unordered_map<std::string, bool> m_AreaNumber{
            {stagemove_postag.UP,{true}},
            {stagemove_postag.RIGHT,{true}},
            {stagemove_postag.LEFT,{true}},
            {stagemove_postag.DOWN,{false}},
        };

#ifdef DEBUG

        //上左右下のHitlineのカラーコード
        std::unordered_map<std::string, VECTOR> d_CollarCode{
            {stagemove_postag.UP,{255,40,0}},
            {stagemove_postag.RIGHT,{250,245,0}},
            {stagemove_postag.LEFT,{53,161,107}},
            {stagemove_postag.DOWN,{0,65,255}},
        };

        //カーソルが当たったか
        std::unordered_map<std::string, std::string> d_CursorHit{
            {stagemove_postag.UP,""},
            {stagemove_postag.RIGHT,""},
            {stagemove_postag.LEFT,""},
            {stagemove_postag.DOWN,""},
        };
#endif
    };
}
