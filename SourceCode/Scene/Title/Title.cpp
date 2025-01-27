#include "Title.h"

#include "../../Object/ObjectTag/TitleObjectTag.h"

#include"../../LevelController/LevelController.h"
#include"../../LevelController/LevelStatus.h"
#include"../../Object/NumDays/NumDays.h"

#include"../ThreeDays/ThreeDays.h"
#include"../Result/Result.h"
#include"../Story/Story.h"

#include "../../Object/TitleObj/TitleUi/TitleUi.h"
#include "../../Object/TitleObj/SelectMode/SelectMode.h"

using namespace level_controller;

namespace scene
{
    Title::Title()
        :SceneBase()
    {
        //�ǂݍ��݊֘A
        LoadObject();
    }

    Title::~Title()
    {
        //�����Ȃ�
    }

    void Title::LoadObject()
    {
        //�I�u�W�F�N�g�^�O���Z�b�g
        object::ObjectManager::NowSceneSet(objecttag::TitleObjectTagAll);
        //Game��Ԃ��Z�b�g
        object::ObjectManager::SetNowGameState(object::Title);
        object::ObjectManager::SetNextGameState(object::Title);

        LevelController::Initialize();
        object::NumDays::Initialize();

        //Title��ʂ̑SUi����
        object::ObjectManager::Entry(new object::TitleUi);
        object::ObjectManager::Entry(new object::SelectMode);
    }

    SceneBase* Title::UpdateScene(float deltaTime)
    {
        if (!m_FadeInSet)
        {
            transitor::FadeTransitor::FadeInStart(deltaTime);
            LoadScene();
        }

        //���݂̃X�e�[�^�X���擾
        object::GameStatus status = object::ObjectManager::GetNowGameState();

        //�Q�[���X�e�[�^�X���ς������V�[���؂�ւ�����������
        if (status != object::ObjectManager::GetNextGameState())
        {
            m_IsChangeScene = true;
            transitor::FadeTransitor::FadeOutStart(deltaTime);
            TransitorScene();
        }
        else
        {
            object::ObjectManager::UpdateAllObj(deltaTime);
        }

        //LevelController::SetLevel(levelStatus.NOMAL);
        //object::ObjectManager::ReleaseAllObj();
        //object::ObjectManager::SetNowGameState(object::GamePlay);
        //object::ObjectManager::SetNowGameState(object::Story);
        //return new Story();

            //LevelController::SetLevel(levelStatus.NOMAL);
            //object::ObjectManager::ReleaseAllObj();
            //object::ObjectManager::SetNowGameState(object::GamePlay);
            //object::ObjectManager::SetPlayMode(object::PlayNewGame);
            //return new ThreeDays();

        //�Q�[���v���C
        if (object::GamePlay == status)
        {
            LevelController::SetLevel(levelStatus.NOMAL);
            object::ObjectManager::SetNowGameState(object::Still);
            return new Story();
        }

        return this;
    }

    void Title::DrawScene()
    {
        DrawFormatString(0, 0, GetColor(255, 255, 255), "title");

        if (m_IsChangeScene || !m_FadeInSet)
        {
            transitor::FadeTransitor::DrawFade();
        }

        object::ObjectManager::DrawAllObj();
    }
}