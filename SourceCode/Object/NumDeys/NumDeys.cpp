#include <Dxlib.h>
#include "NumDeys.h"

namespace object
{
    std::unique_ptr<NumDeys>NumDeys::numdeys = nullptr;

    NumDeys::NumDeys()
    {
        //処理なし
    }

    NumDeys::~NumDeys()
    {
        //処理なし
    }

    void NumDeys::Initialize()
    {
        //実態が空ならインスタンス生成
        if (!numdeys)
        {
            numdeys.reset(new NumDeys);
        }

        LoadObject();
    }

    void NumDeys::LoadObject()
    {
        //日数の初期化
        numdeys->m_NumDeys = 0;
        numdeys->m_IsFadeDone = false;
    }

    void NumDeys::UpdateNumDeys()
    {
        //一日経過
        numdeys->m_NumDeys++;
    }

    void NumDeys::DrawNumDeys()
    {
        if (!numdeys->m_IsFadeDone)
        {
            numdeys->m_DrawCount += 0.1f;

            //現在の日数を表示
            SetFontSize(120);
            DrawFormatString(820, 480, GetColor(numdeys->m_Collar, numdeys->m_Collar, numdeys->m_Collar), "%d日目", numdeys->m_NumDeys);

            SetFontSize(16);
            DrawFormatString(750, 350, GetColor(255, 255, 255), "日数表示カウント:%f 最高値100", numdeys->m_DrawCount);

            if (numdeys->m_DrawCount >= 100.0f)
            {
                numdeys->m_Collar -= m_DROPSPEED;

                if (numdeys->m_Collar <= 0.0f)
                {
                    numdeys->m_IsFadeDone = true;	//処理の完了
                }
            }
        }
    }
}