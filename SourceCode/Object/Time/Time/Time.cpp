#include "Time.h"
#include "../../ObjectTag/Global_ObjectTag.h"
#include "../../StageObj/ItemGetNum/ItemGetNum.h"
#include "../../ObjectManager/ObjectManager.h"
#include "../TimeStatus/TimeStatus.h"

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

        m_NowCollar = m_COLLAR_DEFAULT;
    }

    void Time::UpdateObj(float deltatime)
    {
        //�^�C���I�[�o�[���Ă����珈���Ȃ�
        if (TimeStatus::GetIsTimeOver())
            return;

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

#ifdef DEBUG
        //F1�������ꂽ�玞�Ԍo��
        if (CheckHitKey(KEY_INPUT_F1))
        {
            m_DrawTime = m_PLAYTIME_MAX;
        }
#endif // DEBUG

        //�v���C�̏I�����ԂɂȂ�����
        if (m_DrawTime == m_PLAYTIME_MAX)
        {
            //�m���}�B�����Ă��邩
            if (ItemGetNum::GetIsNolmClear())
            {
                //�B�����Ă�����N���A��ʂ�
                ObjectManager::SetNowGameState(GameClear);
            }
            else
            {
                //���B���Ȃ�^�C���X�e�[�^�X�ύX
                TimeStatus::SetIsTimeOver(true);
                m_NowCollar = m_COLLAR_RED;
            }
        }
    }

    void Time::DrawObj()
    {
        //SetFontSize(m_FONTSIZE_AM);
        DrawFormatString(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), GetColor(static_cast<int>(m_NowCollar.x), static_cast<int>(m_NowCollar.y), static_cast<int>(m_NowCollar.z)), "AM");
        //SetFontSize(m_FONTSIZE_TIME);
        DrawFormatString(static_cast<int>(m_TimePos.x), static_cast<int>(m_TimePos.y), GetColor(static_cast<int>(m_NowCollar.x), static_cast<int>(m_NowCollar.y), static_cast<int>(m_NowCollar.z)), "%d:%d", m_DrawTime, m_DrawMinutes);
#ifdef DEBUG
        //SetFontSize(m_DEBUG_FONTSIZE);
        DrawFormatString(0, 1060, GetColor(255, 255, 255), "���یo�ߎ���:%f", m_NowTime);
#endif // DEBUG
    }
}
