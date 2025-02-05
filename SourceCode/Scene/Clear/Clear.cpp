#include"Clear.h"

#include"../Story/Story.h"
#include"../Movie/Movie.h"

#include"../../Object/ObjectTag/GameClear_ObjectTag.h"

#include"../../Object/Result/BackGround/BackGround.h"
#include"../../Object/Result/GameClearUi/GameClearUi.h"

#include"../../Object/ScoreDraw/ScoreDraw.h"

namespace scene
{
    Clear::Clear()
        :SceneBase()
    {
        //読み込み関連
        LoadObject();
    }

    Clear::~Clear()
    {
        //処理なし
    }

    void Clear::LoadObject()
    {
        //現在のステータスを確認し読み込みデータを切り替える
        object::GameStatus status = object::ObjectManager::GetNowGameState();
        object::ObjectManager::NowSceneSet(objecttag::GameClear_ObjectTagAll);

        if (status == object::GameStatus::GameClear)
        {
            object::ObjectManager::SetNextGameState(object::GameClear);

            object::ObjectManager::Entry(new object::BackGround);
            object::ObjectManager::Entry(new object::GameClearUi);
        }
        else
        {
            object::ObjectManager::SetNextGameState(object::GameStatus::Score);
            object::ObjectManager::Entry(new object::BackGround);
            object::ObjectManager::Entry(new object::ScoreDraw);
        }

        //初期化
        m_IsNextSame = false;
    }

    SceneBase* Clear::UpdateScene(const float deltaTime)
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
            TransitorScene(deltaTime, object::GameStatus::Score, object::GameStatus::GameClear, m_IsNextSame);
        }
        else
        {
            object::ObjectManager::UpdateAllObj(deltaTime);
        }

        if (m_IsNextSame)
        {
            return new Clear;
        }

        if (object::Story == status || object::Still == status)
        {
            return new Story;
        }

        if (object::GameStatus::PlayEnd == status)
        {
            return new Movie;
        }

        return this;
    }

    void Clear::DrawScene()
    {
        if (m_IsChangeScene || !m_FadeInSet)
        {
            transitor::FadeTransitor::DrawFade();
        }

        object::ObjectManager::DrawAllObj();

        DrawFormatString(0, 0, GetColor(255, 255, 255), "Clear");
    }
}
