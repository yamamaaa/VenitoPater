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
		/// ���͂��󂯕t�����Ԃ��擾
		/// </summary>
		/// <returns>true:���͉�|false:���͕s��</returns>
		static const bool GetIsFadeDone() { return mousestatus->m_IsInput; }

		/// <summary>
		/// ���͂��󂯕t�����Ԃ��Z�b�g
		/// </summary>
		/// <param name="status">true:���͉�|false:���͕s��</param>
		static void SetIsFadeDone(const bool status) { mousestatus->m_IsInput = status; }

	private:

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		MouseStatus();

		/// <summary>
		/// �ǂݍ��݊֘A
		/// </summary>
		static void LoadObject();

		bool m_IsInput;		//���͎󂯕t���ł��邩

		static std::unique_ptr<class MouseStatus> mousestatus;//���g�̎���
	};
}
