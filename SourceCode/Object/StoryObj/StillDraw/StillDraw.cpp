#include "StillDraw.h"
#include"../../ObjectTag/Still_ObjectTag.h"
#include"../LineStatus/LineStatus.h"
#include"../../NumDeys/NumDeys.h"

namespace object
{
    StillDraw::StillDraw()
        :ObjectBase(still_ObjectTag.STILL)
    {
        //読み込み関連
        LoadObject();
    }

    StillDraw::~StillDraw()
    {
        m_TxtFile.close();
    }

    void StillDraw::LoadObject()
    {
        m_ObjImg.clear();
        m_ObjPos = { 0,184 };
        m_Index = 0;

        m_Collar = 0;
        m_Calculation = 0;

        m_IsFadeIn_Done = false;
        m_IsFade = false;

        //日数別に読み込むファイルを変更
        int dey = NumDeys::GetNumDeys();
        int max;
        std::string text;
        switch (dey)
        {
        case 0:
            max = 2;
            for (int i = 0; i < max; i++)
            {
                m_ObjImg.push_back(LoadGraph(JsonManager::ImgData_Instance()->Get_StoryImgData_Instance()->GetStillData_Day_0(i).c_str()));
            }
            text = JsonManager::TextData_Instance()->Get_StillData_Instance()->GetDrawImgData_Day_0();
            break;
        case 1:
            max = 3;
            for (int i = 0; i < max; i++)
            {
                m_ObjImg.push_back(LoadGraph(JsonManager::ImgData_Instance()->Get_StoryImgData_Instance()->GetStillData_Day_1(i).c_str()));
            }
            text = JsonManager::TextData_Instance()->Get_StillData_Instance()->GetDrawImgData_Day_1();
            break;
        case 2:
            max = 6;
            for (int i = 0; i < max; i++)
            {
                m_ObjImg.push_back(LoadGraph(JsonManager::ImgData_Instance()->Get_StoryImgData_Instance()->GetStillData_Day_2(i).c_str()));
            }
            text = JsonManager::TextData_Instance()->Get_StillData_Instance()->GetDrawImgData_Day_2();
            break;
        case 3:
            max = 8;
            for (int i = 0; i < max; i++)
            {
                m_ObjImg.push_back(LoadGraph(JsonManager::ImgData_Instance()->Get_StoryImgData_Instance()->GetStillData_Day_3(i).c_str()));
            }
            text = JsonManager::TextData_Instance()->Get_StillData_Instance()->GetDrawImgData_Day_3();
            break;
        case 4:
            max = 2;
            for (int i = 0; i < max; i++)
            {
                m_ObjImg.push_back(LoadGraph(JsonManager::ImgData_Instance()->Get_StoryImgData_Instance()->GetStillData_Day_4(i).c_str()));
            }
            text = JsonManager::TextData_Instance()->Get_StillData_Instance()->GetDrawImgData_Day_4();
            break;
        }

        m_TxtFile.open(text.c_str());
        UpdateDrawStatus();
    }

    void StillDraw::UpdateObj(const float deltatime)
    {
        //文字セット前は以下処理なし
        if (!LineStatus::GetIsDoneAnim())
            return;

        UpdateDrawStatus();
    }

    void StillDraw::UpdateDrawStatus()
    {
        std::getline(m_TxtFile, m_Line);    //テキストファイルの読み込み

        if (m_Line == m_NEXT)
        {
            return;
        }
        else if (m_Line == m_BLACKOUT)
        {
            IsBlackOut = true;
        }
        else if (m_Line == m_STILLDRAW)
        {
            IsBlackOut = false;
            m_IsFade = true;
        }
    }

    void StillDraw::DrawObj()
    {
        if (!IsBlackOut)
        {
            if (m_IsFade)
            {
                FadeObj();
            }
            else
            {
                DrawGraph(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), m_ObjHandle, TRUE);
            }
        }
    }

    void StillDraw::FadeObj()
    {
        m_Calculation += m_FADESPEED;

        if (m_IsFadeIn_Done)
        {
            //だんだん明るく
            m_Collar += static_cast<int>(m_Calculation);
            if (m_Collar >= m_COLLARCODE)
            {
                m_IsFade = false;	//処理の完了
                m_Calculation = 0;
                m_IsFadeIn_Done = false;
                m_Collar = m_COLLARCODE;
            }
        }
        else
        {
            //だんだん暗く
            m_Collar -= static_cast<int>(m_Calculation);
            if (m_Collar <= 0)
            {
                m_IsFadeIn_Done = true;	//処理の完了
                m_Calculation = 0;
                m_Collar = 0;
                m_ObjHandle = m_ObjImg[m_Index];
                m_Index++;
            }
        }

        SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_Collar);
        DrawGraph(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), m_ObjHandle, TRUE);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }
}