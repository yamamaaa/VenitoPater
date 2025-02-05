#include"Movie.h"

#include"../Title/Title.h"

#include"../../Object/ObjectTag/PlayEnd_ObjectTag.h"

namespace scene
{
    Movie::Movie()
        :SceneBase()
    {
        //�ǂݍ��݊֘A
        LoadObject();
    }

    Movie::~Movie()
    {
        //�����Ȃ�
    }

    void Movie::LoadObject()
    {
        //���݂̃X�e�[�^�X���擾
        object::GameStatus status = object::ObjectManager::GetNowGameState();

        if (object::GameStatus::GameEnd == object::ObjectManager::GetNowGameState())
        {
            object::PlayMenu menu = object::ObjectManager::GetPlayMode();
            if (object::PlayMenu::PlayNewGame == menu)
            {
                m_MovieFile = "../Asset/movie/ending.mp4";
            }
            else
            {

            }
        }
        else
        {
            m_MovieFile = "../Asset/movie/ending.mp4";
        }
    }

    SceneBase* Movie::UpdateScene(const float deltaTime)
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

        //�^�C�g���֖߂�
        if (object::Title == status)
        {
            return new Title;
        }

        return this;
    }

    void Movie::DrawScene()
    {
        if (m_IsChangeScene || !m_FadeInSet)
        {
            transitor::FadeTransitor::DrawFade();
        }
        else
        {
            //���݂̃X�e�[�^�X���擾
            object::GameStatus status = object::ObjectManager::GetNowGameState();
            if (object::GameStatus::Standby)
            {
                PlayMovie(m_MovieFile.c_str(), 1, DX_MOVIEPLAYTYPE_BCANCEL);

                //���{�^�����N���b�N���ꂽ��^�C�g����
                if ((GetMouseInput() & MOUSE_INPUT_LEFT))
                {
                    object::ObjectManager::SetNextGameState(object::GameStatus::Title);
                }
            }
            else
            {
                PlayMovie(m_MovieFile.c_str(), 1, DX_MOVIEPLAYTYPE_NORMAL);
                object::ObjectManager::SetNextGameState(object::GameStatus::Title);
            }
        }
   
        DrawFormatString(0, 0, GetColor(255, 255, 255), "Movie");
    }
}
