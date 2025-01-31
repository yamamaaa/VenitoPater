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
        //�t�H���g�n���h���̉��
        DeleteFontToHandle(m_FontHandle_Am);
        DeleteFontToHandle(m_FontHandle_Time);
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

        m_NowColor = m_COLOR_DEFAULT;

        //�t�H���g�n���h���̐���
        m_FontHandle_Am = CreateFontToHandle("���C���I", m_FONTSIZE_AM.x, m_FONTSIZE_AM.y, DX_FONTTYPE_ANTIALIASING);
        m_FontHandle_Time = CreateFontToHandle("���C���I", m_FONTSIZE_TIME.x, m_FONTSIZE_TIME.y, DX_FONTTYPE_ANTIALIASING);
    }

    void Time::UpdateObj(float deltatime)
    {
        //�^�C���I�[�o�[���Ă����珈���Ȃ�
        if (TimeStatus::GetIsTimeOver())
            return;

        //���ۂ̎����v�Z
        m_NowTime += m_RISETIME* deltatime;

        //�\��������ݒ�
        m_DrawCount += m_RISETIME* deltatime;

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
            //�����L���O���[�h�Ȃ�N���A��ʂ�
            object::PlayMenu menu = object::ObjectManager::GetPlayMode();
            if (menu == object::PlayMenu::PlayRankingMode)
            {
                ObjectManager::SetNextGameState(GameClear);
                return;
            }

            //�m���}�B�����Ă��邩
            if (ItemGetNum::GetIsNolmClear())
            {
                //�B�����Ă�����N���A��ʂ�
                ObjectManager::SetNextGameState(GameClear);
            }
            else
            {
                //���B���Ȃ�^�C���X�e�[�^�X�ύX
                TimeStatus::SetIsTimeOver(true);
                m_NowColor = m_COLOR_RED;
            }
        }
    }

    void Time::DrawObj()
    {
        unsigned int cr=GetColor(static_cast<int>(m_NowColor.x), static_cast<int>(m_NowColor.y), static_cast<int>(m_NowColor.z));

        DrawStringFToHandle(m_ObjPos.x, m_ObjPos.y,m_AmText.c_str(),cr, m_FontHandle_Am);

        if (m_DrawMinutes == 0)
        {
            DrawFormatStringFToHandle(m_TimePos.x, m_TimePos.y, cr, m_FontHandle_Time, m_TimeText_Zero.c_str(), m_DrawTime);
        }
        else
        {
            DrawFormatStringFToHandle(m_TimePos.x, m_TimePos.y, cr, m_FontHandle_Time, m_TimeText.c_str(), m_DrawTime, m_DrawMinutes);
        }

#ifdef DEBUG
        DrawFormatString(0, 1060, GetColor(255, 255, 255), "���یo�ߎ���:%f", m_NowTime);
        DrawString(0, 1040, "F1�Ń^�C���I�[�o�[",GetColor(255, 0, 0));
#endif // DEBUG
    }
}
