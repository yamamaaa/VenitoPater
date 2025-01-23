#include"SceneBase.h"

namespace scene
{
    SceneBase::SceneBase()
        :fade_transitor (new transitor::FadeTransitor),
        m_FadeInSet(false)
    {
        //処理なし
    }

    SceneBase::~SceneBase()
    {
        //メモリの解放
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
            //処理が終わったらステータスの変更
            object::ObjectManager::SetNowGameState(object::ObjectManager::GetNextGameState());
            fade_transitor->FadeProcessing();
        }
    }
}