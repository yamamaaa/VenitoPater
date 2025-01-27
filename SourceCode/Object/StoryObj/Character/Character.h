#pragma once
#include <fstream>
#include <unordered_map>
#include"../../ObjectBase/ObjectBase.h"
#include"CharaStatus.h"

namespace object
{
    class Character:public ObjectBase
    {
    public:

        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        Character();

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~Character();

    private:

        /// <summary>
        /// �ǂݍ��݊֘A
        /// </summary>
        void LoadObject() override;

        /// <summary>
        /// �X�V
        /// </summary>
        /// <param name="deltatime">�f���^�^�C��</param>
        void UpdateObj(const float deltatime) override ;

        /// <summary>
        /// �\����Ԃ̍X�V
        /// </summary>
        void UpdateDrawStatus();

        /// <summary>
        /// �t�F�[�h����
        /// </summary>
        /// <param name="deltatime">�f���^�^�C��</param>
        void FadeObj(const float deltatime);

        /// <summary>
        /// �`��
        /// </summary>
        void DrawObj()override ;

        std::ifstream m_TxtFile;//�ǂݍ��܂ꂽ�t�@�C��
        std::string m_Status;   //�L�����N�^�[���

        //�L�����N�^�[�摜
        std::unordered_map<std::string, int> m_Objimg{};

        //�摜�ʒu
        std::unordered_map<std::string, POINTFLOAT> m_ImgPos{
            {charaStatus.NORMAL,{790,57}},
            {charaStatus.WORRY,{ 670,94}},
            {charaStatus.DISMAYER,{ 710,71}},
            {charaStatus.HAPPY,{585,33}},
            {charaStatus.SURPRISE,{690,95}},
        };
    };
}