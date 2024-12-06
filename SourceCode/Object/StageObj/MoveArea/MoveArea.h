#pragma once
#include <unordered_map>
#include"../../MouseBase/MouseBase.h"
#include"../../StageObj/Stage/StageMove_PosTag.h"

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

        const int m_CEILINGAREA_NUM = 3;    //�V��G���A�i���o�[
        const int m_FRONTAREA_NUM = 1;      //���ʃG���A�i���o�[

        const float m_MOVECOUNT_MAX = 30.0f;     //�Ăшړ��ł���܂�

        bool m_IsMove;       //�G���A�ړ�������
        bool m_CanMove;       //�G���A�ړ��ł��邩
        float m_MoveCount;   //�G���A�ړ������ۂ̃J�E���g

        //�㍶�E����HitPos
        std::unordered_map<std::string, POINTS> m_HitSize{
            {stagemove_postag.UP,{900,150}},
            {stagemove_postag.RIGHT,{150,800}},
            {stagemove_postag.LEFT,{150,800}},
            {stagemove_postag.DOWN,{900,150}},
        };

        //�㍶�E����MovePos
        std::unordered_map<std::string, POINTFLOAT> m_MovePos{
            {stagemove_postag.UP,{500.0f,0.0f}},
            {stagemove_postag.RIGHT,{0.0f,200.0f}},
            {stagemove_postag.LEFT,{1770.0f,200.0f}},
            {stagemove_postag.DOWN,{500.0f,930.0f}},
        };

        //�J�[�\���̃q�b�g���
        std::unordered_map<std::string, bool> m_AreaNumber{
            {stagemove_postag.UP,{true}},
            {stagemove_postag.RIGHT,{true}},
            {stagemove_postag.LEFT,{true}},
            {stagemove_postag.DOWN,{false}},
        };

#ifdef DEBUG

        //�㍶�E����Hitline�̃J���[�R�[�h
        std::unordered_map<std::string, VECTOR> d_CollarCode{
            {stagemove_postag.UP,{255,40,0}},
            {stagemove_postag.RIGHT,{250,245,0}},
            {stagemove_postag.LEFT,{53,161,107}},
            {stagemove_postag.DOWN,{0,65,255}},
        };

        //�J�[�\��������������
        std::unordered_map<std::string, std::string> d_CursorHit{
            {stagemove_postag.UP,""},
            {stagemove_postag.RIGHT,""},
            {stagemove_postag.LEFT,""},
            {stagemove_postag.DOWN,""},
        };
#endif
    };
}
