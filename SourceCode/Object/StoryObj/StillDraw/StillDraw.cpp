#include "StillDraw.h"
#include"../../ObjectTag/Still_ObjectTag.h"
#include"../LineStatus/LineStatus.h"
#include"../../ObjectManager/ObjectManager.h"
#include"../../NumDeys/NumDeys.h"

namespace object
{
    StillDraw::StillDraw()
        :ObjectBase(still_ObjectTag.STILL)
    {
        //�ǂݍ��݊֘A
        LoadObject();
    }

    StillDraw::~StillDraw()
    {
        m_ObjImg.clear();
    }

    void StillDraw::LoadObject()
    {
        m_ObjImg.clear();
        m_ObjPos = { 0,0 };
        m_Index = 0;

        //�����ʂɓǂݍ��ރt�@�C����ύX
        int dey = NumDeys::GetNumDeys();

        switch (dey)
        {
        case 0:
            //m_ObjImg.push_back(LoadGraph("../Asset/image/story/still/steel_1.png"));
            break;
        case 1:
            //m_ObjImg.push_back(LoadGraph("../Asset/image/story/still/steel_2.png"));
            break;
        case 2:
            //m_ObjImg.push_back(LoadGraph("../Asset/image/story/still/steel_3.png"));
            break;
        }

        m_ObjHandle = m_ObjImg[m_Index];
    }

    void StillDraw::UpdateObj(const float deltatime)
    {
        //�����Z�b�g�O�͈ȉ������Ȃ�
        if (!LineStatus::GetIsDoneAnim())
            return;

        m_Index++;
        m_ObjHandle= m_ObjImg[m_Index];

        LineStatus::SetIsDoneAnim(false);
    }

    void StillDraw::DrawObj()
    {
        DrawGraph(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), m_ObjHandle, TRUE);
    }
}