#include"GameManager.h"
#include "../Window/Window.h"
#include "../GameSetting/GameSetting.h"
#include "../../JsonMaster/JsonManager/JsonManager.h"

namespace GameSystem
{
    GameManager::GameManager()
        :window(nullptr),
        gamesetting(nullptr)
    {
        //Log.txt�𐶐����Ȃ��悤�ɐݒ�
        SetOutApplicationLogValidFlag(false);

        //Window������
        window->Init();
        //GameSetting������
        gamesetting->Init();

        jsonmaster::JsonManager::InitJsonManager();

        //SceneManager�̃C���X�^���X��
        sceneManager.reset(new scene::SceneManager);
    }

    GameManager::~GameManager()
    {
        //�������̉��
        delete window;
        delete gamesetting;
    }

    void GameManager::Finalize()
    {
        sceneManager->GameLoop();
    }
}