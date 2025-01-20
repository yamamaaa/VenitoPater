#pragma once
#include<Dxlib.h>
#include<string>
#include"../../JsonMaster/JsonManager/JsonManager.h"
#include"../../Object/ObjectTag/ThreeDays_ObjectTag.h"
#include"../../Collision/Collision.h"
#include"../../Math2D/Math2D.h"

#define DEBUG
using namespace collision;
using namespace math2d;
using namespace objecttag;

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
        /// <param name="tagname">�^�O��</param>
        ObjectBase(std::string tagname);

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        virtual ~ObjectBase();

        /// <summary>
        /// �I�u�W�F�N�g�̓ǂݍ��݊֘A
        /// </summary>
        virtual void LoadObject() = 0;

        /// <summary>
        /// �I�u�W�F�N�g�̍X�V
        /// </summary>
        /// <param name="deltatime">�f���^�^�C��</param>
        virtual void UpdateObj(const float deltatime) = 0;

        /// <summary>
        /// �I�u�W�F�N�g�̕`��
        /// </summary>
        virtual void DrawObj() = 0;

        /// <summary>
        /// �ړ�����
        /// </summary>
        virtual void MoveObj(const float deltatime) {};

        /// <summary>
        /// �I�u�W�F�N�g�̃^�O���擾
        /// </summary>
        /// <returns>�^�O��</returns>
        const std::string GetTagName()const { return m_ObjTag; }

        /// <summary>
        /// �ʒu���擾
        /// </summary>
        /// <returns>�ʒu���</returns>
        const auto GetObjPos()const { return m_ObjPos; }

        /// <summary>
        /// �I�u�W�F�N�g�̐�����Ԃ̎擾
        /// </summary>
        /// <returns>true:����|false:���S</returns>
        const bool GetAlive() const { return m_Alive; }

        /// <summary>
        /// �I�u�W�F�N�g�̐�����ԃZ�b�g
        /// </summary>
        /// <param name="alive">true:����|false:���S</param>
        const void SetAlive(const bool alive) { m_Alive = alive; }

    protected:

        std::string m_ObjTag;   //�I�u�W�F�N�g�^�O

        POINTFLOAT m_ObjPos;    //�I�u�W�F�N�g���W
        POINTS m_ObjSize;       //�I�u�W�F�N�g�T�C�Y
        POINTS m_DrawOffset;    // �����蔻�肩��̉��������炵��

        bool m_Alive;           //�������
        int m_ObjHandle;        //�I�u�W�F�N�g�n���h��

        float m_MoveSpeed;      //�����X�s�[�h
        float m_MaxMoveSpeed;   //�ő�ړ����x

#ifdef DEBUG
        const int m_DEBUG_FONTSIZE = 16;           //�t�H���g�T�C�Y
#endif // DEBUG
    };
}