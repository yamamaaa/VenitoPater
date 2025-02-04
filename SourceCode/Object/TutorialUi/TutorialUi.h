#pragma once
#include <unordered_map>
#include<vector>
#include "../MouseBase/MouseBase.h"
#include "../ObjectManager/ObjectManager.h"

namespace object
{
    /// <summary>
    /// Tutorial��ʊ֘A
    /// </summary>
    class TutorialUi :public MouseBase
    {
    public:

        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        TutorialUi();

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~TutorialUi();

    private:

        /// <summary>
        /// �ǂݍ��݊֘A
        /// </summary>
        void LoadObject() override;

        /// <summary>
        /// �I�u�W�F�N�g�̍X�V
        /// </summary>
        /// <param name="deltatime">�f���^�^�C��</param>
        void UpdateObj(const float deltatime) override;

        /// <summary>
        /// �I�u�W�F�N�g�̕`��
        /// </summary>
        void DrawObj() override;

        std::string m_JsonTag[3];  //�T�E���h�pJson�^�O

        std::vector<int> m_Tutorial_Img;   //�`���[�g���A���摜

        int m_MenuImg;      //���j���[�摜
        int m_SelectImg;    //�Z���N�g�摜
        int m_BackImg;      //�߂�{�^���摜

        const int m_SelectImg_Color = 170;  //�Z���N�g�摜�����x

        POINTFLOAT m_SelectPos;    //�Z���N�g�摜�ʒu

        POINTFLOAT m_BackHit_Pos;   //�^�C�g���ɖ߂�{�^��������ʒu
        POINTS m_BackHit_Size;  //�����蔻��T�C�Y

        std::vector<POINTFLOAT> m_MenuHit_Pos;  //���j���[�{�^�������蔻��
        POINTS m_MenuHit_Size;  //�����蔻��T�C�Y

        int m_HitIndex;     //�����������j���[
    };
}
