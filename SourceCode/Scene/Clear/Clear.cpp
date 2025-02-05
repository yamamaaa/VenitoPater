#include"Clear.h"

#include"../Story/Story.h"
#include"../Movie/Movie.h"

#include"../../Object/ObjectTag/GameClear_ObjectTag.h"

#include"../../Object/Result/BackGround/BackGround.h"
#include"../../Object/Result/GameClearUi/GameClearUi.h"

#include"../../Object/ScoreDraw/ScoreDraw.h"

namespace scene
{
    Clear::Clear()
        :SceneBase()
    {
        //�ǂݍ��݊֘A
        LoadObject();
    }

    Clear::~Clear()
    {
        //�����Ȃ�
    }

    void Clear::LoadObject()
    {
        //���݂̃X�e�[�^�X���m�F���ǂݍ��݃f�[�^��؂�ւ���
        object::GameStatus status = object::ObjectManager::GetNowGameState();
        object::ObjectManager::NowSceneSet(objecttag::GameClear_ObjectTagAll);

        if (status == object::GameStatus::GameClear)
        {
            object::ObjectManager::SetNextGameState(object::GameClear);

            object::ObjectManager::Entry(new object::BackGround);
            object::ObjectManager::Entry(new object::GameClearUi);
        }
        else
        {
            object::ObjectManager::SetNextGameState(object::GameStatus::Score);
            object::ObjectManager::Entry(new object::BackGround);
            object::ObjectManager::Entry(new object::ScoreDraw);
        }

        //������
        m_IsNextSame = false;
    }

    SceneBase* Clear::UpdateScene(const float deltaTime)
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
            TransitorScene(deltaTime, object::GameStatus::Score, object::GameStatus::GameClear, m_IsNextSame);
        }
        else
        {
            object::ObjectManager::UpdateAllObj(deltaTime);
        }

        if (m_IsNextSame)
        {
            return new Clear;
        }

        if (object::Story == status || object::Still == status)
        {
            return new Story;
        }

        if (object::GameStatus::PlayEnd == status)
        {
            return new Movie;
        }

        return this;
    }

    void Clear::DrawScene()
    {
        if (m_IsChangeScene || !m_FadeInSet)
        {
            transitor::FadeTransitor::DrawFade();
        }

        object::ObjectManager::DrawAllObj();

        DrawFormatString(0, 0, GetColor(255, 255, 255), "Clear");
    }
}
