#pragma once
#include "../../MouseBase/MouseBase.h"

/// <summary>
/// ��ʃT�C�Y�֘A
/// </summary>
namespace GameSystem
{
    class Window;
}

namespace object
{
    /// <summary>
    /// �Q�[���I�[�o�[��ʊ֘A
    /// </summary>
    class GameOverUi :public MouseBase
    {
    public:

        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        GameOverUi();

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~GameOverUi();

    private:

        /// <summary>
        /// �ǂݍ��݊֘A
        /// </summary>
        void LoadObject() override ;

        /// <summary>
        /// �I�u�W�F�N�g�̍X�V
        /// </summary>
        /// <param name="deltatime">�f���^�^�C��</param>
        void UpdateObj(const float deltatime) override;

        /// <summary>
        /// �I�u�W�F�N�g�̕`��
        /// </summary>
        void DrawObj() override;

        GameSystem::Window* window;

        POINTFLOAT m_ResultLogo_Pos;    //���U���g���S�\�����W

        POINTFLOAT m_SelectUi_Pos[2];       //�Z���N�gUi���W
        POINTFLOAT m_UiOffset[2];           //���W���炵��
        POINTFLOAT m_Uipos;                 //Ui�ʒu

        int m_FontHandle;          //�t�H���g�n���h��(�^�C�g��)
        int m_FontHandle_Ui;       //�t�H���g�n���h��(Ui)

        const POINTS m_FONTSIZE = { 150,60 };     //�t�H���g�T�C�Y(�^�C�g��)
        const POINTS m_FONTSIZE_Ui = { 30,10 };    //�t�H���g�T�C�Y(Ui)

        const int m_COLOR = 255;       //�J���[�R�[�h

        const std::string m_Title = "GameOver";
        const std::string m_SelectText[2] = { "�R���e�j���[" ,"�^�C�g����" };

#ifdef DEBUG
        std::string m_selectstatus = "";
#endif // DEBUG
    };
}

