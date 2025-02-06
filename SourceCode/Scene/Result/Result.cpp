#include "Result.h"

#include"../Play/Play.h"
#include"../Title/Title.h"

#include"../../Object/ObjectTag/GameOver_ObjectTag.h"

#include"../../Object/Result/BackGround/BackGround.h"
#include"../../Object/Result/GameOverUi/GameOverUi.h"
#include"../../Object/TextDraw/TextDraw.h"

namespace scene
{
    Result::Result()
        :SceneBase()
    {
        //読み込み関連
        LoadObject();
    }

    Result::~Result()
    {
        //処理なし
    }

    void Result::LoadObject()
    {
        //Game状態をセット
        object::ObjectManager::NowSceneSet(objecttag::GameOver_ObjectTagAll);

        if (object::ObjectManager::GetNowGameState() == object::GameOver)
        {
            object::ObjectManager::SetNextGameState(object::GameOver);
        }
        else if (object::ObjectManager::GetNowGameState() == object::TimeOver)
        {
            object::ObjectManager::SetNextGameState(object::TimeOver);
        }

        object::ObjectManager::Entry(new object::BackGround);
        object::ObjectManager::Entry(new object::GameOverUi);
        object::ObjectManager::Entry(new object::TextDraw);
    }

    SceneBase* Result::UpdateScene(const float deltaTime)
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

        //コンテニュー
        if (object::GamePlay == status)
        {
            object::ObjectManager::ReleaseAllObj();
            return new Play;
        }

        //タイトルへ戻る
        if (object::Title == status)
        {
            return new Title;
        }

        return this;
    }

    void Result::DrawScene()
    {
        if (m_IsChangeScene || !m_FadeInSet)
        {
            transitor::FadeTransitor::DrawFade();
        }

        object::ObjectManager::DrawAllObj();

#if DEBUG
        DrawString(0, 0, "Result", GetColor(255, 255, 255));
#endif // DEBUG
    }
}