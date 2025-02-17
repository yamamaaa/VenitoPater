#pragma once
#include <DxLib.h>
#include <memory>

namespace GameSystem
{
    /// <summary>
    /// ウィンドウ
    /// </summary>
    class Window
    {
    public:

        /// <summary>
        /// デストラクタ
        /// </summary>
        ~Window();

        /// <summary>
        /// 初期化処理
        /// </summary>
        static void Init();

        /// <summary>
        /// ウィンドウサイズ取得処理
        /// </summary>
        /// <returns>ウィンドウサイズ</returns>
        static const POINTS GetWindowSize() { return window->WINDOW_SIZE; }

    private:

        /// <summary>
        /// コンストラクタ
        /// </summary>
        Window();

        const POINTS WINDOW_SIZE = { 1920, 1080 };     //ウィンドウサイズ
        static std::unique_ptr<Window> window;              //自身の実体
        const int COLOR_BIT = 16;                           //カラービット
    };
}
