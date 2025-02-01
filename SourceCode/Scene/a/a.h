#pragma once
#pragma once
#include"../../Scene/SceneBase/SceneBase.h"

namespace scene
{
    /// <summary>
    /// タイトル画面の進行管理クラス
    /// </summary>
    class a :public SceneBase
    {
    public:

        /// <summary>
        /// コンストラクタ
        /// </summary>
        a();

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~a();

    private:

        /// <summary>
        /// オブジェクト読み込み関連
        /// </summary>
        void LoadObject()override;

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

