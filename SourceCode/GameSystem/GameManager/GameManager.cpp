#include"GameManager.h"
#include"../Window/Window.h"
#include"../GameSetting/GameSetting.h"
//#include""
//#include""

namespace GameSystem
{
    GameManager::GameManager()
    {
        //Log.txt�𐶐����Ȃ��悤�ɐݒ�
        SetOutApplicationLogValidFlag(false);

        //Window������
        window->Init();
        //GameSetting������
        gamesetting->Init();

        //JsonManager::InitJsonManager();
        //sceneManager.reset(new SceneManager);
    }

    GameManager::~GameManager()
    {
        //�����Ȃ�
    }

    void GameManager::Finalize()
    {
        //sceneManager->GameLoop();
    }
}