#include "Result.h"

#include"../ThreeDays/ThreeDays.h"
#include"../Title/Title.h"

#include"../../Object/ObjectTag/GameOver_ObjectTag.h"

#include"../../Object/Result/BackGround/BackGround.h"
#include"../../Object/Result/GameOverUi/GameOverUi.h"

#include"../../Object/ObjectTag/GameClear_ObjectTag.h"

#include"../../Object/Result/BackGround/BackGround.h"
#include"../../Object/Result/GameClearUi/GameClearUi.h"

namespace scene
{
    Result::Result()
        :SceneBase()
    {
        //�ǂݍ��݊֘A
        LoadObject();
    }

    Result::~Result()
    {
        //�����Ȃ�
    }

    void Result::LoadObject()
    {
        //Game��Ԃ��Z�b�g

        if (object::ObjectManager::GetNowGameState() == object::GameOver)
        {
            object::ObjectManager::NowSceneSet(objecttag::GameOver_ObjectTagAll);
            object::ObjectManager::SetNextGameState(object::GameOver);

            object::ObjectManager::Entry(new object::BackGround);
            object::ObjectManager::Entry(new object::GameOverUi);
        }
        else if (object::ObjectManager::GetNowGameState() == object::GameClear)
        {
            object::ObjectManager::NowSceneSet(objecttag::GameClear_ObjectTagAll);
            object::ObjectManager::SetNextGameState(object::GameClear);

            object::ObjectManager::Entry(new object::BackGround);
            object::ObjectManager::Entry(new object::GameClearUi);
        }

        //�t�F�[�h�t���O������
        m_FadeInSet = false;
    }

    SceneBase* Result::UpdateScene(const float deltaTime)
    {
        object::ObjectManager::UpdateAllObj(deltaTime);

        //�R���e�j���[
        if (object::Continue == object::ObjectManager::GetNowGameState()|| object::GamePlay == object::ObjectManager::GetNowGameState())
        {
            object::ObjectManager::ReleaseAllObj();
            return new ThreeDays;
        }

        //�Q�[���I�[�o�[
        if (object::Title == object::ObjectManager::GetNowGameState())
        {
            object::ObjectManager::ReleaseAllObj();
            return new Title;
        }

        return this;
    }

    void Result::DrawScene()
    {
        DrawFormatString(0, 0, GetColor(255, 255, 255), "Result");

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