#include "NumDeys.h"

namespace object
{
    std::unique_ptr<NumDeys>NumDeys::numdeys = nullptr;

    NumDeys::NumDeys()
    {
        //�����Ȃ�
    }

    NumDeys::~NumDeys()
    {
        //�����Ȃ�
    }

    void NumDeys::Initialize()
    {
        //���Ԃ���Ȃ�C���X�^���X����
        if (!numdeys)
        {
            numdeys.reset(new NumDeys);
        }

        LoadObject();
    }

    void NumDeys::LoadObject()
    {
        //�����̏�����
        numdeys->m_NumDeys = 1;
    }

    void NumDeys::UpdateNumDeys()
    {
        //����o��
        numdeys->m_NumDeys ++;
    }
}