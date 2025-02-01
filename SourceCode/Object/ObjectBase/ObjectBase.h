#pragma once
#include<Dxlib.h>
#include<string>
#include"../../JsonMaster/JsonManager/JsonManager.h"
#include"../../Object/ObjectTag/Play_ObjectTag.h"
#include"../../Collision/Collision.h"
#include"../../Math2D/Math2D.h"

#define DEBUG
using namespace jsonmaster;
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

    protected:

        std::string m_ObjTag;   //�I�u�W�F�N�g�^�O

        POINTFLOAT m_ObjPos;    //�I�u�W�F�N�g���W
        POINTS m_ObjSize;       //�I�u�W�F�N�g�T�C�Y
        POINTS m_DrawOffset;    // �����蔻�肩��̉��������炵��

        int m_ObjHandle;        //�I�u�W�F�N�g�n���h��
    };
}