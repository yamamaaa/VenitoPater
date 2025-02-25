#include"SceneBase.h"

namespace scene
{
    SceneBase::SceneBase()
        :m_IsChangeScene(false)
        ,m_FadeInSet(false)
    {
        //�����Ȃ�
    }

    SceneBase::~SceneBase()
    {
    }

    void SceneBase::LoadScene()
    {
        //�������I�������t���O���I���ɂ��Č㏈��
        if (transitor::FadeTransitor::IsFadeDone())
        {
            m_FadeInSet = true;
            transitor::FadeTransitor::FadeProcessing();
        }
    }

    void SceneBase::TransitorScene(const float deltatime)
    {
        //�������I�������X�e�[�^�X�̕ύX�ƌ㏈��
        if (transitor::FadeTransitor::IsFadeDone())
        {
            object::ObjectManager::SetNowGameState(object::ObjectManager::GetNextGameState());
            object::ObjectManager::ReleaseAllObj();
            transitor::FadeTransitor::FadeProcessing();
        }
    }

    void SceneBase::TransitorScene(const float deltatime, object::GameStatus scene_1, object::GameStatus scene_2, bool& is_same)
    {
        //�������I�������X�e�[�^�X�̕ύX�ƌ㏈��
        if (transitor::FadeTransitor::IsFadeDone())
        {
            //���̃X�e�[�^�X���擾���Z�b�g
            object::GameStatus status_next = object::ObjectManager::GetNextGameState();
            object::ObjectManager::SetNowGameState(status_next);

            object::ObjectManager::ReleaseAllObj();
            transitor::FadeTransitor::FadeProcessing();

            //���̃V�[���������X�g�[���[�V�[����
            if (scene_1 == status_next || scene_2 == status_next)
            {
                is_same = true;
            }
        }
    }
}