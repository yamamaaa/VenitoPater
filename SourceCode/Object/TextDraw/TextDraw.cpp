#include "TextDraw.h"
#include "../ObjectTag/TimeOver_ObjectTag.h"
#include "../ObjectManager/ObjectManager.h"

namespace object
{
    TextDraw::TextDraw()
        :ObjectBase(timeOver_ObjectTag.TEXTDRAW)
    {
        //�ǂݍ��݊֘A
        LoadObject();
    }

    TextDraw::~TextDraw()
    {
        m_TxtFile.close();

        //�t�H���g�̃A�����[�h
        if (RemoveFontResourceEx(m_FontPath, FR_PRIVATE, NULL)) {
        }
        else {
            MessageBox(NULL, "remove failure", "", MB_OK);
        }
    }

    void TextDraw::LoadObject()
    {
        m_WaitDone = false;
        m_IsLineSet = true;
        m_IslineAnim = false;
        m_IsDraw = true;
        m_IsLoadDone = false;
        m_StartCount = 0.0f;
        m_DrawCount = 0.0f;
        m_TxtNum = 0;
        m_AnimCount = 0.0f;
        m_NowCollar = m_COLLAR_DEFAULT;
        m_AnimSpeed = m_SPEED_DEFAULT;

        //���݂̃Q�[���X�e�[�^�X���擾
        GameStatus status = ObjectManager::GetNextGameState();

        std::string text;
        if (status == TimeOver)
        {
            text = JsonManager::TextData_Instance()->Get_CharacterData_Instance()->GetLineData_GameOver();
            m_ObjPos = { 0,600 };
        }

        //�t�@�C���̓ǂݍ���
        m_TxtFile.open(text.c_str());

        //�t�H���g�̓ǂݍ���
        m_FontPath = "../Asset/font/story/ShinRetroMaruGothic-Medium.ttf";

        //�t�H���g�̓ǂݍ��݂��ł��Ȃ�������
        if (AddFontResourceEx(m_FontPath, FR_PRIVATE, NULL) > 0)
        {
        }
        else
        {
            // �t�H���g�Ǎ��G���[����
            MessageBox(NULL, "FontErrer", "", MB_OK);
        }

        //�t�H���g�����擾
        std::ifstream fontname_data;
        std::string name;
        fontname_data.open(JsonManager::FontData_Instance()->Get_StoryDat_Instance()->Get_FontTagData().c_str());
        std::getline(fontname_data, name);
        //�t�H���g���Z�b�g
        ChangeFont(name.c_str(), DX_CHARSET_DEFAULT);
        fontname_data.close();
    }

    void TextDraw::UpdateObj(const float deltatime)
    {
        //�����\�����Ȃ��Ƃ������Ȃ�
        if (!m_IsDraw)
            return;

        if (!m_WaitDone)
        {
            m_StartCount += m_RISESPEED;
            if (m_StartCount >= m_WAITCOU_MAX)
            {
                m_WaitDone = true;
            }
            return;
        }

        UpdateDrawStatus();

        if (m_IslineAnim)
        {
            TextAnim();
        }
    }

    void TextDraw::UpdateDrawStatus()
    {
        //�����̃Z�b�g�ƃA�j�����I�������
        if (m_IsLineSet&& !m_IslineAnim)
        {
            m_DrawCount += m_RISESPEED;
            if (m_DrawCount >= m_DRAW_COUNTMAX)
            {
                m_DrawCount = 0.0f;
                m_IsLineSet = false;
                if (m_IsLoadDone)
                {
                    m_IsDraw = false;
                }
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

        if (line == m_END)	//�t�@�C���̏I���Ȃ�
        {
            m_IsLoadDone = true;    //�����̓ǂݍ��݂��I����
        }
        else
        {
            m_Line = line;
        }

        m_IsLineSet = true;
        m_IslineAnim = true;
    }

    void TextDraw::TextAnim()
    {
        m_AnimCount += m_AnimSpeed;
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

    void TextDraw::DrawObj()
    {
        if (m_IsDraw)
        {
            SetFontSize(30);
            int x = GetDrawStringWidth(m_Line.c_str(), -1);
            DrawString((1920 - x) / 2, static_cast<int>(m_ObjPos.y), (m_Line.substr(0, m_TxtNum) + " ").c_str(), GetColor(static_cast<int>(m_NowCollar.x), static_cast<int>(m_NowCollar.y), static_cast<int>(m_NowCollar.z)));
        }

#ifdef DEBUG
        SetFontSize(m_DEBUG_FONTSIZE);
        DrawFormatString(0, 40, GetColor(255, 255, 255), "�����ēǂݍ��݂܂�:%f", m_DrawCount);
        DrawFormatString(0, 60, GetColor(255, 255, 255), "�����X�^�[�g�܂�:%f", m_StartCount);
#endif // DEBUG
    }
}