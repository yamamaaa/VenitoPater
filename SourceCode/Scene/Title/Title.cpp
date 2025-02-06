#include "Title.h"

#include "../../Object/ObjectTag/TitleObjectTag.h"
#include "../../Object/ObjectTag/Tutorial_ObjectTag.h"

#include"../../LevelController/LevelController.h"
#include"../../LevelController/LevelStatus.h"
#include"../../NumDays/NumDays.h"

#include"../Play/Play.h"
#include"../Story/Story.h"
#include"../Movie/Movie.h"

#include "../../Object/TitleObj/TitleUi/TitleUi.h"
#include "../../Object/TitleObj/SelectMode/SelectMode.h"
#include"../../Object/Menu/Menu.h"

#include"../../Object/TutorialUi/TutorialUi.h"

using namespace level_controller;

namespace scene
{
    Title::Title()
        :SceneBase()
    {
        //読み込み関連
        LoadObject();
    }

    Title::~Title()
    {
        //処理なし
    }

    void Title::LoadObject()
    {
        if (object::Title == object::ObjectManager::GetNowGameState())
        {
            //オブジェクトタグをセット
            object::ObjectManager::NowSceneSet(objecttag::TitleObjectTagAll);
            //Game状態をセット
            object::ObjectManager::SetNowGameState(object::Title);
            object::ObjectManager::SetNextGameState(object::Title);

            LevelController::Initialize();
            object::NumDays::Initialize();

            //Title画面の全Ui生成
            object::ObjectManager::Entry(new object::TitleUi);
            object::ObjectManager::Entry(new object::SelectMode);
            object::ObjectManager::Entry(new object::Menu);
        }
        else
        {
            //オブジェクトタグをセット
            object::ObjectManager::NowSceneSet(objecttag::Tutorial_ObjectTagAll);
            //Game状態をセット
            object::ObjectManager::SetNowGameState(object::Tutorial);
            object::ObjectManager::SetNextGameState(object::Tutorial);

            object::ObjectManager::Entry(new object::TutorialUi);
        }
        //初期化
        m_IsNextSame = false;
        m_Change_Count = m_COUNT_MAX;
    }

    SceneBase* Title::UpdateScene(float deltaTime)
    {
        //object::ObjectManager::SetNextGameState(object::PlayEnd);
        //object::ObjectManager::SetPlayMode(object::PlayNewGame);
        //object::ObjectManager::ReleaseAllObj();
        //transitor::FadeTransitor::FadeProcessing();

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
            TransitorScene(deltaTime, object::GameStatus::Title, object::GameStatus::Tutorial, m_IsNextSame);
        }
        else
        {
            m_Change_Count -= m_COUNT_DECREMENT* deltaTime;

            if (m_Change_Count <= 0.0f)
            {
                object::ObjectManager::SetNextGameState(object::GameStatus::Standby);
            }

            object::ObjectManager::UpdateAllObj(deltaTime);
        }

        //待機モードかプレイ終了
        if (object::Standby == status || object::GameStatus::PlayEnd == status)
        {
            return new Movie();
        }

        //ニューゲーム
        if (object::Still == status)
        {
            LevelController::SetLevel(levelStatus.NOMAL);
            return new Story();
            /*return new Movie();*/
        }

        //ランキングモード
        if (object::GamePlay == status)
        {
            LevelController::SetLevel(levelStatus.NOMAL);
            return new Play();
        }

        //チュートリアル、タイトル
        if (m_IsNextSame)
        {
            return new Title();
        }

        return this;
    }

    void Title::DrawScene()
    {
        if (m_IsChangeScene || !m_FadeInSet)
        {
            transitor::FadeTransitor::DrawFade();
        }

        object::ObjectManager::DrawAllObj();

#if DEBUG
        DrawString(0, 0, "title", GetColor(255, 255, 255));
        DrawFormatString(0, 0, GetColor(255, 255, 255), "切り替わりまで:%f", m_Change_Count);
#endif
    }
}