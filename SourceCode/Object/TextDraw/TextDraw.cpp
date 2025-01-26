#include "TextDraw.h"
#include "../ObjectTag/ThreeDays_ObjectTag.h"
#include "../../GameSystem/Window/Window.h"
#include "../NumDays/NumDays.h"

namespace object
{
    TextDraw::TextDraw()
        :ObjectBase(threedays_objtag.TEXTDRAW)
    {
        //読み込み関連
        LoadObject();
    }

    TextDraw::~TextDraw()
    {
        if (m_Status == TimeOver)
        {
            m_TxtFile.close();
        }
        DeleteFontToHandle(m_FontHandle);
        //メモリの解放
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

        window = nullptr;	//windowのインスタンス生成
        m_WindowSize = window->GetWindowSize();

        //現在のゲームステータスを取得
        m_Status = ObjectManager::GetNextGameState();

        std::string text;

        if (m_Status == TimeOver)
        {
            //フォントハンドルの生成
            m_FontHandle = CreateFontToHandle("メイリオ", m_FONTSIZE_Line.x, m_FONTSIZE_Line.y, DX_FONTTYPE_ANTIALIASING);

            text = JsonManager::TextData_Instance()->Get_CharacterData_Instance()->GetLineData_GameOver();
            m_ObjPos = { 0,600 };
            //ファイルの読み込み
            m_TxtFile.open(text.c_str());
        }
        if (m_Status == GamePlay)
        {
            //フォントハンドルの生成
            m_FontHandle = CreateFontToHandle("メイリオ", m_FONTSIZE_Day.x, m_FONTSIZE_Day.y, DX_FONTTYPE_ANTIALIASING);

            //文字の長さを取得して画面中央に座標を設定
            int x = GetDrawFormatStringWidthToHandle(m_FontHandle, "%d日目", NumDays::GetNumDays());

            float ans_x = static_cast<float>((m_WindowSize.x - x) / 2);
            float ans_y = static_cast<float>((m_WindowSize.y - m_FONTSIZE_Day.x) / 2);

            m_ObjPos = { ans_x,ans_y };
        }
    }

    void TextDraw::UpdateObj(const float deltatime)
    {
        //スタートしてから少し待つ
        if (!m_WaitDone)
        {
            m_StartCount += m_RISESPEED;
            if (m_StartCount >= m_WAITCOU_MAX)
            {
                m_WaitDone = true;
            }
            return;
        }

        //ゲームプレイ中なら日数関連だけ更新
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
        //文字のセットとアニメが終わったら
        if (m_IsLineSet&& !m_IslineAnim)
        {
            m_DrawCount += m_RISESPEED* deltatime;
            if (m_DrawCount >= m_DRAW_COUNTMAX)
            {
                m_DrawCount = 0.0f;
                m_IsLineSet = false;
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

        if (line == m_END)//ファイル末端ならオブジェクトの削除
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
        //表示可能時間を計算
        m_DrawCount += m_COUNTSPEED * deltatime;
        if (m_DrawCount >= m_COUNTMAX)
        {
            m_NowCollar.x -= m_DROPSPEED * deltatime;

            //処理が完了したらオブジェクトの削除
            if (m_NowCollar.x <= 0.0f)
            {
                ObjectManager::ReleaseObj(threedays_objtag.TEXTDRAW);
            }
        }
    }

    void TextDraw::LineDraw()
    {
        //文字の横幅を取得し座標を画面中央に設定
        int x = GetDrawStringWidthToHandle(m_Line.c_str(),m_FontHandle,0);
        m_ObjPos.x = static_cast<float>((m_WindowSize.x - x) / 2);

        std::string text = (m_Line.substr(0, m_TxtNum) + " ");

        //セリフの表示
        DrawStringFToHandle(m_ObjPos.x, m_ObjPos.y,text.c_str(), GetColor(static_cast<int>(m_NowCollar.x), static_cast<int>(m_NowCollar.y), static_cast<int>(m_NowCollar.z)), m_FontHandle);
#ifdef DEBUG
        DrawFormatString(0, 40, GetColor(255, 255, 255), "文字再読み込みまで:%f", m_DrawCount);
        DrawFormatString(0, 60, GetColor(255, 255, 255), "文字スタートまで:%f", m_StartCount);
#endif // DEBUG
    }

    void TextDraw::NumDayDraw()
    {
        //現在の日数を表示
        int day = NumDays::GetNumDays();
        int collar = static_cast<int>(m_NowCollar.x);

        SetDrawBlendMode(DX_BLENDMODE_ALPHA, collar);
        DrawFormatStringFToHandle(m_ObjPos.x, m_ObjPos.y, GetColor(collar, collar, collar), m_FontHandle, "%d日目", day);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
#ifdef DEBUG
        DrawFormatString(750, 350, GetColor(255, 255, 255), "日数表示カウント:%f", m_DrawCount);
#endif // DEBUG
    }

    void TextDraw::DrawObj()
    {
        if (m_Status == GamePlay)   //ゲームプレイ中は日数の表示
        {
            NumDayDraw();
        }
        if (m_Status == TimeOver)   //タイムオーバー中はセリフの表示
        {
            LineDraw();
        }
    }
}