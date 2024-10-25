#pragma once
#include<Dxlib.h>
#include<string>

#include"../../JsonMaster/JsonManager/JsonManager.h"

namespace object
{
    /// <summary>
    /// �Q�[���I�u�W�F�N�g�̊��N���X
    /// </summary>
    class ObjectBase
    {
    public:

        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        /// <param name="tagname"></param>
        ObjectBase(std::string tagname);

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        virtual ~ObjectBase();

        /// <summary>
        /// �I�u�W�F�N�g�̏�����
        /// </summary>
        virtual void LoadObject() = 0;

        /// <summary>
        /// �I�u�W�F�N�g�̍X�V
        /// </summary>
        /// <param name="deltatime">�f���^�^�C��</param>
        virtual void UpdateObj(float deltatime) = 0;

        /// <summary>
        /// �I�u�W�F�N�g�̕`��
        /// </summary>
        virtual void DrawObj() = 0;

        /// <summary>
        /// �ړ�����
        /// </summary>
        virtual void MoveObj() {};

        /// <summary>
        /// �I�u�W�F�N�g�̃^�O���擾
        /// </summary>
        /// <returns>�^�O��</returns>
        std::string GetTagName()const { return m_ObjTag; }

        /// <summary>
        /// �ʒu���擾
        /// </summary>
        /// <returns></returns>
        const VECTOR& GetObjPos()const { return m_ObjPos; }

        /// <summary>
        /// �I�u�W�F�N�g�̐�����Ԃ̎擾
        /// </summary>
        /// <returns></returns>
        bool GetAlive() const { return m_Alive; }

        /// <summary>
        /// �I�u�W�F�N�g�̐�����ԃZ�b�g
        /// </summary>
        /// <param name="alive"></param>
        void SetAlive(bool alive) { m_Alive = alive; }

    protected:

        std::string m_ObjTag;   //�I�u�W�F�N�g�^�O

        VECTOR m_ObjPos;        //�ʒu���
        bool m_Alive;           //�������
        int m_ObjHandle;        //�I�u�W�F�N�g�n���h��

        int m_ImgSize_Y;        //�摜�c�T�C�Y
        int m_ImgSize_X;        //�摜���T�C�Y

        float m_MoveSpeed;      //�����X�s�[�h
    };
}