#include"GameManager.h"
#include"../Window/Window.h"
#include"../GameSetting/GameSetting.h"
//#include""
//#include""

namespace GameSystem
{
    GameManager::GameManager()
    {
        //Log.txt‚ð¶¬‚µ‚È‚¢‚æ‚¤‚ÉÝ’è
        SetOutApplicationLogValidFlag(false);

        //Window‰Šú‰»
        window->Init();
        //GameSetting‰Šú‰»
        gamesetting->Init();

        //JsonManager::InitJsonManager();
        //sceneManager.reset(new SceneManager);
    }

    GameManager::~GameManager()
    {
        //ˆ—‚È‚µ
    }

    void GameManager::Finalize()
    {
        //sceneManager->GameLoop();
    }
}