#include "Title.h"

#include "../../Object/ObjectTag/TitleObjectTag.h"

#include"../../LevelController/LevelController.h"
#include"../../LevelController/LevelStatus.h"
#include"../../Object/NumDeys/NumDeys.h"

#include"../ThreeDays/ThreeDays.h"
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
        object::NumDeys::Initialize();

        //Title画面の全Ui生成
        object::ObjectManager::Entry(new object::TitleUi);
        object::ObjectManager::Entry(new object::SelectMode);

        m_FadeInSet = false;
    }

    SceneBase* Title::UpdateScene(float deltaTime)
    {
        object::ObjectManager::UpdateAllObj(deltaTime);

        ////F1が押されたらノーマルモード
        //if (CheckHitKey(KEY_INPUT_F1))
        //{
        //    //プレイ中に切り替え
        //    LevelController::SetLevel(levelStatus.NOMAL);
        //    return new ThreeDays();
        //}

        ////F2が押されたらハードモード
        //else if (CheckHitKey(KEY_INPUT_F2))
        //{
        //    //プレイ中に切り替え
        //    LevelController::SetLevel(levelStatus.HARD);
        //    return new ThreeDays();
        //}

        //LevelController::SetLevel(levelStatus.NOMAL);
        //object::ObjectManager::ReleaseAllObj();
        //return new ThreeDays();

        //LevelController::SetLevel(levelStatus.NOMAL);
        //object::ObjectManager::ReleaseAllObj();
        //object::ObjectManager::SetNowGameState(object::Still);
        //return new Story();

            LevelController::SetLevel(levelStatus.NOMAL);
            object::ObjectManager::ReleaseAllObj();
            object::ObjectManager::SetNowGameState(object::Still);
            return new Story();
        //ゲームプレイ
        if (object::GamePlay == object::ObjectManager::GetNowGameState())
        {
        }

        return this;
    }

    void Title::DrawScene()
    {
        DrawFormatString(0, 0, GetColor(255, 255, 255), "title");

        //ゲームステータスが変わったら
        if (object::ObjectManager::GetNowGameState() != object::ObjectManager::GetNextGameState())
        {
            //フェード処理をする
            fade_transitor->FadeOutStart(true);
            TransitorScene();
        }

        if (!m_FadeInSet)
        {
            //フェードイン
            fade_transitor->FadeInStart(false);
            LoadScene();
        }

        object::ObjectManager::DrawAllObj();
    }
}