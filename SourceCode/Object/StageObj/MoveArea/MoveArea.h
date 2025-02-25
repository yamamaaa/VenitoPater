#pragma once
#include <unordered_map>
#include<vector>
#include"../../MouseBase/MouseBase.h"
#include"../../StageObj/Area/AreaMove_PosTag.h"

namespace object
{
    /// <summary>
    /// �G���A�ړ��֘A
    /// </summary>
    class MoveArea :public MouseBase
    {
    public:

        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        MoveArea();

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~MoveArea();

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

        /// <summary>
        /// ���݂̃G���A�i���o�[���X�V
        /// </summary>
        /// <param name="tagname">��������Box�̃^�O��</param>
        void Update_AreaNumber(const std::string tagname);

        /// <summary>
        /// �J�[�\���̃q�b�g��Ԃ𕪂���
        /// </summary>
        void CursorHitControl();

        const float m_COUNTSPPED_MOVE = 60.0f;   //�Ăшړ��ł���܂�(�J�E���g�X�s�[�h)
        const float m_MOVECOUNT_MAX = 18.0f;     //�Ăшړ��ł���܂�(�J�E���g�ő�l)

        const int m_CEILINGAREA_NUM = 3;    //�V��G���A�i���o�[
        const int m_FRONTAREA_NUM = 1;      //���ʃG���A�i���o�[

        bool m_IsMove;       //�G���A�ړ�������
        bool m_CanMove;       //�G���A�ړ��ł��邩
        float m_MoveCount;   //�G���A�ړ������ۂ̃J�E���g

        std::unordered_map<std::string, int> m_MoveUiImg{};         //�G���A�ړ���Ui�摜
        std::unordered_map<std::string, POINTFLOAT> m_MoveUiPos{};  //�G���A�ړ���Ui�摜�ʒu

        //�㍶�E����HitPos
        std::unordered_map<std::string, POINTS> m_HitSize{
            {areaMove_PosTag.UP,{900,150}},
            {areaMove_PosTag.RIGHT,{150,800}},
            {areaMove_PosTag.LEFT,{150,800}},
            {areaMove_PosTag.DOWN,{900,150}},
        };

        //�㍶�E����MovePos
        std::unordered_map<std::string, POINTFLOAT> m_MovePos{
            {areaMove_PosTag.UP,{500.0f,0.0f}},
            {areaMove_PosTag.RIGHT,{0.0f,200.0f}},
            {areaMove_PosTag.LEFT,{1770.0f,200.0f}},
            {areaMove_PosTag.DOWN,{500.0f,930.0f}},
        };

        //�J�[�\���̃q�b�g���
        std::unordered_map<std::string, bool> m_AreaNumber{
            {areaMove_PosTag.UP,{true}},
            {areaMove_PosTag.RIGHT,{true}},
            {areaMove_PosTag.LEFT,{true}},
            {areaMove_PosTag.DOWN,{false}},
        };

#if DEBUG

        //�㍶�E����Hitline�̃J���[�R�[�h
        std::unordered_map<std::string, VECTOR> d_ColorCode{
            {areaMove_PosTag.UP,{255,40,0}},
            {areaMove_PosTag.RIGHT,{250,245,0}},
            {areaMove_PosTag.LEFT,{53,161,107}},
            {areaMove_PosTag.DOWN,{0,65,255}},
        };

        //�J�[�\��������������
        std::unordered_map<std::string, std::string> d_CursorHit{
            {areaMove_PosTag.UP,""},
            {areaMove_PosTag.RIGHT,""},
            {areaMove_PosTag.LEFT,""},
            {areaMove_PosTag.DOWN,""},
        };
#endif
    };
}
