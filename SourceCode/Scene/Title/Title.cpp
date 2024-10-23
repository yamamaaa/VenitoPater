#include<DxLib.h>

#include "Title.h"
#include"../ThreeDays/ThreeDays.h"

namespace scene
{
    Title::Title()
        :SceneBase()
    {
        //処理なし
    }

    Title::~Title()
    {
        //処理なし
    }

    SceneBase* Title::UpdateScene(float deltaTime)
    {
        //シーン切り替え
        if (CheckHitKey(KEY_INPUT_SPACE))
        {
            //プレイ中に切り替え
            return new ThreeDays;
        }
        return this;
    }

    void Title::DrawScene()
    {
        DrawFormatString(0, 0, GetColor(255, 255, 255), "title");
        //タイトルロゴ表示
    }
}