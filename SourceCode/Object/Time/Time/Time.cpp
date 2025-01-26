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
        //処理なし
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

        m_NowCollar = m_COLLAR_DEFAULT;
    }

    void Time::UpdateObj(float deltatime)
    {
        //タイムオーバーしていたら処理なし
        if (TimeStatus::GetIsTimeOver())
            return;

        //実際の時刻計算
        m_NowTime += m_RISETIME;

        //表示時刻を設定
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
        //F1が押されたら時間経過
        if (CheckHitKey(KEY_INPUT_F1))
        {
            m_DrawTime = m_PLAYTIME_MAX;
        }
#endif // DEBUG

        //プレイの終了時間になったら
        if (m_DrawTime == m_PLAYTIME_MAX)
        {
            //ノルマ達成しているか
            if (ItemGetNum::GetIsNolmClear())
            {
                //達成していたらクリア画面へ
                ObjectManager::SetNowGameState(GameClear);
            }
            else
            {
                //未達成ならタイムステータス変更
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
        DrawFormatString(0, 1060, GetColor(255, 255, 255), "実際経過時間:%f", m_NowTime);
#endif // DEBUG
    }
}
