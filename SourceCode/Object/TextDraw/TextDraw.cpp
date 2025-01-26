#include "TextDraw.h"
#include "../ObjectTag/ThreeDays_ObjectTag.h"
#include "../../GameSystem/Window/Window.h"
#include "../NumDays/NumDays.h"

namespace object
{
    TextDraw::TextDraw()
        :ObjectBase(threedays_objtag.TEXTDRAW)
    {
        //�ǂݍ��݊֘A
        LoadObject();
    }

    TextDraw::~TextDraw()
    {
        if (m_Status == TimeOver)
        {
            m_TxtFile.close();
        }
        DeleteFontToHandle(m_FontHandle);
        //�������̉��
        delete window;
    }

    void TextDraw::LoadObject()
    {
        m_WaitDone = false;
        m_IsLineSet = true;
        m_IslineAnim = false;
        m_StartCount = 0.0f;
        m_DrawCount = 0.0f;
        m_TxtNum = 0;
        m_AnimCount = 0.0f;
        m_NowCollar = m_COLLAR_DEFAULT;
        m_AnimSpeed = m_SPEED_DEFAULT;

        window = nullptr;	//window�̃C���X�^���X����
        m_WindowSize = window->GetWindowSize();

        //���݂̃Q�[���X�e�[�^�X���擾
        m_Status = ObjectManager::GetNextGameState();

        std::string text;

        if (m_Status == TimeOver)
        {
            //�t�H���g�n���h���̐���
            m_FontHandle = CreateFontToHandle("���C���I", m_FONTSIZE_Line.x, m_FONTSIZE_Line.y, DX_FONTTYPE_ANTIALIASING);

            text = JsonManager::TextData_Instance()->Get_CharacterData_Instance()->GetLineData_GameOver();
            m_ObjPos = { 0,600 };
            //�t�@�C���̓ǂݍ���
            m_TxtFile.open(text.c_str());
        }
        if (m_Status == GamePlay)
        {
            //�t�H���g�n���h���̐���
            m_FontHandle = CreateFontToHandle("���C���I", m_FONTSIZE_Day.x, m_FONTSIZE_Day.y, DX_FONTTYPE_ANTIALIASING);

            //�����̒������擾���ĉ�ʒ����ɍ��W��ݒ�
            int x = GetDrawFormatStringWidthToHandle(m_FontHandle, "%d����", NumDays::GetNumDays());

            float ans_x = static_cast<float>((m_WindowSize.x - x) / 2);
            float ans_y = static_cast<float>((m_WindowSize.y - m_FONTSIZE_Day.x) / 2);

            m_ObjPos = { ans_x,ans_y };
        }
    }

    void TextDraw::UpdateObj(const float deltatime)
    {
        //�X�^�[�g���Ă��班���҂�
        if (!m_WaitDone)
        {
            m_StartCount += m_RISESPEED;
            if (m_StartCount >= m_WAITCOU_MAX)
            {
                m_WaitDone = true;
            }
            return;
        }

        //�Q�[���v���C���Ȃ�����֘A�����X�V
        if (m_Status == GamePlay)
        {
            NumDayDrawCount(deltatime);
            return;
        }

        UpdateDrawStatus(deltatime);

        if (m_IslineAnim)
        {
            TextAnim(deltatime);
        }
    }

    void TextDraw::UpdateDrawStatus(const float deltatime)
    {
        //�����̃Z�b�g�ƃA�j�����I�������
        if (m_IsLineSet&& !m_IslineAnim)
        {
            m_DrawCount += m_RISESPEED* deltatime;
            if (m_DrawCount >= m_DRAW_COUNTMAX)
            {
                m_DrawCount = 0.0f;
                m_IsLineSet = false;
            }
        }

        //���Z�b�g��ԂȂ�
        if (!m_IsLineSet)
        {
            DrawTextSet();
        }
    }

    void TextDraw::DrawTextSet()
    {
        //�O�̕������N���A
        m_Line.clear();
        m_TxtNum = 0;
        m_NowCollar = m_COLLAR_DEFAULT;
        m_AnimSpeed = m_SPEED_DEFAULT;

        std::string line = "";

        //���̍s��ǂݍ���
        std::getline(m_TxtFile, line);

        if (line == m_END)//�t�@�C�����[�Ȃ�I�u�W�F�N�g�̍폜
        {
            ObjectManager::ReleaseObj(threedays_objtag.TEXTDRAW);
        }
        else
        {
            m_Line = line;
        }

        m_IsLineSet = true;
        m_IslineAnim = true;
    }

    void TextDraw::TextAnim(const float deltatime)
    {
        m_AnimCount += m_AnimSpeed * deltatime;
        if (m_AnimCount >= m_ANIMFPS)
        {
            if (m_TxtNum == m_Line.size())
            {
                m_IslineAnim = false;
            }
            else
            {
                m_TxtNum++;
                m_AnimCount = 0.0f;
            }
        }
    }

    void TextDraw::NumDayDrawCount(const float deltatime)
    {
        //�\���\���Ԃ��v�Z
        m_DrawCount += m_COUNTSPEED * deltatime;
        if (m_DrawCount >= m_COUNTMAX)
        {
            m_NowCollar.x -= m_DROPSPEED * deltatime;

            //����������������I�u�W�F�N�g�̍폜
            if (m_NowCollar.x <= 0.0f)
            {
                ObjectManager::ReleaseObj(threedays_objtag.TEXTDRAW);
            }
        }
    }

    void TextDraw::LineDraw()
    {
        //�����̉������擾�����W����ʒ����ɐݒ�
        int x = GetDrawStringWidthToHandle(m_Line.c_str(),m_FontHandle,0);
        m_ObjPos.x = static_cast<float>((m_WindowSize.x - x) / 2);

        std::string text = (m_Line.substr(0, m_TxtNum) + " ");

        //�Z���t�̕\��
        DrawStringFToHandle(m_ObjPos.x, m_ObjPos.y,text.c_str(), GetColor(static_cast<int>(m_NowCollar.x), static_cast<int>(m_NowCollar.y), static_cast<int>(m_NowCollar.z)), m_FontHandle);
#ifdef DEBUG
        DrawFormatString(0, 40, GetColor(255, 255, 255), "�����ēǂݍ��݂܂�:%f", m_DrawCount);
        DrawFormatString(0, 60, GetColor(255, 255, 255), "�����X�^�[�g�܂�:%f", m_StartCount);
#endif // DEBUG
    }

    void TextDraw::NumDayDraw()
    {
        //���݂̓�����\��
        int day = NumDays::GetNumDays();
        int collar = static_cast<int>(m_NowCollar.x);

        SetDrawBlendMode(DX_BLENDMODE_ALPHA, collar);
        DrawFormatStringFToHandle(m_ObjPos.x, m_ObjPos.y, GetColor(collar, collar, collar), m_FontHandle, "%d����", day);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
#ifdef DEBUG
        DrawFormatString(750, 350, GetColor(255, 255, 255), "�����\���J�E���g:%f", m_DrawCount);
#endif // DEBUG
    }

    void TextDraw::DrawObj()
    {
        if (m_Status == GamePlay)   //�Q�[���v���C���͓����̕\��
        {
            NumDayDraw();
        }
        if (m_Status == TimeOver)   //�^�C���I�[�o�[���̓Z���t�̕\��
        {
            LineDraw();
        }
    }
}