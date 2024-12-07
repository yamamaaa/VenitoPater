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
    }
}