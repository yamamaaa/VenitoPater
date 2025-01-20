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
        numdeys->m_NumDeys = 1;
    }

    void NumDeys::UpdateNumDeys()
    {
        //一日経過
        numdeys->m_NumDeys ++;
    }
}