#include "NumDays.h"

namespace object
{
    std::unique_ptr<NumDays>NumDays::numdays = nullptr;

    NumDays::NumDays()
    {
        //処理なし
    }

    NumDays::~NumDays()
    {
        //処理なし
    }

    void NumDays::Initialize()
    {
        //実態が空ならインスタンス生成
        if (!numdays)
        {
            numdays.reset(new NumDays);
        }

        LoadObject();
    }

    void NumDays::LoadObject()
    {
        //日数の初期化
        numdays->m_NumDays = 3;
        numdays->m_DrawCount = 0;
        numdays->m_Collar = m_COLLARCODE;
        numdays->m_IsFadeDone = false;
        numdays->m_ObjPos = { 780.0f,470.0f };
    }

    void NumDays::UpdateNumDays()
    {
        //一日経過
        numdays->m_NumDays++;
    }

    void NumDays::DrawNumDays()
    {
        if (!numdays->m_IsFadeDone)
        {
            numdays->m_DrawCount += numdays->m_COUNTSPEED;

            //現在の日数を表示
            SetFontSize(m_FONTSIZE);
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, numdays->m_Collar);
            DrawFormatString(static_cast<int>(numdays->m_ObjPos.x), static_cast<int>(numdays->m_ObjPos.y), GetColor(numdays->m_Collar, numdays->m_Collar, numdays->m_Collar), "%d日目", numdays->m_NumDays);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

            SetFontSize(16);
            //DrawFormatString(750, 350, GetColor(255, 255, 255), "日数表示カウント:%f 最高値100", numdays->m_DrawCount);

            if (numdays->m_DrawCount >= numdays->m_COUNTMAX)
            {
                numdays->m_Collar -= m_DROPSPEED;

                if (numdays->m_Collar <= 0.0f)
                {
                    numdays->m_IsFadeDone = true;	//処理の完了
                }
            }
        }
    }
}