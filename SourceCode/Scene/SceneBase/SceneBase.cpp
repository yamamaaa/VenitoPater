#include"SceneBase.h"

namespace scene
{
    SceneBase::SceneBase()
        :m_IsChangeScene(false)
        ,m_FadeInSet(false)
    {
        //処理なし
    }

    SceneBase::~SceneBase()
    {
    }

    void SceneBase::LoadScene()
    {
        //処理が終わったらフラグをオンにして後処理
        if (transitor::FadeTransitor::IsFadeDone())
        {
            m_FadeInSet = true;
            transitor::FadeTransitor::FadeProcessing();
        }
    }

    void SceneBase::TransitorScene(const float deltatime)
    {
        //処理が終わったらステータスの変更と後処理
        if (transitor::FadeTransitor::IsFadeDone())
        {
            object::ObjectManager::SetNowGameState(object::ObjectManager::GetNextGameState());
            object::ObjectManager::ReleaseAllObj();
            transitor::FadeTransitor::FadeProcessing();
        }
    }
}