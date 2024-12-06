#pragma once
#include"../../MouseBase/MouseBase.h"

namespace object
{
    /// <summary>
    /// プレイヤー関連
    /// </summary>
    class Player:public MouseBase
    {
    public:

        /// <summary>
        /// コンストラクタ
        /// </summary>
        Player();

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~Player();

        /// <summary>
        /// 読み込み関連
        /// </summary>
        void LoadObject() override;

        void UpdateObj(const float deltatime) override;

        void DrawObj()override;

        void MoveObj(const float deltatime)override;

    private:

#ifdef DEBUG
        std::string select_level = "";  //難易度表示
        std::string mouse_click = "";   //マウスクリック状態
#endif
    };

}

