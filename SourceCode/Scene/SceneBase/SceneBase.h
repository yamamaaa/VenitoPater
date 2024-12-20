#pragma once
#include<Dxlib.h>

#include"../../Transitor/FadeTransitor/FadeTransitor.h"

namespace transitor
{
    /// <summary>
    /// 画面移転_フェード関連
    /// </summary>
    class FadeTransitor;
}

namespace scene
{
    /// <summary>
    /// シーンの更新処理クラス
    /// </summary>
    class SceneBase
    {
    public:

        /// <summary>
        /// コンストラクタ
        /// </summary>
        SceneBase();

        /// <summary>
        /// デストラクタ
        /// </summary>
        virtual ~SceneBase();

        /// <summary>
        /// シーン更新処理
        /// </summary>
        /// <param name="deltaTime">デルタタイム</param>
        /// <returns>次のフレームシーン</returns>
        virtual SceneBase* UpdateScene(const float deltaTime) = 0;

        /// <summary>
        /// シーン描画処理
        /// </summary>
        virtual void DrawScene() = 0;

    protected:

        transitor::FadeTransitor* fade_transitor;   //フェード関連
    };
}