#pragma once
#include <DxLib.h>
#include <memory>

namespace GameSystem
{
    /// <summary>
    /// ゲームセッティング
    /// </summary>
    class GameSetting final
    {
    public:

        /// <summary>
        /// 初期化処理
        /// </summary>
        static void Init();

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~GameSetting();

    private:

        /// <summary>
        /// コンストラクタ
        /// </summary>
        GameSetting();

        /// <summary>
        /// ライブラリ初期化前の処理
        /// </summary>
        static void BeforeLibInit();

        /// <summary>
        /// ライブラリ初期化後の処理
        /// </summary>
        static void AfterLibInit();

        static std::unique_ptr<GameSetting> gamesetting;           //自身の実体

    };
}