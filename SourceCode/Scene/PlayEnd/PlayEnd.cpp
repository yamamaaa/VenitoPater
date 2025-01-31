#include"PlayEnd.h"

#include"../Title/Title.h"

#include"../../Object/ObjectTag/PlayEnd_ObjectTag.h"

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
        //object::ObjectManager::NowSceneSet(objecttag::GameOver_ObjectTagAll);
        //object::ObjectManager::SetNextGameState(object::GameOver);
        //object::ObjectManager::Entry(new object::BackGround);
        //object::ObjectManager::Entry(new object::GameOverUi);
        //object::ObjectManager::Entry(new object::TextDraw);

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
            TransitorScene(deltaTime);
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
