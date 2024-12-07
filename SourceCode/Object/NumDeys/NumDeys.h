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

        static std::unique_ptr<NumDeys> numdeys;	//自身の実態

    };
}