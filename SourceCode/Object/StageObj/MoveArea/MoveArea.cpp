#include "MoveArea.h"
#include "../../ObjectTag/Global_ObjectTag.h"
#include "../../StageObj/AreaNumController/AreaNumController.h"
#include "../../CharaObj/AvoidStatus/AvoidStatus.h"

namespace object
{
    MoveArea::MoveArea()
        :MouseBase(global_objecttag.MOVEAREA)
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
        //�ړ�������
        if (m_IsMove)
        {
            //�Ăшړ��ł���܂ŃJ�E���g
            m_MoveCount--;
            if (m_MoveCount == 0)
            {
                m_IsMove = false;
                m_CanMove = true;
                m_MoveCount = m_MOVECOUNT_MAX;
            }
        }

        //��𒆂̓G���A�ړ��s��
        if (AvoidStatus::GetIsAvoid())
            return;

        for (std::string& tag : StageMove_PosTagAll)
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
        for (std::string& tag : StageMove_PosTagAll)
        {
            m_AreaNumber[tag] = false;
        }

        //�\���G���A�ɂ���ԕω�
        switch (AreaNumController::GetAreaNum())
        {
        case 0:
            m_AreaNumber[stagemove_postag.LEFT] = true;
            break;
        case 1:
            m_AreaNumber[stagemove_postag.UP] = true;
            m_AreaNumber[stagemove_postag.RIGHT] = true;
            m_AreaNumber[stagemove_postag.LEFT] = true;
            break;
        case 2:
            m_AreaNumber[stagemove_postag.RIGHT] = true;
            break;
        case 3:
            m_AreaNumber[stagemove_postag.DOWN] = true;
            break;
        }
    }

    void MoveArea::DrawObj()
    {
#ifdef DEBUG
        //HitBox�̕\��
        for (std::string& tag : StageMove_PosTagAll)
        {
            if (m_AreaNumber[tag] == true)
            {
                m_ObjPos.x = m_MovePos[tag].x;
                m_ObjPos.y = m_MovePos[tag].y;

                m_ObjSize.x = static_cast<int>(m_HitSize[tag].x);
                m_ObjSize.y = static_cast<int>(m_HitSize[tag].y);

                DrawBox(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), static_cast<int>(m_ObjPos.x) + m_ObjSize.x, static_cast<int>(m_ObjPos.y) + m_ObjSize.y, GetColor(static_cast<int>(d_CollarCode[tag].x), static_cast<int>(d_CollarCode[tag].y), static_cast<int>(d_CollarCode[tag].z)), FALSE);
            }
        }
        DrawFormatString(0, 100, GetColor(255, 255, 255), "��:��");
        DrawFormatString(0, 120, GetColor(255, 255, 255), "��:��");
        DrawFormatString(0, 140, GetColor(255, 255, 255), "��:�E");
        DrawFormatString(0, 160, GetColor(255, 255, 255), "��:��");

        DrawFormatString(0, 180, GetColor(255, 255, 255), "��:%s", d_CursorHit[stagemove_postag.UP].c_str());
        DrawFormatString(0, 200, GetColor(255, 255, 255), "��:%s", d_CursorHit[stagemove_postag.RIGHT].c_str());
        DrawFormatString(0, 220, GetColor(255, 255, 255), "�E:%s", d_CursorHit[stagemove_postag.LEFT].c_str());
        DrawFormatString(0, 240, GetColor(255, 255, 255), "��:%s", d_CursorHit[stagemove_postag.DOWN].c_str());
        DrawFormatString(0, 320, GetColor(255, 255, 255), "�\�����G���A:%d", AreaNumController::GetAreaNum());
        DrawFormatString(300, 320, GetColor(255, 255, 255), "�\���J�E���g:%f", m_MoveCount);
#endif
    }

    void MoveArea::Update_AreaNumber(std::string tagname)
    {
        int tmp = AreaNumController::GetAreaNum();

        //�G���A�ԍ��̐؂�ւ�
        if (tagname == stagemove_postag.UP)
        {
            tmp = m_CEILINGAREA_NUM;
        }
        if (tagname == stagemove_postag.DOWN)
        {
            tmp = m_FRONTAREA_NUM;
        }
        if (tagname == stagemove_postag.LEFT)
        {
            tmp++;
        }
        if (tagname == stagemove_postag.RIGHT)
        {
            tmp--;
        }

        //�G���A�ԍ��̍X�V
        AreaNumController::SetAreaNum(tmp);
    }
}