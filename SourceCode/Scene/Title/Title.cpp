#include "Title.h"

#include "../../Object/ObjectTag/TitleObjectTag.h"

#include"../../LevelController/LevelController.h"
#include"../../LevelController/LevelStatus.h"
#include"../../Object/NumDeys/NumDeys.h"

#include"../ThreeDays/ThreeDays.h"
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
        object::NumDeys::Initialize();

        //Title��ʂ̑SUi����
        object::ObjectManager::Entry(new object::TitleUi);
        object::ObjectManager::Entry(new object::SelectMode);

        m_FadeInSet = false;
    }

    SceneBase* Title::UpdateScene(float deltaTime)
    {
        object::ObjectManager::UpdateAllObj(deltaTime);

        ////F1�������ꂽ��m�[�}�����[�h
        //if (CheckHitKey(KEY_INPUT_F1))
        //{
        //    //�v���C���ɐ؂�ւ�
        //    LevelController::SetLevel(levelStatus.NOMAL);
        //    return new ThreeDays();
        //}

        ////F2�������ꂽ��n�[�h���[�h
        //else if (CheckHitKey(KEY_INPUT_F2))
        //{
        //    //�v���C���ɐ؂�ւ�
        //    LevelController::SetLevel(levelStatus.HARD);
        //    return new ThreeDays();
        //}

        //LevelController::SetLevel(levelStatus.NOMAL);
        //object::ObjectManager::ReleaseAllObj();
        //return new ThreeDays();

        //LevelController::SetLevel(levelStatus.NOMAL);
        //object::ObjectManager::ReleaseAllObj();
        //object::ObjectManager::SetNowGameState(object::Still);
        //return new Story();

            LevelController::SetLevel(levelStatus.NOMAL);
            object::ObjectManager::ReleaseAllObj();
            object::ObjectManager::SetNowGameState(object::Still);
            return new Story();
        //�Q�[���v���C
        if (object::GamePlay == object::ObjectManager::GetNowGameState())
        {
        }

        return this;
    }

    void Title::DrawScene()
    {
        DrawFormatString(0, 0, GetColor(255, 255, 255), "title");

        //�Q�[���X�e�[�^�X���ς������
        if (object::ObjectManager::GetNowGameState() != object::ObjectManager::GetNextGameState())
        {
            //�t�F�[�h����������
            fade_transitor->FadeOutStart(true);
            TransitorScene();
        }

        if (!m_FadeInSet)
        {
            //�t�F�[�h�C��
            fade_transitor->FadeInStart(false);
            LoadScene();
        }

        object::ObjectManager::DrawAllObj();
    }
}