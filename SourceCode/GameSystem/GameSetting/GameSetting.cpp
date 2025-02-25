#include "GameSetting.h"

namespace GameSystem
{
    //実体の初期化
    std::unique_ptr<GameSetting> GameSetting::gamesetting = nullptr;

    void GameSetting::Init()
    {
        //実体に何も入っていなかったら
        if (!gamesetting)
        {
            //実体内にインスタンスを生成
            gamesetting.reset(new GameSetting);
        }
    }

    GameSetting::GameSetting()
    {
        BeforeLibInit();

        //DxLib初期化処理
        if (DxLib_Init() == -1)
        {
            //エラーが起きたら直ちに終了
            DebugBreak();
        }

        AfterLibInit();
    }

    GameSetting::~GameSetting()
    {
        //ライブラリ終了
        DxLib_End();
    }

    void GameSetting::BeforeLibInit()
    {
        //アンチエイリアスの設定
        SetFullSceneAntiAliasingMode(4, 2);
    }

    void GameSetting::AfterLibInit()
    {
        //描画先を裏画面に設定
        SetDrawScreen(DX_SCREEN_BACK);

        SetBackgroundColor(0, 0, 0);   // 背景色設定
    }
}