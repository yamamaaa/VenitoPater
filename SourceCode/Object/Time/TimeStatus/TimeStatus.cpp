#include "TimeStatus.h"

namespace object
{
    //ŽÀ‘Ô‚ð‹ó‚É
    std::unique_ptr<TimeStatus>TimeStatus::timestatus = nullptr;

    TimeStatus::TimeStatus()
    {
        //ˆ—‚È‚µ
    }

    TimeStatus::~TimeStatus()
    {
        //ˆ—‚È‚µ
    }

    void TimeStatus::Initialize()
    {
        //ŽÀ‘Ì‚ª‹ó‚È‚ç¶¬
        if (!timestatus)
        {
            timestatus.reset(new TimeStatus);
        }

        //“Ç‚Ýž‚ÝŠÖ˜A
        LoadObject();
    }

    void TimeStatus::LoadObject()
    {
        //‰Šú‰»
        timestatus->m_IsTimeOver = false;
    }

}