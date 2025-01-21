#pragma once
#include "../../MouseBase/MouseBase.h"

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

        POINTS m_ResultLogo_Pos;    //���U���g���S�\�����W

        POINTS m_SelectUi_Pos[2];       //�Z���N�gUi���W
        POINTS m_UiOffset[2];           //���W���炵��
        POINTS m_Uipos;

#ifdef DEBUG
        std::string m_selectstatus = "";
#endif // DEBUG
    };
}

