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
}