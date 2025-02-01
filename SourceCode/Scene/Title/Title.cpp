#include "Title.h"

#include "../../Object/ObjectTag/TitleObjectTag.h"

#include"../../LevelController/LevelController.h"
#include"../../LevelController/LevelStatus.h"
#include"../../NumDays/NumDays.h"

#include"../Play/Play.h"
#include"../Story/Story.h"

#include "../../Object/TitleObj/TitleUi/TitleUi.h"
#include "../../Object/TitleObj/SelectMode/SelectMode.h"
#include"../a/a.h"

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
        //オブジェクトタグをセット
        object::ObjectManager::NowSceneSet(objecttag::TitleObjectTagAll);
        //Game状態をセット
        object::ObjectManager::SetNowGameState(object::Title);
        object::ObjectManager::SetNextGameState(object::Title);

        LevelController::Initialize();
        object::NumDays::Initialize();

        ////Title画面の全Ui生成
        object::ObjectManager::Entry(new object::TitleUi);
        object::ObjectManager::Entry(new object::SelectMode);
    }

    SceneBase* Title::UpdateScene(float deltaTime)
    {
        //object::ObjectManager::ReleaseAllObj();
        //object::ObjectManager::SetNowGameState(object::Score);
        //object::ObjectManager::SetPlayMode(object::PlayMenu::PlayRankingMode);
        //return new PlayEnd();
         //F1が押されたら時間経過
        if (CheckHitKey(KEY_INPUT_F1))
        {
            object::ObjectManager::ReleaseAllObj();
            return new a;
        }

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

        //ニューゲーム
        if (object::Still == status)
        {
            LevelController::SetLevel(levelStatus.NOMAL);
            return new Story();
        }

        //ランキングモード
        if (object::GamePlay == status)
        {
            LevelController::SetLevel(levelStatus.NOMAL);
            return new Play();
        }

        return this;
    }

    void Title::DrawScene()
    {
        DrawFormatString(0, 0, GetColor(255, 255, 255), "title");

        if (m_IsChangeScene || !m_FadeInSet)
        {
            transitor::FadeTransitor::DrawFade();
        }

        object::ObjectManager::DrawAllObj();
    }
}