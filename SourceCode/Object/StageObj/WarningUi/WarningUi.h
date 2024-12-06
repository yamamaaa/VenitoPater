#pragma once

namespace object
{
	/// <summary>
	/// �x��Ui�֘A
	/// </summary>
	class WarningUi final
	{
	public:

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		WarningUi();

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~WarningUi();

		/// <summary>
		/// �摜�̕\��
		/// </summary>
		void DrawUi();

		/// <summary>
		/// �x����Ԃ̎擾
		/// </summary>
		/// <returns>true:�x��|false:�x���s��</returns>
		const bool GetIsWarning() const{ return m_IsWarning; }

		/// <summary>
		/// �x����Ԃ̃Z�b�g
		/// </summary>
		/// <param name="status">true:�x��|false:�x���s��</param>
		void SetIsWarning(const bool status) {m_IsWarning= status; }

		/// <summary>
		/// �摜��_�ŏ�Ԃɂ��邩
		/// </summary>
		/// <param name="status">true:�_��|false:�_�ł����Ȃ�</param>
		void SetIsBlinking(const bool status) { m_IsBlinking = status;}

	private:

		/// <summary>
		/// �ǂݍ���
		/// </summary>
		void LoadUi();

		const int m_PWRIOD = 20;	//�\������
		const int m_NUMTIMES = 10;	//�\����

		POINTS m_UiPos;	//�摜���W

		int m_DrawCount;	//�\���J�E���g
		int m_UiHandol;		//�摜�n���h��
		bool m_IsWarning;	//�x�����o���邩
		bool m_IsBlinking;	//�摜��_�ł����邩
	};
}