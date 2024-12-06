#include<DxLib.h>
#include "GameOver.h"
#include"../../../Transitor/FadeTransitor/FadeTransitor.h"
#include"../../../Object/ObjectManager/ObjectManager.h"
#include"../../../Object/ObjectTag/Result_ObjectTag.h"

#include"../../ThreeDays/ThreeDays.h"
#include"../../Title/Title.h"

#include"../../../Object/Result/BackGround/BackGround.h"
#include"../../../Object/Result/GameOverUi/GameOverUi.h"

namespace scene
{
    GameOver::GameOver()
        :SceneBase()
    {
        SetDrawBright(255, 255, 255);

        object::ObjectManager::SetNowSceneName("gameover");
        object::ObjectManager::NowSceneSet(objecttag::Result_ObjectTagAll);

        object::ObjectManager::Entry(new object::BackGround);
        object::ObjectManager::Entry(new object::GameOverUi);
    }

    GameOver::~GameOver()
    {
        //処理なし
    }

    SceneBase* GameOver::UpdateScene(const float deltaTime)
    {
        object::ObjectManager::UpdateAllObj(deltaTime);

        if (object::Continue==object::ObjectManager::GetGameState())
        {
            object::ObjectManager::ReleaseAllObj();
            return new ThreeDays;
        }

        //ゲームオーバー
        if (object::Title == object::ObjectManager::GetGameState())
        {
            /*if (fade_transitor->IsFadeDone())
            {
                object::ObjectManager::ReleaseAllObj();
                return new Title;
            }*/
        }

        return this;
    }

    void GameOver::DrawScene()
    {
        DrawFormatString(0, 0, GetColor(255, 255, 255), "Result:GameOver");
        object::ObjectManager::DrawAllObj();

        if (object::Title == object::ObjectManager::GetGameState())
        {
            fade_transitor->FadeOutStart(true);
        }
    }
}