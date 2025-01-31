#include "Result.h"

#include"../ThreeDays/ThreeDays.h"
#include"../Title/Title.h"
#include"../Story/Story.h"
#include"../PlayEnd/PlayEnd.h"

#include"../../Object/ObjectTag/GameOver_ObjectTag.h"

#include"../../Object/Result/BackGround/BackGround.h"
#include"../../Object/Result/GameOverUi/GameOverUi.h"
#include"../../Object/TextDraw/TextDraw.h"

#include"../../Object/ObjectTag/GameClear_ObjectTag.h"

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
            object::ObjectManager::Entry(new object::TextDraw);
        }
        else if (object::ObjectManager::GetNowGameState() == object::TimeOver)
        {
            object::ObjectManager::NowSceneSet(objecttag::GameOver_ObjectTagAll);
            object::ObjectManager::SetNextGameState(object::TimeOver);

            object::ObjectManager::Entry(new object::BackGround);
            object::ObjectManager::Entry(new object::GameOverUi);
            object::ObjectManager::Entry(new object::TextDraw);
        }
        else if (object::ObjectManager::GetNowGameState() == object::GameClear)
        {
            object::ObjectManager::NowSceneSet(objecttag::GameClear_ObjectTagAll);
            object::ObjectManager::SetNextGameState(object::GameClear);

            object::ObjectManager::Entry(new object::BackGround);
            object::ObjectManager::Entry(new object::GameClearUi);
        }
    }

    SceneBase* Result::UpdateScene(const float deltaTime)
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
            TransitorScene(deltaTime);
        }
        else
        {
            object::ObjectManager::UpdateAllObj(deltaTime);
        }

        //�R���e�j���[
        if (object::GamePlay == status)
        {
            return new ThreeDays;
        }

        //�^�C�g���֖߂�
        if (object::Title == status)
        {
            return new Title;
        }

        //�Q�[���N���A������
        if (object::Story == status || object::Still == status)
        {
            return new Story;
        }
        if (object::Score == status)
        {
            return new PlayEnd;
        }

        return this;
    }

    void Result::DrawScene()
    {
        DrawFormatString(0, 0, GetColor(255, 255, 255), "Result");

        if (m_IsChangeScene || !m_FadeInSet)
        {
            transitor::FadeTransitor::DrawFade();
        }

        object::ObjectManager::DrawAllObj();
    }
}