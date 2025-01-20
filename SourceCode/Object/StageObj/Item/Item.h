#pragma once
#include <unordered_map>
#include"../../MouseBase/MouseBase.h"

namespace object
{
    /// <summary>
    /// �Q�[�����A�C�e���֘A
    /// </summary>
    class Item :public MouseBase
    {
    public:

        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        Item();

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~Item();

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

        /// <summary>
        /// �A�C�e���i���o�[���Z�b�g
        /// </summary>
        void ItemNumSet();

        /// <summary>
        /// �\������A�C�e�����Z�b�g
        /// </summary>
        void DrawItemSet();

        const int m_TOTAlITEM_NUM = 5;    //�G���A���̃A�C�e������
        const int m_ITEMOCCUR_AREA = 3;   //�A�C�e����\������G���A�̐�
        const int m_RARECHANCA = 3;       //���A�A�C�e���o���m��
        const int m_RAREITEM_INDEX = 5;   //���A�A�C�e���̓Y����

        int m_NowItemNumber;    //���݂̃A�C�e���ԍ�
        int m_DrawItemArea;     //�A�C�e����\������G���A
        int m_NowDrawItem;      //��ʂɕ\������A�C�e��

        POINTS m_NowItem_collision; //���݂̃A�C�e���̂����蔻��

        //�e�G���A�̃A�C�e���摜
        int m_ItemImg_area0[6]; //���̕���
        int m_ItemImg_area1[6]; //���ʂ̕���
        int m_ItemImg_area2[6]; //�E�̕���

        bool m_IsOccur;     //�A�C�e�����o��������
        bool m_IsRareItem;  //���A�A�C�e����
        bool m_IsSet;        //�Z�b�g�A�b�v������������
        bool m_IsGet;       //�A�C�e�����Q�b�g������
        bool m_CanDraw;    //�A�C�e����\���ł��邩

        const float m_OCCURCOUNT_MAX = 300.0f;  //�A�C�e���o���Ԋu
        const float m_COUNT_DECREMENT = 0.1f;   //�J�E���g������
        float m_OccurCount;                     //�o���܂ł̃J�E���g

        //���݂̃A�C�e���f�[�^�ۊǗp
        std::unordered_map<int, POINTS> m_NowDrawItem_Data;

        //�e�G���A�̃A�C�e��Hit�T�C�Y
        //VECTOR.x:���T�C�Y|VECTOR.y:�c�T�C�Y
        std::unordered_map<int, POINTS> m_HitSize_area0{
            {0,{80,75}},
            {1,{30,40}},
            {2,{70,75}},
            {3,{40,40}},
            {4,{60,60}},
            {5,{50,60}},
        };

        std::unordered_map<int, POINTS> m_HitSize_area1{
            {0,{50,60}},
            {1,{115,120}},
            {2,{80,70}},
            {3,{140,110}},
            {4,{125,53}},
            {5,{150,200}},
        };

        std::unordered_map<int, POINTS> m_HitSize_area2{
            {0,{80,90}},
            {1,{90,100}},
            {2,{60,60}},
            {3,{50,40}},
            {4,{50,60}},
            {5,{130,120}},
        };

        //�e�A�C�e���̍��W
        std::unordered_map<int, POINTS> m_ItemPos_area0{
            {0,{360,555}},
            {1,{839,811}},
            {2,{1000,500}},
            {3,{1292,766}},
            {4,{1436,256}},
            {5,{991,628}},
        };

        std::unordered_map<int, POINTS> m_ItemPos_area1{
           {0,{1220,855}},
           {1,{500,730}},
           {2,{1150,760}},
           {3,{1350,333}},
           {4,{1500,1025}},
           {5,{850,660}},
        };

        std::unordered_map<int, POINTS> m_ItemPos_area2{
           {0,{100,635}},
           {1,{421,780}},
           {2,{773,837}},
           {3,{1006,903}},
           {4,{1511,883}},
           {5,{1095,765}},
        };
    };
}