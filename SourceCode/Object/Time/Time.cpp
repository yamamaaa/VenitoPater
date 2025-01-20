#include "Time.h"
#include "../ObjectTag/Global_ObjectTag.h"

namespace object
{
    Time::Time()
        :ObjectBase(global_objecttag.TIME)
    {
        //�ǂݍ��݊֘A
        LoadObject();
    }

    Time::~Time()
    {
        //�����Ȃ�
    }

    void Time::LoadObject()
    {
        //������
        m_NowTime = 0.0f;     //���ۂ̌o�ߎ���
        m_DrawTime = 0;       //�\���p_����
        m_DrawMinutes = 0;    //�\���p_��
        m_DrawCount = 0.0f;   //�\�������̎Z�o

        m_ObjPos.x = 50.0f;     //���W�����l�Z�b�g
        m_ObjPos.y = 50.0f;

        m_TimePos.x = 120.0f;	//���W�����l�Z�b�g
        m_TimePos.y = 30.0f;
    }

    void Time::UpdateObj(float deltatime)
    {
        //���ۂ̎����v�Z
        m_NowTime += m_RISETIME;

        //�\��������ݒ�
        m_DrawCount += m_RISETIME;

        if (m_DrawCount > m_TIMER_MAX / m_TIMERFPS)
        {
            m_DrawCount = 0.0f;
            m_DrawMinutes += m_MINUTES_RISETIME;

            if (m_DrawMinutes == m_MINUTES_MAX)
            {
                m_DrawMinutes = 0;
                m_DrawTime++;
            }
        }
    }

    void Time::DrawObj()
    {
        SetFontSize(m_FONTSIZE_AM);
        DrawFormatString(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), GetColor(255, 255, 255), "AM");
        SetFontSize(m_FONTSIZE_TIME);
        DrawFormatString(static_cast<int>(m_TimePos.x), static_cast<int>(m_TimePos.y), GetColor(255, 255, 255), "%d:%d", m_DrawTime, m_DrawMinutes);
#ifdef DEBUG
        SetFontSize(m_DEBUG_FONTSIZE);
        DrawFormatString(0, 1060, GetColor(255, 255, 255), "���یo�ߎ���:%f", m_NowTime);
#endif // DEBUG
    }
}
