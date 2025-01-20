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
        /// �`��
        /// </summary>
        void DrawObj()override;

        std::ifstream m_TxtFile;    //�ǂݍ��܂ꂽ�t�@�C��

        std::vector<int> m_ObjImg;  //�X�`���摜
        int m_Index;                //�X�`���摜�C���f�b�N�X
    };
}