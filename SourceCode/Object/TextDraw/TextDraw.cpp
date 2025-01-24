#include "TextDraw.h"
#include "../ObjectTag/TimeOver_ObjectTag.h"
#include "../ObjectManager/ObjectManager.h"

namespace object
{
    TextDraw::TextDraw()
        :ObjectBase(timeOver_ObjectTag.TEXTDRAW)
    {
        //読み込み関連
        LoadObject();
    }

    TextDraw::~TextDraw()
    {
        m_TxtFile.close();

        //フォントのアンロード
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

        //現在のゲームステータスを取得
        GameStatus status = ObjectManager::GetNextGameState();

        std::string text;
        if (status == TimeOver)
        {
            text = JsonManager::TextData_Instance()->Get_CharacterData_Instance()->GetLineData_GameOver();
            m_ObjPos = { 0,600 };
        }

        //ファイルの読み込み
        m_TxtFile.open(text.c_str());

        //フォントの読み込み
        m_FontPath = "../Asset/font/story/ShinRetroMaruGothic-Medium.ttf";

        //フォントの読み込みができなかったら
        if (AddFontResourceEx(m_FontPath, FR_PRIVATE, NULL) > 0)
        {
        }
        else
        {
            // フォント読込エラー処理
            MessageBox(NULL, "FontErrer", "", MB_OK);
        }

        //フォント名を取得
        std::ifstream fontname_data;
        std::string name;
        fontname_data.open(JsonManager::FontData_Instance()->Get_StoryDat_Instance()->Get_FontTagData().c_str());
        std::getline(fontname_data, name);
        //フォントをセット
        ChangeFont(name.c_str(), DX_CHARSET_DEFAULT);
        fontname_data.close();
    }

    void TextDraw::UpdateObj(const float deltatime)
    {
        //文字表示がないとき処理なし
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
        //文字のセットとアニメが終わったら
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

        //未セット状態なら
        if (!m_IsLineSet)
        {
            DrawTextSet();
        }
    }

    void TextDraw::DrawTextSet()
    {
        //前の文字をクリア
        m_Line.clear();
        m_TxtNum = 0;
        m_NowCollar = m_COLLAR_DEFAULT;
        m_AnimSpeed = m_SPEED_DEFAULT;

        std::string line = "";

        //次の行を読み込み
        std::getline(m_TxtFile, line);

        if (line == m_END)	//ファイルの終わりなら
        {
            m_IsLoadDone = true;    //文字の読み込みを終える
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
        DrawFormatString(0, 40, GetColor(255, 255, 255), "文字再読み込みまで:%f", m_DrawCount);
        DrawFormatString(0, 60, GetColor(255, 255, 255), "文字スタートまで:%f", m_StartCount);
#endif // DEBUG
    }
}