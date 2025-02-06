#pragma once
#include <unordered_map>
#include<vector>
#include "../MouseBase/MouseBase.h"
#include "../ObjectManager/ObjectManager.h"

namespace object
{
    /// <summary>
    /// Menu��ʊ֘A
    /// </summary>
    class Menu :public MouseBase
    {
    public:

        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        Menu();

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~Menu();

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
        /// �N���b�N����
        /// </summary>
        bool ClickDetect(POINTFLOAT& objpos, POINTS& objsize);

        /// <summary>
        /// �J�[�\������
        /// </summary>
        bool CursorDetect(POINTFLOAT& objpos, POINTS& objsize);

        /// <summary>
        /// ���j���[�I����̃X�e�[�^�X�Z�b�g
        /// </summary>
        void GameStatusSet();

        /// <summary>
        /// �I�u�W�F�N�g�̕`��
        /// </summary>
        void DrawObj() override;

        std::string m_JsonTag[3];  //�T�E���h�pJson�^�O

        int m_IconImg;      //���j���[�A�C�R���摜
        int m_MenuBack_Img; //���j���[�w�i�摜
        int m_SelectImg;    //�Z���N�g�摜

        POINTFLOAT m_MenuBack_Pos;          //���j���[�w�i�摜�ʒu

        POINTFLOAT m_SelectPos_Offset;    //�Z���N�g�摜�ʒu_���炵��

        POINTFLOAT m_IconHitPos;    //�A�C�R�������蔻��ʒu
        POINTS m_IconHit_Size;      //�����蔻��T�C�Y

        POINTFLOAT m_BackHit_Pos;   //�Q�[���ɖ߂�{�^��������ʒu
        POINTS m_BackHit_Size;      //�����蔻��T�C�Y

        std::vector<POINTFLOAT> m_MenuHit_Pos;  //���j���[�{�^�������蔻��
        POINTS m_MenuHit_Size;      //�����蔻��T�C�Y

        int m_HitIndex;     //�����������j���[
        bool m_IsMenuMode;  //���j���[�A�C�R���������ꂽ��
    };
}

