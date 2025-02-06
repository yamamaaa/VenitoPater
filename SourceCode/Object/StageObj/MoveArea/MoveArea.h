#pragma once
#include <unordered_map>
#include<vector>
#include"../../MouseBase/MouseBase.h"
#include"../../StageObj/Area/AreaMove_PosTag.h"

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

        const float m_COUNTSPPED_MOVE = 60.0f;   //再び移動できるまで(カウントスピード)
        const float m_MOVECOUNT_MAX = 18.0f;     //再び移動できるまで(カウント最大値)

        const int m_CEILINGAREA_NUM = 3;    //天井エリアナンバー
        const int m_FRONTAREA_NUM = 1;      //正面エリアナンバー

        bool m_IsMove;       //エリア移動したか
        bool m_CanMove;       //エリア移動できるか
        float m_MoveCount;   //エリア移動した際のカウント

        std::unordered_map<std::string, int> m_MoveUiImg{};         //エリア移動のUi画像
        std::unordered_map<std::string, POINTFLOAT> m_MoveUiPos{};  //エリア移動のUi画像位置

        //上左右下のHitPos
        std::unordered_map<std::string, POINTS> m_HitSize{
            {areaMove_PosTag.UP,{900,150}},
            {areaMove_PosTag.RIGHT,{150,800}},
            {areaMove_PosTag.LEFT,{150,800}},
            {areaMove_PosTag.DOWN,{900,150}},
        };

        //上左右下のMovePos
        std::unordered_map<std::string, POINTFLOAT> m_MovePos{
            {areaMove_PosTag.UP,{500.0f,0.0f}},
            {areaMove_PosTag.RIGHT,{0.0f,200.0f}},
            {areaMove_PosTag.LEFT,{1770.0f,200.0f}},
            {areaMove_PosTag.DOWN,{500.0f,930.0f}},
        };

        //カーソルのヒット状態
        std::unordered_map<std::string, bool> m_AreaNumber{
            {areaMove_PosTag.UP,{true}},
            {areaMove_PosTag.RIGHT,{true}},
            {areaMove_PosTag.LEFT,{true}},
            {areaMove_PosTag.DOWN,{false}},
        };

#if DEBUG

        //上左右下のHitlineのカラーコード
        std::unordered_map<std::string, VECTOR> d_ColorCode{
            {areaMove_PosTag.UP,{255,40,0}},
            {areaMove_PosTag.RIGHT,{250,245,0}},
            {areaMove_PosTag.LEFT,{53,161,107}},
            {areaMove_PosTag.DOWN,{0,65,255}},
        };

        //カーソルが当たったか
        std::unordered_map<std::string, std::string> d_CursorHit{
            {areaMove_PosTag.UP,""},
            {areaMove_PosTag.RIGHT,""},
            {areaMove_PosTag.LEFT,""},
            {areaMove_PosTag.DOWN,""},
        };
#endif
    };
}
