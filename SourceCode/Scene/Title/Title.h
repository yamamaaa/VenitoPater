#pragma once
#include"../../Scene/SceneBase/SceneBase.h"

namespace scene
{
    /// <summary>
    /// タイトル画面の進行管理クラス
    /// </summary>
    class Title :public SceneBase
    {
    public:

        /// <summary>
        /// コンストラクタ
        /// </summary>
        Title();

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~Title();

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

        bool m_IsNextSame;      //次も同じシーンか
        float m_Change_Count;   //ムービーモードに変わるまでのカウント

        const float m_COUNT_DECREMENT = 1.0f;     //カウント減らし量
        const float m_COUNT_MAX = 200.0f;         //ムービーモードに変わるまで
    };
}