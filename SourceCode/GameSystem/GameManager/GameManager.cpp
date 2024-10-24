#include"GameManager.h"
#include"../Window/Window.h"
#include"../GameSetting/GameSetting.h"
#include"../../Scene/SceneManager/SceneManager.h"
//#include""
//#include""

namespace GameSystem
{
    GameManager::GameManager()
        :window(nullptr),
        gamesetting(nullptr)
    {
        //Log.txtを生成しないように設定
        SetOutApplicationLogValidFlag(false);

        //Window初期化
        window->Init();
        //GameSetting初期化
        gamesetting->Init();

        //JsonManager::InitJsonManager();

        //SceneManagerのインスタンス化
        sceneManager.reset(new scene::SceneManager);
    }

    GameManager::~GameManager()
    {
        //メモリの解放
        delete window;
        delete gamesetting;
    }

    void GameManager::Finalize()
    {
        sceneManager->GameLoop();
    }
}