#include"SceneBase.h"

namespace scene
{
    SceneBase::SceneBase()
        :fade_transitor (new transitor::FadeTransitor),
        m_FadeInSet(false)
    {
        //�����Ȃ�
    }

    SceneBase::~SceneBase()
    {
        //�������̉��
        delete fade_transitor;
    }

    void SceneBase::LoadScene()
    {
        if (fade_transitor->IsFadeDone())
        {
            m_FadeInSet = true;
            fade_transitor->FadeProcessing();
        }
    }

    void SceneBase::TransitorScene()
    {
        if (fade_transitor->IsFadeDone())
        {
            //�������I�������X�e�[�^�X�̕ύX
            object::ObjectManager::SetNowGameState(object::ObjectManager::GetNextGameState());
            fade_transitor->FadeProcessing();
        }
    }
}