#pragma once
#include <memory>

namespace object
{
    class NumDeys final
    {
    public:

        /// <summary>
        /// 初期化
        /// </summary>
        static void Initialize();

        /// <summary>
        /// 現在の日数を取得
        /// </summary>
        /// <returns>現在の日数</returns>
        static int GetNumDeys() { return numdeys->m_NumDeys; }

        /// <summary>
        /// 日数を増やす
        /// </summary>
        static void UpdateNumDeys();

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~NumDeys();

    private:

        /// <summary>
        /// コンストラクタ
        /// </summary>
        NumDeys();

        /// <summary>
        /// 読み込み関連
        /// </summary>
        static void LoadObject();

        int m_NumDeys;  //ゲーム内日数

        static std::unique_ptr<NumDeys> numdeys;	//自身の実態

    };
}