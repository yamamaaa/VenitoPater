#pragma once
#include"../../MouseBase/MouseBase.h"

namespace object
{
    /// <summary>
    /// �v���C���[�֘A
    /// </summary>
    class Player:public MouseBase
    {
    public:

        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        Player();

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~Player();

        /// <summary>
        /// �ǂݍ��݊֘A
        /// </summary>
        void LoadObject() override;

        void UpdateObj(const float deltatime) override;

        void DrawObj()override;

        void MoveObj(const float deltatime)override;

    private:

#ifdef DEBUG
        std::string select_level = "";  //��Փx�\��
        std::string mouse_click = "";   //�}�E�X�N���b�N���
#endif
    };

}

