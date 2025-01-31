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

    void SceneBase::TransitorScene(const float deltatime, object::GameStatus scene_1, object::GameStatus scene_2, bool& is_same)
    {
        //処理が終わったらステータスの変更と後処理
        if (transitor::FadeTransitor::IsFadeDone())
        {
            //次のステータスを取得しセット
            object::GameStatus status_next = object::ObjectManager::GetNextGameState();
            object::ObjectManager::SetNowGameState(status_next);

            object::ObjectManager::ReleaseAllObj();
            transitor::FadeTransitor::FadeProcessing();

            //次のシーンが同じストーリーシーンか
            if (scene_1 == status_next || scene_2 == status_next)
            {
                is_same = true;
            }
        }
    }
}