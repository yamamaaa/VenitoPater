#pragma once
#include"../../ObjectBase/ObjectBase.h"

namespace object
{
    class BackGround: public ObjectBase
    {
    public:

        /// <summary>
        /// コンストラクタ
        /// </summary>
        BackGround();

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~BackGround();

    private:

        /// <summary>
        /// 読み込み関連
        /// </summary>
        void LoadObject() override;

        /// <summary>
        /// オブジェクトの更新
        /// </summary>
        /// <param name="deltatime">デルタタイム</param>
        void UpdateObj(const float deltatime) override {};

        /// <summary>
        /// オブジェクトの描画
        /// </summary>
        void DrawObj() override;
    };
}