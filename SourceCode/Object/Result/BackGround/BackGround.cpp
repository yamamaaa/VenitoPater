#include "BackGround.h"
#include "../../ObjectTag/GameOver_ObjectTag.h"
#include "../../ObjectManager/ObjectManager.h"

namespace object
{
    BackGround::BackGround()
        :ObjectBase(gameOver_ObjectTag.BACKGROUND)
    {
        //“Ç‚Ýž‚ÝŠÖ˜A
        LoadObject();
    }

    BackGround::~BackGround()
    {
        //ˆ—‚È‚µ
    }

    void BackGround::LoadObject()
    {
        m_ObjPos = { 0,0 };

        if (GameOver == ObjectManager::GetGameState())
        {
            m_ObjHandle = LoadGraph(JsonManager::ImgData_Instance()->Get_ResultData_Instance()->GetOverData_BackGround().c_str());
        }
        if (GameClear == ObjectManager::GetGameState())
        {
            m_ObjHandle = LoadGraph(JsonManager::ImgData_Instance()->Get_ResultData_Instance()->GetClearData_BackGround().c_str());
        }
    }

    void BackGround::DrawObj()
    {
        //‰æ‘œ‚Ì•\Ž¦
        DrawGraph(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), m_ObjHandle, TRUE);
    }
}