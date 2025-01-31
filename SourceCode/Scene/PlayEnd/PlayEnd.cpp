#include"PlayEnd.h"

#include"../Title/Title.h"

#include"../../Object/ObjectTag/PlayEnd_ObjectTag.h"

#include"../../Object/ScoreDraw/ScoreDraw.h"

namespace scene
{
    PlayEnd::PlayEnd()
        :SceneBase()
    {
        //読み込み関連
        LoadObject();
    }

    PlayEnd::~PlayEnd()
    {
        //処理なし
    }

    void PlayEnd::LoadObject()
    {
        //現在のステータスを確認し読み込みデータを切り替える
        object::GameStatus status = object::ObjectManager::GetNowGameState();

        if (status == object::GameStatus::PlayEnd)
        {
            //object::ObjectManager::SetNowGameState(object::Still);
            //object::ObjectManager::SetNextGameState(object::GameOver);
        }
        else
        {
            object::ObjectManager::NowSceneSet(objecttag::PlayEnd_ObjectTagAll);
            object::ObjectManager::SetNextGameState(object::GameStatus::Score);
            object::ObjectManager::Entry(new object::ScoreDraw);
        }

        //初期化
        m_IsNextSame = false;
    }

    SceneBase* PlayEnd::UpdateScene(const float deltaTime)
    {
        if (!m_FadeInSet)
        {
            transitor::FadeTransitor::FadeInStart(deltaTime);
            LoadScene();
        }

        //現在のステータスを取得
        object::GameStatus status = object::ObjectManager::GetNowGameState();

        //ゲームステータスが変わったらシーン切り替え処理をする
        if (status != object::ObjectManager::GetNextGameState())
        {
            m_IsChangeScene = true;
            transitor::FadeTransitor::FadeOutStart(deltaTime);
            TransitorScene(deltaTime, object::GameStatus::Score, object::GameStatus::PlayEnd, m_IsNextSame);
        }
        else
        {
            object::ObjectManager::UpdateAllObj(deltaTime);
        }

        //タイトルへ戻る
        if (object::Title == status)
        {
            return new Title;
        }

        return this;
    }

    void PlayEnd::DrawScene()
    {
        if (m_IsChangeScene || !m_FadeInSet)
        {
            transitor::FadeTransitor::DrawFade();
        }

        object::ObjectManager::DrawAllObj();
        
        DrawFormatString(0, 0, GetColor(255, 255, 255), "PlayEnd");
    }
}
