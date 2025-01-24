#include "TimeStatus.h"

namespace object
{
    //���Ԃ����
    std::unique_ptr<TimeStatus>TimeStatus::timestatus = nullptr;

    TimeStatus::TimeStatus()
    {
        //�����Ȃ�
    }

    TimeStatus::~TimeStatus()
    {
        //�����Ȃ�
    }

    void TimeStatus::Initialize()
    {
        //���̂���Ȃ琶��
        if (!timestatus)
        {
            timestatus.reset(new TimeStatus);
        }

        //�ǂݍ��݊֘A
        LoadObject();
    }

    void TimeStatus::LoadObject()
    {
        //������
        timestatus->m_IsTimeOver = false;
    }

}