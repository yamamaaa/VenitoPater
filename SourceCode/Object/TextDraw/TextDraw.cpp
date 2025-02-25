#include <ctime>

#include "TextDraw.h"
#include "../ObjectTag/Play_ObjectTag.h"
#include "../../GameSystem/Window/Window.h"
#include "../../NumDays/NumDays.h"

namespace object
{
    TextDraw::TextDraw()
        :ObjectBase(play_ObjectTag.TEXTDRAW)
    {
        //読み込み関連
        LoadObject();
    }

    TextDraw::~TextDraw()
    {
        if (m_Status != GamePlay)
        {
            m_TxtFile.close();
        }
        DeleteFontToHandle(m_FontHandle);
        //メモリの解放
        delete window;
    }

    void TextDraw::LoadObject()
    {
        m_IsReleaseObj = false;
        m_WaitDone = false;
        m_IsLineSet = false;
        m_IslineAnim = false;
        m_StartCount = 0.0f;
        m_DrawCount = 0.0f;
        m_TxtNum = 0;
        m_AnimCount = 0.0f;
        m_NowColor = m_COLOR_DEFAULT;
        m_AnimSpeed = m_SPEED_DEFAULT;

        window = nullptr;	//windowのインスタンス生成
        m_WindowSize = window->GetWindowSize();

        //現在のゲームステータスを取得
        m_Status = ObjectManager::GetNextGameState();

        std::string text;

        if (m_Status == TimeOver|| m_Status == GameOver)
        {
            if (m_Status == GameOver)
            {
                RandomLineSet();
            }
            else
            {
                text = JsonManager::TextData_Instance()->Get_GameOverData_Instance()->GetGameOverData_TimeOver();
                m_TxtFile.open(text.c_str());
            }

            //フォントハンドルの生成
            m_FontHandle = CreateFontToHandle("メイリオ", m_FONTSIZE_Line.x, m_FONTSIZE_Line.y, DX_FONTTYPE_ANTIALIASING);

            m_ObjPos = { 0,600 };
        }
        if (m_Status == GamePlay)
        {
            //フォントハンドルの生成
            m_FontHandle = CreateFontToHandle("メイリオ", m_FONTSIZE_Day.x, m_FONTSIZE_Day.y, DX_FONTTYPE_ANTIALIASING);
            m_ObjPos = { 1670,1000 };
        }
    }

    void TextDraw::RandomLineSet()
    {
        //ランダム生成の初期化
        srand(static_cast<unsigned int>(time(0)));

        //アイテムの出現設定
        int range = 100;
        int drawnum = rand() % range;

        //セリフの表示を行うなら表示セリフの選出
        if (drawnum <= 100)
        {
            range = 7;
            int linenum = rand() % range;
            std::string text;
            auto jsondata = JsonManager::TextData_Instance()->Get_GameOverData_Instance();

            if (linenum <= 2)
            {
                text = jsondata->GetGameOverData_line_0();
            }
            else if (linenum <= 4)
            {
                text = jsondata->GetGameOverData_line_1();
            }
            else if (linenum<= 6)
            {
                text = jsondata->GetGameOverData_line_2();
            }
            else if (linenum <= 7)
            {
                text = jsondata->GetGameOverData_line_3();
            }

            m_TxtFile.open(text.c_str());
        }
        else
        {
            m_IsReleaseObj = true;
        }

    }

    void TextDraw::UpdateObj(const float deltatime)
    {
        if (m_IsReleaseObj)
        {
            ObjectManager::ReleaseObj(play_ObjectTag.TEXTDRAW);
        }

        //スタートしてから少し待つ
        if (!m_WaitDone)
        {
            m_StartCount += m_RISESPEED* deltatime;
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
                m_IsLineSet = false;
                m_DrawCount = 0.0f;
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
        m_NowColor = m_COLOR_DEFAULT;
        m_AnimSpeed = m_SPEED_DEFAULT;

        std::string line = "";

        //次の行を読み込み
        std::getline(m_TxtFile, line);

        if (line == m_END)//ファイル末端ならオブジェクトの削除
        {
            m_IsReleaseObj = true;
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
            m_NowColor.x -= m_DROPSPEED * deltatime;

            //処理が完了したらオブジェクトの削除
            if (m_NowColor.x <= 0.0f)
            {
                ObjectManager::ReleaseObj(play_ObjectTag.TEXTDRAW);
            }
        }
    }

    void TextDraw::LineDraw()
    {
        //文字の横幅を取得し座標を画面中央に設定
        int x = GetDrawFormatStringWidthToHandle(m_FontHandle, m_Line.c_str(), -1);
        m_ObjPos.x = static_cast<float>((m_WindowSize.x - x) / 2);

        std::string text = (m_Line.substr(0, m_TxtNum) + " ");

        //セリフの表示
        DrawStringFToHandle(m_ObjPos.x, m_ObjPos.y,text.c_str(), GetColor(static_cast<int>(m_NowColor.x), static_cast<int>(m_NowColor.y), static_cast<int>(m_NowColor.z)), m_FontHandle);
#if DEBUG
        DrawFormatString(0, 40, GetColor(255, 255, 255), "文字再読み込みまで:%f", m_DrawCount);
        DrawFormatString(0, 60, GetColor(255, 255, 255), "文字スタートまで:%f", m_StartCount);
#endif // DEBUG
    }

    void TextDraw::NumDayDraw()
    {
        //現在の日数を表示
        int day = NumDays::GetNumDays();
        int collar = static_cast<int>(m_NowColor.x);

        SetDrawBlendMode(DX_BLENDMODE_ALPHA, collar);
        DrawFormatStringFToHandle(m_ObjPos.x, m_ObjPos.y, GetColor(collar, collar, collar), m_FontHandle, "%d日目", day);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
#if DEBUG
        DrawFormatString(750, 350, GetColor(255, 255, 255), "日数表示カウント:%f", m_DrawCount);
#endif // DEBUG
    }

    void TextDraw::DrawObj()
    {
        if (m_Status == GamePlay)   //ゲームプレイ中は日数の表示
        {
            NumDayDraw();
        }
        if (m_Status == TimeOver|| m_Status == GameOver)   //セリフの表示
        {
            LineDraw();
        }
    }
}