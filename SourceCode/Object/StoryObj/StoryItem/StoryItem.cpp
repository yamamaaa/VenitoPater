#include "StoryItem.h"
#include"../../ObjectTag/Story_ObjectTag.h"
#include "../../ObjectManager/ObjectManager.h"
#include"../LineStatus/LineStatus.h"
#include"../../../NumDays/NumDays.h"

namespace object
{
    StoryItem::StoryItem()
        :ObjectBase(story_ObjectTag.STORYITEM)
    {
        //読み込み関連
        LoadObject();
    }

    StoryItem::~StoryItem()
    {
        m_TxtFile.close();
    }

    void StoryItem::LoadObject()
    {
        m_ObjImg.clear();
        m_ObjPos = { 0,0 };

        m_Color = 0;
        m_Calculation = 0;

        m_IsDrawObj = false;
        m_IsFade = false;
        m_IsReleaseObj = false;

        m_BackFade= LoadGraph(JsonManager::ImgData_Instance()->Get_StoryImgData_Instance()->GetItemData_BackFade().c_str());

        //日数別に読み込むファイルを変更
        int day = NumDays::GetNumDays();
        std::string text;
        switch (day)
        {
        case 0:
            m_ObjImg[charaItem_Tag.DUCK]=LoadGraph(JsonManager::ImgData_Instance()->Get_StoryImgData_Instance()->GetItemData_Duck().c_str());
            m_ObjImg[charaItem_Tag.GUARD_SET] = LoadGraph(JsonManager::ImgData_Instance()->Get_StoryImgData_Instance()->GetItemData_Guard_Set().c_str());
            text = JsonManager::TextData_Instance()->Get_CharacterData_Instance()->GetItemData_Day_0();
            break;
        case 4:
            m_ObjImg[charaItem_Tag.MEDICINE] = LoadGraph(JsonManager::ImgData_Instance()->Get_StoryImgData_Instance()->GetItemData_Medicine().c_str());
            text = JsonManager::TextData_Instance()->Get_CharacterData_Instance()->GetItemData_Day_4();
            break;
        default:
            m_IsReleaseObj = true;
            break;
        }

        m_TxtFile.open(text.c_str());
        std::getline(m_TxtFile, m_Line);
        UpdateDrawStatus();
    }

    void StoryItem::UpdateObj(const float deltatime)
    {
        if (m_IsReleaseObj)
        {
            ObjectManager::ReleaseObj(story_ObjectTag.STORYITEM);
        }

        if (m_IsFade)
        {
            FadeObj(deltatime);
        }

        //文字セット前は以下処理なし
        if (!LineStatus::GetIsDoneAnim())
            return;

        std::getline(m_TxtFile, m_Line);
        if (m_Line != m_NEXT)
        {
            UpdateDrawStatus();
        }
    }

    void StoryItem::UpdateDrawStatus()
    {
        //ファイル末端ならオブジェクトの削除
        if (m_Line == m_END)
        {
            m_IsReleaseObj = true;
        }
        else if (m_Line == m_BLACKOUT)
        {
            m_IsDrawObj = false;
        }
        else
        {
            m_ObjHandle = m_ObjImg[m_Line.c_str()];
            m_ObjPos = m_ImgPos[m_Line.c_str()];
            m_Color = 0;
            m_IsDrawObj = true;
            m_IsFade = true;
        }
    }

    void StoryItem::FadeObj(const float deltatime)
    {
        m_Calculation += m_FADESPEED * deltatime;

        //だんだん明るく
        m_Color += static_cast<int>(m_Calculation);
        if (m_Color >= m_COLORCODE)
        {
            m_IsFade = false;	//処理の完了
            m_Calculation = 0;
            m_Color = static_cast<float>(m_COLORCODE);
        }
    }

    void StoryItem::DrawObj()
    {
        if (m_IsDrawObj)
        {
            DrawGraph(0, 0, m_BackFade, TRUE);
            if (m_IsFade)
            {
                SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(m_Color));
                DrawGraph(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), m_ObjHandle, TRUE);
                SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            }
            else
            {
                DrawGraph(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), m_ObjHandle, TRUE);
#ifdef DEBUG
                DrawFormatString(0, 80, GetColor(255, 255, 255), "表示アイテム:%s", m_Line.c_str());
#endif // DEBUG
            }
        }
    }
}