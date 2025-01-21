#include "BackGround.h"
#include "../../ObjectTag/GameOver_ObjectTag.h"
#include "../../ObjectManager/ObjectManager.h"

namespace object
{
    BackGround::BackGround()
        :ObjectBase(gameOver_ObjectTag.BACKGROUND)
    {
        //ì«Ç›çûÇ›ä÷òA
        LoadObject();
    }

    BackGround::~BackGround()
    {
        //èàóùÇ»Çµ
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
        //âÊëúÇÃï\é¶
        DrawGraph(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), m_ObjHandle, TRUE);
    }
}