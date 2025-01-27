#pragma once
#include "../../MouseBase/MouseBase.h"

namespace object
{
	/// <summary>
	/// ��𓮍�֘A
	/// </summary>
	class Avoid :public MouseBase
	{
	public:

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		Avoid();

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~Avoid();

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
		void DrawObj()override;

		/// <summary>
		/// �ړ�����
		/// </summary>
		/// <param name="deltatime">�f���^�^�C��</param>
		void MoveObj(const float deltatime)override;

		POINTFLOAT m_DrawPos;	//�摜�\�����W

		const int m_AVOID_NOTNUM = 3;		//����s���s�G���A

		const float m_CLICKCOUNT_MAX = 5.0f;	//�ĂуN���b�N�ł���܂�
		const float m_COUNTSPPED = 20.0f;		//�J�E���g�X�s�[�h

		float m_ClickCount ;		//�N���b�N�ł���܂ł̃J�E���g
		bool m_IsClick = true;		//�N���b�N���ł��邩

#ifdef DEBUG
		std::string m_avoid_status = "";			//�����Ԃ̕\��
		const VECTOR m_collarcode = {255,20,147};	//�J���[�R�[�h
#endif
	};
}