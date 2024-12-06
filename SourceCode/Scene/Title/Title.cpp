#include<DxLib.h>

#include "Title.h"
#include"../ThreeDays/ThreeDays.h"
#include"../Result/GameOver/GameOver.h"
#include"../../LevelController/LevelController.h"
#include"../../LevelController/LevelStatus.h"

using namespace level_controller;

namespace scene
{
    Title::Title()
        :SceneBase()
    {
        LevelController::Initialize();
    }

    Title::~Title()
    {
        //処理なし
    }

    SceneBase* Title::UpdateScene(float deltaTime)
    {
        ////シーン切り替え
        //if (CheckHitKey(KEY_INPUT_SPACE))
        //{
        //    //プレイ中に切り替え
        //    return new ThreeDays;
        //}

        //プレイ中に切り替え
        LevelController::SetLevel(levelStatus.NOMAL);
        return new ThreeDays();

        //return new GameOver();

        //F1が押されたらノーマルモード
        if (CheckHitKey(KEY_INPUT_F1))
        {
            //プレイ中に切り替え
            LevelController::SetLevel(levelStatus.NOMAL);
            return new ThreeDays();
        }
        //F2が押されたらハードモード
        else if (CheckHitKey(KEY_INPUT_F2))
        {
            //プレイ中に切り替え
            LevelController::SetLevel(levelStatus.HARD);
            return new ThreeDays();
        }

        return this;
    }

    void Title::DrawScene()
    {
        DrawFormatString(0, 0, GetColor(255, 255, 255), "title");
        //タイトルロゴ表示
    }
}