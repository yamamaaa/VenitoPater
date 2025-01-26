#include "NumDays.h"
#include "../../GameSystem/Window/Window.h"

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
        DeleteFontToHandle(m_FontHandle);
        //メモリの解放
        delete window;
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
        numdays->m_NumDays = 0;
        numdays->m_DrawCount = 0;
        numdays->m_Collar = m_COLLARCODE;
        numdays->m_IsFadeDone = false;
        numdays->m_FontHandle = CreateFontToHandle("メイリオ", numdays->m_FONTSIZE.x, numdays->m_FONTSIZE.y, DX_FONTTYPE_ANTIALIASING_EDGE);

        numdays->window = nullptr;	//windowのインスタンス生成

        //文字の長さを取得して画面中央に座標を設定
        int x = GetDrawFormatStringWidthToHandle(numdays->m_FontHandle, "%d日目", numdays->m_NumDays);
        numdays->m_WindowSize = numdays->window->GetWindowSize();
        float ans_x = (numdays->m_WindowSize.x- x) / 2;
        float ans_y = (numdays->m_WindowSize.y - numdays->m_FONTSIZE.x) / 2;
        numdays->m_ObjPos = { ans_x,ans_y };
    }

    void NumDays::UpdateNumDays()
    {
        //一日経過
        numdays->m_NumDays++;
        //描画座標の更新
        int x = GetDrawFormatStringWidthToHandle(numdays->m_FontHandle, "%d日目", numdays->m_NumDays);
        numdays->m_ObjPos.x = (numdays->m_WindowSize.x - x) / 2;
    }

    void NumDays::DrawNumDays()
    {
        if (!numdays->m_IsFadeDone)
        {
            numdays->m_DrawCount += numdays->m_COUNTSPEED;

            //現在の日数を表示
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, numdays->m_Collar);
            DrawFormatStringToHandle(static_cast<int>(numdays->m_ObjPos.x), static_cast<int>(numdays->m_ObjPos.y),GetColor(numdays->m_Collar, numdays->m_Collar, numdays->m_Collar), numdays->m_FontHandle, "%d日目", numdays->m_NumDays);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

            DrawFormatString(750, 350, GetColor(255, 255, 255), "日数表示カウント:%f 最高値100", numdays->m_DrawCount);

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