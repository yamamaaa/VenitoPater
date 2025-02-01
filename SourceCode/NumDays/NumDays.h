#pragma once
#include<Dxlib.h>
#include <memory>

namespace object
{
    /// <summary>
    /// ゲーム内日数関連
    /// </summary>
    class NumDays final
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
        static int GetNumDays() { return numdays->m_NumDays; }

        /// <summary>
        /// 日数を増やす
        /// </summary>
        static void UpdateNumDays();

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~NumDays();

    private:

        /// <summary>
        /// コンストラクタ
        /// </summary>
        NumDays();

        /// <summary>
        /// 読み込み関連
        /// </summary>
        static void LoadObject();

        int m_NumDays;                  //ゲーム内日数

        static std::unique_ptr<NumDays> numdays;	//自身の実態
    };
}