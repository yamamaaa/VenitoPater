#include "Result.h"

#include"../ThreeDays/ThreeDays.h"
#include"../Title/Title.h"

#include"../../Object/ObjectTag/GameOver_ObjectTag.h"

#include"../../Object/Result/BackGround/BackGround.h"
#include"../../Object/Result/GameOverUi/GameOverUi.h"

#include"../../Object/ObjectTag/GameClear_ObjectTag.h"

#include"../../Object/Result/BackGround/BackGround.h"
#include"../../Object/Result/GameClearUi/GameClearUi.h"

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

        if (m_NowGameStatus == object::GameOver) 
        {
            object::ObjectManager::NowSceneSet(objecttag::GameOver_ObjectTagAll);
            object::ObjectManager::SetGameState(m_NowGameStatus);

            object::ObjectManager::Entry(new object::BackGround);
            object::ObjectManager::Entry(new object::GameOverUi);
        }
        else if (m_NowGameStatus == object::GameClear)
        {
            object::ObjectManager::NowSceneSet(objecttag::GameClear_ObjectTagAll);
            object::ObjectManager::SetGameState(m_NowGameStatus);

            object::ObjectManager::Entry(new object::BackGround);
            object::ObjectManager::Entry(new object::GameClearUi);
        }
    }

    SceneBase* Result::UpdateScene(const float deltaTime)
    {
        object::ObjectManager::UpdateAllObj(deltaTime);

        //コンテニュー
        if (object::Continue == m_NowGameStatus)
        {
            object::ObjectManager::ReleaseAllObj();
            return new ThreeDays;
        }

        //ゲームオーバー
        if (object::Title == m_NowGameStatus)
        {
            object::ObjectManager::ReleaseAllObj();
            return new Title;
        }

        //クリア後
        if (object::GamePlay == m_NowGameStatus)
        {
            object::ObjectManager::ReleaseAllObj();
            return new ThreeDays;	//仮置き
        }

        return this;
    }

    void Result::DrawScene()
    {
        DrawFormatString(0, 0, GetColor(255, 255, 255), "Result");

        //ゲームステータスが変わったら
        if (m_NowGameStatus != object::ObjectManager::GetGameState())
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