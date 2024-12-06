#pragma once
#include"../../../Scene/SceneBase/SceneBase.h"

namespace scene
{
    class GameOver:public SceneBase
    {
    public:

        /// <summary>
        /// コンストラクタ
        /// </summary>
        GameOver();

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~GameOver();

        /// <summary>
        /// シーン更新処理
        /// </summary>
        /// <param name="deltaTime">デルタタイム</param>
        /// <returns>次のフレームシーン</returns>
        SceneBase* UpdateScene(const float deltaTime)override;

        /// <summary>
        /// シーン更新処理
        /// </summary>
        void DrawScene()override;

    };
}