#include "Title.h"

#include "../../Object/ObjectTag/TitleObjectTag.h"

#include"../../LevelController/LevelController.h"
#include"../../LevelController/LevelStatus.h"
#include"../../Object/NumDays/NumDays.h"

#include"../ThreeDays/ThreeDays.h"
#include"../Result/Result.h"
#include"../Story/Story.h"

#include "../../Object/TitleObj/TitleUi/TitleUi.h"
#include "../../Object/TitleObj/SelectMode/SelectMode.h"

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

        //Title画面の全Ui生成
        object::ObjectManager::Entry(new object::TitleUi);
        object::ObjectManager::Entry(new object::SelectMode);
    }

    SceneBase* Title::UpdateScene(float deltaTime)
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
            TransitorScene();
        }
        else
        {
            object::ObjectManager::UpdateAllObj(deltaTime);
        }

        //LevelController::SetLevel(levelStatus.NOMAL);
        //object::ObjectManager::ReleaseAllObj();
        //object::ObjectManager::SetNowGameState(object::GamePlay);
        //object::ObjectManager::SetNowGameState(object::Story);
        //return new Story();

            //LevelController::SetLevel(levelStatus.NOMAL);
            //object::ObjectManager::ReleaseAllObj();
            //object::ObjectManager::SetNowGameState(object::GamePlay);
            //object::ObjectManager::SetPlayMode(object::PlayNewGame);
            //return new ThreeDays();

        //ゲームプレイ
        if (object::GamePlay == status)
        {
            LevelController::SetLevel(levelStatus.NOMAL);
            object::ObjectManager::SetNowGameState(object::Still);
            return new Story();
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