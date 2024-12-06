#pragma once
#include <unordered_map>
#include"../../../ObjectBase/ObjectBase.h"
#include"../EnemyBase/EnemyLine_Tag.h"
#include "../EnemyManager/EnemyManager.h"

namespace GameSystem
{
	/// <summary>
	/// ��ʃT�C�Y�擾�p
	/// </summary>
	class Window;
}

namespace object
{
	/// <summary>
	/// �G�֘A�̊��N���X
	/// </summary>
	class EnemyBase:public ObjectBase
	{
	public:

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		/// <param name="tagname">�^�O��</param>
		EnemyBase(std::string tagname);

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		virtual ~EnemyBase();

	protected:

		/// <summary>
		/// enemyline�ɓ������Ă��邩
		/// </summary>
		void IsHitEnemyLine();

		/// <summary>
		/// ���ݕ\���ł��邩
		/// </summary>
		/// <returns>true;�\����|false:�\���s��</returns>
		const bool IsObjDraw();

		/// <summary>
		/// ����s�����̃A�N�V����
		/// </summary>
		void AvoidAction();

		/// <summary>
		/// EmyLine�ɓ���������Obj�X�e�[�^�X�̍X�V
		/// </summary>
		void ObjStatusUp();

		/// <summary>
		/// �I�u�W�F�N�g�ޏo����
		/// </summary>
		void ExitObj();

		/// <summary>
		/// �I�u�W�F�N�g�̃��Z�b�g
		/// </summary>
		void ResetObj();

		/// <summary>
		/// ���������X�^�[�A�N�V������̏���
		/// </summary>
		void BeefUpEmyAction();

		/// <summary>
		/// �G�̃A�N�V�����㏈��
		/// </summary>
		void EnemyInAction();

		/// <summary>
		/// ��������emyline�̃C���f�b�N�X�擾
		/// </summary>
		/// <returns>��������emyline�̃C���f�b�N�X</returns>
		const int GetHitLineIndex() const{ return m_HitLineIndex; }
#ifdef DEBUG
		/// <summary>
		/// EnemyLine�̉�ʓ��\��
		/// </summary>
		void EnemyLineDraw();
#endif

		const POINTS m_EMYBOX_SIZE = { 100,50 };		//EmyBox�̃T�C�Y
#ifdef DEBUG
		const VECTOR m_emybox_collar = VGet(0,0,255);	//EmyBox�̃J���[�R�[�h
#endif
		const POINTFLOAT m_EMYBOX_RESETPOS = { 900.0f,0.0f };	//EmyBox�̏����ʒu
		POINTFLOAT m_EnemyBoxPos= m_EMYBOX_RESETPOS;			//EmyBox�̍��W

		int m_ObjImg[4];	//obj�摜

		EnemyID m_Idnumber;	//�G���ʔԍ�

		int m_ObjDrawArea;			//�I�u�W�F�N�g���\���ł���G���A
		bool m_IsActionLine;		//�A�N�V�������C���ʉ߂�����
		bool m_IsAppear;			//�I�u�W�F�N�g���o�������H

		bool m_IsEmyReset ;		//�I�u�W�F�N�g�����Z�b�g���邩

		//enemyline�ʉ߂��Ƃ̉摜�\���ʒu
		std::unordered_map<int, POINTFLOAT> m_DrawObjPos{
			//{appear,{0.0f,0.0f}},
			//{replace,{0.0f,0.0f}},
			//{replace_2,{0.0f,0.0f}},
			//{action,{0.0f,0.0f}},
		};

private:

		/// <summary>
		/// �ǂݍ��݊֘A
		/// </summary>
		void LoadObject() override;

		/// <summary>
		/// �X�V
		/// </summary>
		/// <param name="deltatime"></param>
		void UpdateObj(const float deltatime) override {};

		/// <summary>
		/// �`��
		/// </summary>
		void DrawObj()override {};

		/// <summary>
		/// �ړ�����
		/// </summary>
		void MoveObj(const float deltatime)override {};


		const float m_BeefUp_Speed = 0.5;	//�������ړ����x
		int m_HitLineIndex;			//��������enemyline��index

		float m_BlinkingCount;	//��ʂ�_�ł����鎞��
		float m_ResetCount;		//���Z�b�g����܂ł̃J�E���g

		GameSystem::Window* window;	//window�C���X�^���X

		//enemylinePos
		std::unordered_map<std::string, POINTS> m_EmyLine_Pos{
			{enemyline_tag.APPEAR,{0,50}},
			{enemyline_tag.REPLACE,{0,500}},
			{enemyline_tag.REPLACE_2,{0,800}},
			{enemyline_tag.ACTION,{0,1070}},
		};

#ifdef DEBUG
		//enemyline�̃J���[�R�[�h
		std::unordered_map<std::string, VECTOR> m_collarcode{
			{enemyline_tag.APPEAR,{255,140,0}},		//�I�����W
			{enemyline_tag.REPLACE,{0,255,0}},		//�ΐF
			{enemyline_tag.REPLACE_2,{255,255,0}},	//���F
			{enemyline_tag.ACTION,{255,0,0}},		//�ԐF
		};
#endif
	};
}