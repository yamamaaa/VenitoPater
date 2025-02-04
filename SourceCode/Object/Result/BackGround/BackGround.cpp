#include "BackGround.h"
#include "../../ObjectTag/GameOver_ObjectTag.h"
#include "../../ObjectManager/ObjectManager.h"
#include "../../../NumDays/NumDays.h"

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
        DeleteGraph(m_ObjHandle);
    }

    void BackGround::LoadObject()
    {
        m_ObjPos = { 0,0 };

        GameStatus status = ObjectManager::GetNowGameState();

        if (GameOver == status || TimeOver == status)
        {
            m_ObjHandle = LoadGraph(JsonManager::ImgData_Instance()->Get_ResultData_Instance()->GetOverData_BackGround().c_str());
        }
        if (GameClear == status)
        {
            m_ObjHandle = LoadGraph(JsonManager::ImgData_Instance()->Get_ResultData_Instance()->GetClearData_BackGround().c_str());
        }
        if (Story == status)
        {
            int day=NumDays::GetNumDays();
            std::string imgdata;
            switch (day)
            {
            case 4:
                imgdata = JsonManager::ImgData_Instance()->Get_StoryImgData_Instance()->GetBackgroundData_Stage();
                break;
            default:
                imgdata = JsonManager::ImgData_Instance()->Get_StoryImgData_Instance()->GetBackgroundData_Lounge();
                break;
            }
            m_ObjPos = { 0,184 };
            m_ObjHandle = LoadGraph(imgdata.c_str());
        }
        if (Score == status)
        {
            m_ObjHandle = LoadGraph("../Asset/image/score/score.png");
            m_ObjPos = { 0,0 };
        }
    }

    void BackGround::DrawObj()
    {
        //‰æ‘œ‚Ì•\Ž¦
        DrawGraph(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), m_ObjHandle, TRUE);
    }
}