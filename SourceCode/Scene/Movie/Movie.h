#pragma once
#include"../../Scene/SceneBase/SceneBase.h"

namespace scene
{
    /// <summary>
     /// ゲーム終了画面関連
     /// </summary>
    class Movie :public SceneBase
    {
    public:

        /// <summary>
        /// コンストラクタ
        /// </summary>
        Movie();

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~Movie();

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

        std::string m_MovieFile;  //再生する動画のファイルパス
    };
}