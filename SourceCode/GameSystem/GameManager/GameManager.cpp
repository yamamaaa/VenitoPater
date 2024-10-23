#include"GameManager.h"
#include"../Window/Window.h"
#include"../GameSetting/GameSetting.h"
//#include""
//#include""

namespace GameSystem
{
    GameManager::GameManager()
    {
        //Log.txtを生成しないように設定
        SetOutApplicationLogValidFlag(false);

        //Window初期化
        window->Init();
        //GameSetting初期化
        gamesetting->Init();

        //JsonManager::InitJsonManager();
        //sceneManager.reset(new SceneManager);
    }

    GameManager::~GameManager()
    {
        //処理なし
    }

    void GameManager::Finalize()
    {
        //sceneManager->GameLoop();
    }
}