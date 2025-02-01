#include "Title.h"

#include "../../Object/ObjectTag/TitleObjectTag.h"

#include"../../LevelController/LevelController.h"
#include"../../LevelController/LevelStatus.h"
#include"../../NumDays/NumDays.h"

#include"../Play/Play.h"
#include"../Story/Story.h"

#include "../../Object/TitleObj/TitleUi/TitleUi.h"
#include "../../Object/TitleObj/SelectMode/SelectMode.h"
#include"../a/a.h"

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

        ////Title��ʂ̑SUi����
        object::ObjectManager::Entry(new object::TitleUi);
        object::ObjectManager::Entry(new object::SelectMode);
    }

    SceneBase* Title::UpdateScene(float deltaTime)
    {
        //object::ObjectManager::ReleaseAllObj();
        //object::ObjectManager::SetNowGameState(object::Score);
        //object::ObjectManager::SetPlayMode(object::PlayMenu::PlayRankingMode);
        //return new PlayEnd();
         //F1�������ꂽ�玞�Ԍo��
        if (CheckHitKey(KEY_INPUT_F1))
        {
            object::ObjectManager::ReleaseAllObj();
            return new a;
        }

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
            TransitorScene(deltaTime);
        }
        else
        {
            object::ObjectManager::UpdateAllObj(deltaTime);
        }

        //�j���[�Q�[��
        if (object::Still == status)
        {
            LevelController::SetLevel(levelStatus.NOMAL);
            return new Story();
        }

        //�����L���O���[�h
        if (object::GamePlay == status)
        {
            LevelController::SetLevel(levelStatus.NOMAL);
            return new Play();
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