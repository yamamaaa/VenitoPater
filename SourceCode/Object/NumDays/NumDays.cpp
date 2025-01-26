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
    }

    void NumDays::UpdateNumDays()
    {
        //一日経過
        numdays->m_NumDays++;
    }
}