#pragma once
#include <fstream>
#include <unordered_map>
#include"../../ObjectBase/ObjectBase.h"

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
        /// �`��
        /// </summary>
        void DrawObj()override ;

        std::ifstream m_TxtFile;//�ǂݍ��܂ꂽ�t�@�C��
        std::string m_Status;   //�L�����N�^�[���

        //�L�����N�^�[�摜
        std::unordered_map<std::string, int> m_Objimg{};
    };
}