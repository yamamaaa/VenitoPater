#pragma once
#include <memory>

namespace object
{
    /// <summary>
    /// 文字状態関連
    /// </summary>
    class LineStatus final
    {
    public:

        /// <summary>
        /// 初期化
        /// </summary>
        static void Initialize();

        /// <summary>
        /// 文字のアニメーションが終了したか取得
        /// </summary>
        /// <returns>true:終了|false:未終了</returns>
        static const bool GetIsDoneAnim(){ return linestatus->m_IsDoneAnim; }

        /// <summary>
        /// 文字のアニメーションが終了したかセット
        /// </summary>
        /// <param name="status">true:終了|false:未終了</param>
        static void SetIsDoneAnim(const bool status) {linestatus->m_IsDoneAnim = status; }

        /// <summary>
        /// 表示画像のセットが終了したか取得
        /// </summary>
        /// <returns>true:終了|false:未終了</returns>
        static const bool GetIsDoneImgDraw() { return linestatus->m_IsDoneImgDraw; }

        /// <summary>
        /// 表示画像をセットし終えたか
        /// </summary>
        /// <param name="status">true:終了|false:未終了</param>
        static void SetIsDoneImgDraw(const bool status) { linestatus->m_IsDoneImgDraw = status; }

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~LineStatus();

    private:

        /// <summary>
        /// コンストラクタ
        /// </summary>
        LineStatus();

        /// <summary>
        /// 読み込み関連
        /// </summary>
        static void LoadObject();

        bool m_IsDoneAnim;      //文字のアニメが終了したか
        bool m_IsDoneImgDraw;   //表示画像をセットし終えたか

        static std::unique_ptr<LineStatus> linestatus;	//自身の実態
    };
}