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
        //読み込み関連
        LoadObject();
    }

    Time::~Time()
    {
        //フォントハンドルの解放
        DeleteFontToHandle(m_FontHandle_Am);
        DeleteFontToHandle(m_FontHandle_Time);
    }

    void Time::LoadObject()
    {
        //初期化
        m_NowTime = 0.0f;     //実際の経過時間
        m_DrawTime = 0;       //表示用_時間
        m_DrawMinutes = 0;    //表示用_分
        m_DrawCount = 0.0f;   //表示時刻の算出

        m_ObjPos.x = 50.0f;     //座標初期値セット
        m_ObjPos.y = 50.0f;

        m_TimePos.x = 120.0f;	//座標初期値セット
        m_TimePos.y = 30.0f;

        m_NowColor = m_COLOR_DEFAULT;

        //フォントハンドルの生成
        m_FontHandle_Am = CreateFontToHandle("メイリオ", m_FONTSIZE_AM.x, m_FONTSIZE_AM.y, DX_FONTTYPE_ANTIALIASING);
        m_FontHandle_Time = CreateFontToHandle("メイリオ", m_FONTSIZE_TIME.x, m_FONTSIZE_TIME.y, DX_FONTTYPE_ANTIALIASING);
    }

    void Time::UpdateObj(float deltatime)
    {
        //タイムオーバーしていたら処理なし
        if (TimeStatus::GetIsTimeOver())
            return;

        //実際の時刻計算
        m_NowTime += m_RISETIME* deltatime;

        //表示時刻を設定
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
        //F1が押されたら時間経過
        if (CheckHitKey(KEY_INPUT_F1))
        {
            m_DrawTime = m_PLAYTIME_MAX;
        }
#endif // DEBUG

        //プレイの終了時間になったら
        if (m_DrawTime == m_PLAYTIME_MAX)
        {
            //ランキングモードならクリア画面へ
            object::PlayMenu menu = object::ObjectManager::GetPlayMode();
            if (menu == object::PlayMenu::PlayRankingMode)
            {
                ObjectManager::SetNextGameState(GameClear);
                return;
            }

            //ノルマ達成しているか
            if (ItemGetNum::GetIsNolmClear())
            {
                //達成していたらクリア画面へ
                ObjectManager::SetNextGameState(GameClear);
            }
            else
            {
                //未達成ならタイムステータス変更
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
        DrawFormatString(0, 1060, GetColor(255, 255, 255), "実際経過時間:%f", m_NowTime);
        DrawString(0, 1040, "F1でタイムオーバー",GetColor(255, 0, 0));
#endif // DEBUG
    }
}
