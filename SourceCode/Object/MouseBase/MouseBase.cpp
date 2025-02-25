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
        //初期化
        LoadObject();
    }

    MouseBase::~MouseBase()
    {
        //処理なし
    }

    void MouseBase::LoadObject()
    {
        m_MousePosX = 0;
        m_MousePosY = 0;
    }

    void MouseBase::CanClick()
    {
        // マウスがボタン上にあったらクリック可能にする
        if (m_CursorHit)
        {
            m_CanClick = true;
        }
        else
        {
            //クリック不可能
            m_CanClick = false;
        }

        MouseClick();
    }

    void MouseBase::MouseClick()
    {
        //入力状態が不可の時は処理なし
        if (!mousestatus::MouseStatus::GetIsFadeDone())
            return;

        //クリック可能状態の時
        if (m_CanClick)
        {
            //左ボタンがクリックされたらクリック中に
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
            //不可能なら未入力に
            m_StateClick = false;
        }
    }

    void MouseBase::CursorHit()
    {
        //マウスカーソル座標取得
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
        //削除予定
        GetMousePoint(&m_MousePosX, &m_MousePosY);
        DrawFormatString(0, 40, GetColor(255, 255, 255), "カーソルx:%d", m_MousePosX);
        DrawFormatString(0, 60, GetColor(255, 255, 255), "カーソルy:%d", m_MousePosY);
    }
#endif
}