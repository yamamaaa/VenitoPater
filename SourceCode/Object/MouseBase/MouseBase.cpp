#include "MouseBase.h"
#include "../../MouseStatus/MouseStatus.h"

namespace object
{
    MouseBase::MouseBase(std::string tagname)
        :ObjectBase(tagname),
        m_StateClick(false),
        m_CanClick(false),
        m_CursorHit(false)
    {
        //������
        LoadObject();
    }

    MouseBase::~MouseBase()
    {
        //�����Ȃ�
    }

    void MouseBase::LoadObject()
    {
        m_MousePosX = 0;
        m_MousePosY = 0;
    }

    void MouseBase::CanClick()
    {
        // �}�E�X���{�^����ɂ�������N���b�N�\�ɂ���
        if (m_CursorHit)
        {
            m_CanClick = true;
        }
        else
        {
            //�N���b�N�s�\
            m_CanClick = false;
        }

        MouseClick();
    }

    void MouseBase::MouseClick()
    {
        //���͏�Ԃ��s�̎��͏����Ȃ�
        if (!mousestatus::MouseStatus::GetIsFadeDone())
            return;

        //�N���b�N�\��Ԃ̎�
        if (m_CanClick)
        {
            //���{�^�����N���b�N���ꂽ��N���b�N����
            if ((GetMouseInput() & MOUSE_INPUT_LEFT))
            {
                m_StateClick = true;
            }
            else
            {
                m_StateClick = false;
            }
        }
        else
        {
            //�s�\�Ȃ疢���͂�
            m_StateClick = false;
        }
    }

    void MouseBase::CursorHit()
    {
        //�}�E�X�J�[�\�����W�擾
        GetMousePoint(&m_MousePosX, &m_MousePosY);

        if (collision::CheckHitPoint_Square(static_cast<float>(m_MousePosX), static_cast<float>(m_MousePosY), m_ObjPos.x, m_ObjPos.y, static_cast<float>(m_ObjSize.x), static_cast<float>(m_ObjSize.y)))
        {
            m_CursorHit = true;
        }
        else
        {
            m_CursorHit = false;
        }
    }

#if DEBUG
    void MouseBase::Debug_DrawObj()
    {
        //�폜�\��
        GetMousePoint(&m_MousePosX, &m_MousePosY);
        DrawFormatString(0, 40, GetColor(255, 255, 255), "�J�[�\��x:%d", m_MousePosX);
        DrawFormatString(0, 60, GetColor(255, 255, 255), "�J�[�\��y:%d", m_MousePosY);
    }
#endif
}