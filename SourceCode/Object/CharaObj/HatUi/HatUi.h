#pragma once
#include<memory>

namespace object
{
	/// <summary>
	/// ��𒆂�Ui�֘A
	/// </summary>
	class HatUi final
	{
	public:

		/// <summary>
		/// ������
		/// </summary>
		static void Initialize();

		/// <summary>
		/// Ui�̕`��
		/// </summary>
		static void DrawUi();

		/// <summary>
		/// �ړ�����
		/// </summary>
		static void MoveUi();

		/// <summary>
		/// �ړ��l�Z�b�g
		/// </summary>
		static void SetMove();

		/// <summary>
		/// Ui��Move��Ԏ擾
		/// </summary>
		/// <returns></returns>
		static const bool GetIsMoveDone() { return hatui->m_IsMoveDone; }

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~HatUi();

	private:

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		HatUi();

		/// <summary>
		/// Ui�̓ǂݍ���
		/// </summary>
		static void LoadUi();

		POINTFLOAT m_UiPos;		//Ui���W

		int m_UiHandle;		//Ui�n���h��

		bool m_IsMoveDone;		//Ui�̓���������������
		bool m_IsMoveDown;		//���ɓ����������邩

		const float m_UIMOVE_POS = -320.0f;		//Ui�ړ����W
		const float m_UIMOVE_SPEED = 30.0f;		//Ui���W�ړ����x

		static std::unique_ptr<HatUi> hatui;	//���g�̎���
	};
}