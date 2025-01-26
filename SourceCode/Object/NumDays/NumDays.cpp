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
        DeleteFontToHandle(m_FontHandle);
        //�������̉��
        delete window;
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
        numdays->m_DrawCount = 0;
        numdays->m_Collar = m_COLLARCODE;
        numdays->m_IsFadeDone = false;
        numdays->m_FontHandle = CreateFontToHandle("���C���I", numdays->m_FONTSIZE.x, numdays->m_FONTSIZE.y, DX_FONTTYPE_ANTIALIASING_EDGE);

        numdays->window = nullptr;	//window�̃C���X�^���X����

        //�����̒������擾���ĉ�ʒ����ɍ��W��ݒ�
        int x = GetDrawFormatStringWidthToHandle(numdays->m_FontHandle, "%d����", numdays->m_NumDays);
        numdays->m_WindowSize = numdays->window->GetWindowSize();
        float ans_x = (numdays->m_WindowSize.x- x) / 2;
        float ans_y = (numdays->m_WindowSize.y - numdays->m_FONTSIZE.x) / 2;
        numdays->m_ObjPos = { ans_x,ans_y };
    }

    void NumDays::UpdateNumDays()
    {
        //����o��
        numdays->m_NumDays++;
        //�`����W�̍X�V
        int x = GetDrawFormatStringWidthToHandle(numdays->m_FontHandle, "%d����", numdays->m_NumDays);
        numdays->m_ObjPos.x = (numdays->m_WindowSize.x - x) / 2;
    }

    void NumDays::DrawNumDays()
    {
        if (!numdays->m_IsFadeDone)
        {
            numdays->m_DrawCount += numdays->m_COUNTSPEED;

            //���݂̓�����\��
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, numdays->m_Collar);
            DrawFormatStringToHandle(static_cast<int>(numdays->m_ObjPos.x), static_cast<int>(numdays->m_ObjPos.y),GetColor(numdays->m_Collar, numdays->m_Collar, numdays->m_Collar), numdays->m_FontHandle, "%d����", numdays->m_NumDays);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

            DrawFormatString(750, 350, GetColor(255, 255, 255), "�����\���J�E���g:%f �ō��l100", numdays->m_DrawCount);

            if (numdays->m_DrawCount >= numdays->m_COUNTMAX)
            {
                numdays->m_Collar -= m_DROPSPEED;

                if (numdays->m_Collar <= 0.0f)
                {
                    numdays->m_IsFadeDone = true;	//�����̊���
                }
            }
        }
    }
}