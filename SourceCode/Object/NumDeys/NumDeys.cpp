#include <Dxlib.h>
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
        numdeys->m_NumDeys = 0;
        numdeys->m_IsFadeDone = false;
    }

    void NumDeys::UpdateNumDeys()
    {
        //����o��
        numdeys->m_NumDeys++;
    }

    void NumDeys::DrawNumDeys()
    {
        if (!numdeys->m_IsFadeDone)
        {
            numdeys->m_DrawCount += 0.1f;

            //���݂̓�����\��
            SetFontSize(120);
            DrawFormatString(820, 480, GetColor(numdeys->m_Collar, numdeys->m_Collar, numdeys->m_Collar), "%d����", numdeys->m_NumDeys);

            SetFontSize(16);
            DrawFormatString(750, 350, GetColor(255, 255, 255), "�����\���J�E���g:%f �ō��l100", numdeys->m_DrawCount);

            if (numdeys->m_DrawCount >= 100.0f)
            {
                numdeys->m_Collar -= m_DROPSPEED;

                if (numdeys->m_Collar <= 0.0f)
                {
                    numdeys->m_IsFadeDone = true;	//�����̊���
                }
            }
        }
    }
}