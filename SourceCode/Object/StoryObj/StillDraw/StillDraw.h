#pragma once
#include <vector>
#include <fstream>
#include"../../ObjectBase/ObjectBase.h"

namespace object
{
    //Still�֘A
    class StillDraw:public ObjectBase
    {
    public:

        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        StillDraw();

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~StillDraw();

    private:

        /// <summary>
        /// �ǂݍ��݊֘A
        /// </summary>
        void LoadObject() override;

        /// <summary>
        /// �X�V
        /// </summary>
        /// <param name="deltatime">�f���^�^�C��</param>
        void UpdateObj(const float deltatime) override;

        /// <summary>
        /// �\����Ԃ̍X�V
        /// </summary>
        void UpdateDrawStatus();

        /// <summary>
        /// �`��
        /// </summary>
        void DrawObj()override;

        /// <summary>
        /// �t�F�[�h����
        /// </summary>
        void FadeObj();

        std::ifstream m_TxtFile;    //�ǂݍ��܂ꂽ�t�@�C��
        std::string m_Line;         //�t�@�C������擾��������

        const std::string m_END = "null";           //�t�@�C�����[�R�[�h
        const std::string m_NEXT = "n";             //�摜�ύX�Ȃ�
        const std::string m_BLACKOUT = "black";     //�摜�\���Ȃ�
        const std::string m_STILLDRAW = "still";    //Still�摜�\��

        bool IsBlackOut = false;    //�摜���\���ɂ��邩

        const float m_FADESPEED = 1.0f; //�t�F�[�h���x
        const int m_COLLARCODE = 255;	//�J���[�R�[�h

        float m_Collar;       //�摜�����x
        float m_Calculation;  //�����x�ϓ���

        bool m_IsFadeIn_Done; //�t�F�[�h�C�������������
        bool m_IsFade ;       //�t�F�[�h���I�������

        std::vector<int> m_ObjImg;  //�X�`���摜
        int m_Index;                //�X�`���摜�C���f�b�N�X
    };
}