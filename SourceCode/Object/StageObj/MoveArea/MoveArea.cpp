#include "MoveArea.h"
#include "../../ObjectTag/Play_ObjectTag.h"
#include "../../StageObj/AreaNumController/AreaNumController.h"
#include "../../CharaObj/AvoidStatus/AvoidStatus.h"
#include "../../../MouseStatus/MouseStatus.h"

namespace object
{
    MoveArea::MoveArea()
        :MouseBase(play_ObjectTag.MOVEAREA)
    {
        //�ǂݍ��݊֘A
        LoadObject();
    }

    MoveArea::~MoveArea()
    {
        //�����Ȃ�
    }

    void MoveArea::LoadObject()
    {
        m_IsMove = false;
        m_CanMove = true;
        m_MoveCount = m_MOVECOUNT_MAX;
    }

    void MoveArea::UpdateObj(const float deltatime)
    {
        //���͏�Ԃ��s�̎��͏����Ȃ�
        if (!mousestatus::MouseStatus::GetIsFadeDone())
            return;

        //�ړ�������
        if (m_IsMove)
        {
            //�Ăшړ��ł���܂ŃJ�E���g
            m_MoveCount-=m_COUNTSPPED_MOVE* deltatime;
            if (m_MoveCount <= 0.0f)
            {
                m_IsMove = false;
                m_CanMove = true;
                m_MoveCount = m_MOVECOUNT_MAX;
            }
        }

        //��𒆂̓G���A�ړ��s��
        if (AvoidStatus::GetIsAvoid())
            return;

        for (std::string& tag : AreaMove_PosTagAll)
        {
            //�G���A�ړ��ł����Ԃ�
            if (m_AreaNumber[tag] == true && m_CanMove)
            {
                //�}�E�X���G���A�ړ��̈ʒu�ɂ��邩
                m_ObjPos.x = m_MovePos[tag].x;
                m_ObjPos.y = m_MovePos[tag].y;

                m_ObjSize.x = static_cast<int>(m_HitSize[tag].x);
                m_ObjSize.y = static_cast<int>(m_HitSize[tag].y);

                CursorHit();

                //�����ړ��o������
                if (GetCursorHit())
                {
#ifdef DEBUG
                    d_CursorHit[tag] = "Hit";
#endif
                    Update_AreaNumber(tag);
                    CursorHitControl();
                    m_IsMove = true;
                    m_CanMove = false;
                }
#ifdef DEBUG
                else
                {
                    d_CursorHit[tag] = "NoHit";
                }
#endif
            }
        }

        //������
        m_ObjPos.x = 0.0f;
        m_ObjPos.y = 0.0f;
    }

    void MoveArea::CursorHitControl()
    {
        //������
        for (std::string& tag : AreaMove_PosTagAll)
        {
            m_AreaNumber[tag] = false;
        }

        //�\���G���A�ɂ���ԕω�
        switch (AreaNumController::GetAreaNum())
        {
        case 0:
            m_AreaNumber[areaMove_PosTag.LEFT] = true;
            break;
        case 1:
            m_AreaNumber[areaMove_PosTag.UP] = true;
            m_AreaNumber[areaMove_PosTag.RIGHT] = true;
            m_AreaNumber[areaMove_PosTag.LEFT] = true;
            break;
        case 2:
            m_AreaNumber[areaMove_PosTag.RIGHT] = true;
            break;
        case 3:
            m_AreaNumber[areaMove_PosTag.DOWN] = true;
            break;
        }
    }

    void MoveArea::DrawObj()
    {
#ifdef DEBUG
        //HitBox�̕\��
        for (std::string& tag : AreaMove_PosTagAll)
        {
            if (m_AreaNumber[tag] == true)
            {
                m_ObjPos.x = m_MovePos[tag].x;
                m_ObjPos.y = m_MovePos[tag].y;

                m_ObjSize.x = static_cast<int>(m_HitSize[tag].x);
                m_ObjSize.y = static_cast<int>(m_HitSize[tag].y);

                DrawBox(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), static_cast<int>(m_ObjPos.x) + m_ObjSize.x, static_cast<int>(m_ObjPos.y) + m_ObjSize.y, GetColor(static_cast<int>(d_ColorCode[tag].x), static_cast<int>(d_ColorCode[tag].y), static_cast<int>(d_ColorCode[tag].z)), FALSE);
            }
        }

        DrawFormatString(0, 180, GetColor(255, 255, 255), "��:%s", d_CursorHit[areaMove_PosTag.UP].c_str());
        DrawFormatString(0, 200, GetColor(255, 255, 255), "��:%s", d_CursorHit[areaMove_PosTag.RIGHT].c_str());
        DrawFormatString(0, 220, GetColor(255, 255, 255), "�E:%s", d_CursorHit[areaMove_PosTag.LEFT].c_str());
        DrawFormatString(0, 240, GetColor(255, 255, 255), "��:%s", d_CursorHit[areaMove_PosTag.DOWN].c_str());
        DrawFormatString(0, 320, GetColor(255, 255, 255), "�\�����G���A:%d", AreaNumController::GetAreaNum());
        DrawFormatString(300, 320, GetColor(255, 255, 255), "�G���A�ړ��ł���܂�:%f", m_MoveCount);
#endif
    }

    void MoveArea::Update_AreaNumber(std::string tagname)
    {
        int tmp = AreaNumController::GetAreaNum();

        //�G���A�ԍ��̐؂�ւ�
        if (tagname == areaMove_PosTag.UP)
        {
            tmp = m_CEILINGAREA_NUM;
        }
        if (tagname == areaMove_PosTag.DOWN)
        {
            tmp = m_FRONTAREA_NUM;
        }
        if (tagname == areaMove_PosTag.LEFT)
        {
            tmp++;
        }
        if (tagname == areaMove_PosTag.RIGHT)
        {
            tmp--;
        }

        //�G���A�ԍ��̍X�V
        AreaNumController::SetAreaNum(tmp);
    }
}