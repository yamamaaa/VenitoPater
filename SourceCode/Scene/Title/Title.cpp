#include "Title.h"

#include "../../Object/ObjectTag/TitleObjectTag.h"
#include "../../Object/ObjectTag/Tutorial_ObjectTag.h"

#include"../../LevelController/LevelController.h"
#include"../../LevelController/LevelStatus.h"
#include"../../NumDays/NumDays.h"

#include"../Play/Play.h"
#include"../Story/Story.h"
#include"../Movie/Movie.h"

#include "../../Object/TitleObj/TitleUi/TitleUi.h"
#include "../../Object/TitleObj/SelectMode/SelectMode.h"
#include"../../Object/Menu/Menu.h"

#include"../../Object/TutorialUi/TutorialUi.h"

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
        if (object::Title == object::ObjectManager::GetNowGameState())
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
            object::ObjectManager::Entry(new object::Menu);
        }
        else
        {
            //�I�u�W�F�N�g�^�O���Z�b�g
            object::ObjectManager::NowSceneSet(objecttag::Tutorial_ObjectTagAll);
            //Game��Ԃ��Z�b�g
            object::ObjectManager::SetNowGameState(object::Tutorial);
            object::ObjectManager::SetNextGameState(object::Tutorial);

            object::ObjectManager::Entry(new object::TutorialUi);
        }
        //������
        m_IsNextSame = false;
        m_Change_Count = m_COUNT_MAX;
    }

    SceneBase* Title::UpdateScene(float deltaTime)
    {
        //object::ObjectManager::SetNextGameState(object::PlayEnd);
        //object::ObjectManager::SetPlayMode(object::PlayNewGame);
        //object::ObjectManager::ReleaseAllObj();
        //transitor::FadeTransitor::FadeProcessing();

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
            TransitorScene(deltaTime, object::GameStatus::Title, object::GameStatus::Tutorial, m_IsNextSame);
        }
        else
        {
            m_Change_Count -= m_COUNT_DECREMENT* deltaTime;

            if (m_Change_Count <= 0.0f)
            {
                object::ObjectManager::SetNextGameState(object::GameStatus::Standby);
            }

            object::ObjectManager::UpdateAllObj(deltaTime);
        }

        //�ҋ@���[�h���v���C�I��
        if (object::Standby == status || object::GameStatus::PlayEnd == status)
        {
            return new Movie();
        }

        //�j���[�Q�[��
        if (object::Still == status)
        {
            LevelController::SetLevel(levelStatus.NOMAL);
            return new Story();
            /*return new Movie();*/
        }

        //�����L���O���[�h
        if (object::GamePlay == status)
        {
            LevelController::SetLevel(levelStatus.NOMAL);
            return new Play();
        }

        //�`���[�g���A���A�^�C�g��
        if (m_IsNextSame)
        {
            return new Title();
        }

        return this;
    }

    void Title::DrawScene()
    {
        if (m_IsChangeScene || !m_FadeInSet)
        {
            transitor::FadeTransitor::DrawFade();
        }

        object::ObjectManager::DrawAllObj();

#if DEBUG
        DrawString(0, 0, "title", GetColor(255, 255, 255));
        DrawFormatString(0, 0, GetColor(255, 255, 255), "�؂�ւ��܂�:%f", m_Change_Count);
#endif
    }
}