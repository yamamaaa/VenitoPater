#include "NumDays.h"
#include "../../GameSystem/Window/Window.h"

namespace object
{
    std::unique_ptr<NumDays>NumDays::numdays = nullptr;

    NumDays::NumDays()
    {
        //�����Ȃ�
    }

    NumDays::~NumDays()
    {
        //�����Ȃ�
    }

    void NumDays::Initialize()
    {
        //���Ԃ���Ȃ�C���X�^���X����
        if (!numdays)
        {
            numdays.reset(new NumDays);
        }

        LoadObject();
    }

    void NumDays::LoadObject()
    {
        //�����̏�����
        numdays->m_NumDays = 0;
    }

    void NumDays::UpdateNumDays()
    {
        //����o��
        numdays->m_NumDays++;
    }
}