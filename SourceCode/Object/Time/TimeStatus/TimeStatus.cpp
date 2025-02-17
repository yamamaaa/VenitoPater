#include "TimeStatus.h"

namespace object
{
    //実態を空に
    std::unique_ptr<TimeStatus>TimeStatus::timestatus = nullptr;

    TimeStatus::TimeStatus()
    {
        //処理なし
    }

    TimeStatus::~TimeStatus()
    {
        //処理なし
    }

    void TimeStatus::Initialize()
    {
        //実体が空なら生成
        if (!timestatus)
        {
            timestatus.reset(new TimeStatus);
        }

        //読み込み関連
        LoadObject();
    }

    void TimeStatus::LoadObject()
    {
        //初期化
        timestatus->m_IsTimeOver = false;
    }
}