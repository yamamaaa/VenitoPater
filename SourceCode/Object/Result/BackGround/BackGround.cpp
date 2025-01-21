#include "BackGround.h"
#include "../../ObjectTag/GameOver_ObjectTag.h"
#include "../../ObjectManager/ObjectManager.h"

namespace object
{
    BackGround::BackGround()
        :ObjectBase(gameOver_ObjectTag.BACKGROUND)
    {
        //読み込み関連
        LoadObject();
    }

    BackGround::~BackGround()
    {
        //処理なし
    }

    void BackGround::LoadObject()
    {
        m_ObjPos = { 0,0 };

        if (GameOver == ObjectManager::GetGameState())
        {
            m_ObjHandle = LoadGraph("../Asset/image/result/gameover/background.png");
        }
        if (GameClear == ObjectManager::GetGameState())
        {
            m_ObjHandle = LoadGraph("../Asset/image/result/gameover/background.png");
        }
    }

    void BackGround::DrawObj()
    {
        //画像の表示
        DrawGraph(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), m_ObjHandle, TRUE);
    }
}