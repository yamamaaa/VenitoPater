#pragma once
#include <vector>
#include <fstream>
#include"../../ObjectBase/ObjectBase.h"
#include"CharaItem_Tag.h"

namespace object
{
    class StoryItem :public ObjectBase
    {
    public:

        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        StoryItem();

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~StoryItem();

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

        int m_BackFade;     //�w�i�摜

        const std::string m_END = "null";           //�t�@�C�����[�R�[�h
        const std::string m_NEXT = "n";             //�摜�ύX�Ȃ�
        const std::string m_BLACKOUT = "black";     //�摜�\���Ȃ�

        bool m_IsDrawObj;    //�摜��\�����邩

        const float m_FADESPEED = 1.5f; //�t�F�[�h���x
        const int m_COLORCODE = 255;	//�J���[�R�[�h

        float m_Color;       //�摜�����x
        float m_Calculation;  //�����x�ϓ���

        bool m_IsFade;              //�t�F�[�h���I�������
        bool m_IsReleaseObj;        //�������I��邩

        std::unordered_map<std::string, int> m_ObjImg;  //�摜�f�[�^

        //�摜�ʒu
        std::unordered_map<std::string, POINTFLOAT> m_ImgPos{
            {charaItem_Tag.DUCK,{830,270}},
            {charaItem_Tag.GUARD_SET,{ 520,330}},
            {charaItem_Tag.MEDICINE,{ 860,360}},
        };
    };
}

