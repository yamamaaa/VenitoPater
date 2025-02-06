#pragma once
#include <memory>

namespace mousestatus
{
	/// <summary>
	/// �}�E�X��Ԋ֘A
	/// </summary>
	class MouseStatus final
	{
	public:

		/// <summary>
		/// ������
		/// </summary>
		static void Initialize();

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~MouseStatus();

		/// <summary>
		/// �t�F�[�h�������I����ē��͂��󂯕t���邩�擾
		/// </summary>
		/// <returns>true:���͉�|false:���͕s��</returns>
		static const bool GetIsFadeDone() { return mousestatus->m_IsInput_Fade; }

		/// <summary>
		/// �t�F�[�h��������͂��󂯕t�����Ԃ��Z�b�g
		/// </summary>
		/// <param name="status">true:���͉�|false:���͕s��</param>
		static void SetIsFadeDone(const bool status) { mousestatus->m_IsInput_Fade = status; }

		/// <summary>
		/// ���j���[��ʒ����H
		/// </summary>
		/// <returns>true:���j���[���|false:�ʏ���</returns>
		static bool GetIsMenuMode() { return mousestatus->m_IsInput_Menu; }

		/// <summary>
		/// ���j���[��ʒ����Z�b�g
		/// </summary>
		/// <param name="status">true:���j���[���|false:�ʏ���</param>
		static void SetIsMenuMode(const bool status) { mousestatus->m_IsInput_Menu = status; }

	private:

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		MouseStatus();

		/// <summary>
		/// �ǂݍ��݊֘A
		/// </summary>
		static void LoadObject();

		bool m_IsInput_Fade;		//���͎󂯕t���ł��邩_�t�F�[�h���
		bool m_IsInput_Menu;		//���͎󂯕t���ł��邩_���j���[���

		static std::unique_ptr<class MouseStatus> mousestatus;//���g�̎���
	};
}
