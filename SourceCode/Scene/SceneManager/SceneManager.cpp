#include "SceneManager.h"
#include"../../Scene/SceneBase/SceneBase.h"
#include"../Title/Title.h"
#include"../../Fps/Fps.h"
#include"../../Object/ObjectManager/ObjectManager.h"

using namespace object;

namespace scene
{
    SceneManager::SceneManager()
        :m_HoldScene(nullptr)
        , fps(new fps::Fps)
    {
        //初期化処理
        ObjectManager::Initialize();
        //AssetManager::InitAssetManager(); インスタンス生成

        //現在のシーンをタイトルに設定
        m_NowScene.emplace(new Title);

        //マウスの表示設定
        SetMouseDispFlag(TRUE);
    }

    SceneManager::~SceneManager()
    {
        //処理なし
    }

    void SceneManager::GameLoop()
    {
        // エスケープキーが押されるかウインドウが閉じられるまでループ
        while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
        {
            //シーンのフロー
            UpdateScene();    //更新処理
            ChangeScene();    //切り替え処理
            DrawScene();      //描画処理
        }
    }

    void SceneManager::UpdateScene()
    {
        //現在のシーンを更新してmHoldSceneに代入
        fps->Update();
        m_HoldScene = m_NowScene.top()->UpdateScene(fps->GetDeltaTime());
    }

    void SceneManager::DrawScene()
    {
        ClearDrawScreen();					// 画面をクリア
        m_NowScene.top()->DrawScene();		// 次のシーンを表示
        ScreenFlip();						// 裏画面の内容を表画面に反映
    }

    void SceneManager::ChangeScene()
    {
        // 次のシーンが同じではなかったら
        if (m_NowScene.top().get() != m_HoldScene)
        {
            //現在のシーンを削除し、次のシーンに切り替え
            m_NowScene.pop();
            m_NowScene.emplace(m_HoldScene);
        }
    }
}

