#include "Window.h"

namespace GameSystem
{
    //実体を空に
    std::unique_ptr<Window> Window::window = nullptr;

    void Window::Init()
    {
        //実体に何も入っていなかったら
        if (!window)
        {
            //実体内にインスタンスを生成
            window.reset(new Window);
        }
    }

    Window::Window()
    {
        //TRUE ウィンドウモードで起動
        ChangeWindowMode(TRUE);
        //ウィンドウのサイズを設定
        SetGraphMode(static_cast<int>(WINDOW_SIZE.x), static_cast<int>(WINDOW_SIZE.y), COLOR_BIT);
        //ウィンドウ解像度を維持したままサイズ倍率を設定
        SetWindowSizeExtendRate(1.0);
        //ウィンドウのタイトル変更
        SetMainWindowText("VenitoPater");
    }

    Window::~Window()
    {
        //処理なし
    }
}
