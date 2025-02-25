#pragma once
#include <memory>

namespace object
{
    /// <summary>
    /// �^�C����Ԋ֘A
    /// </summary>
    class TimeStatus final
    {
	public:

		/// <summary>
		/// ������
		/// </summary>
		static void Initialize();

		/// <summary>
		/// �^�C����Ԃ��擾
		/// </summary>
		/// <returns>true:�^�C���I�[�o�[|false:�Q�[���N���A</returns>
		static bool GetIsTimeOver() { return timestatus->m_IsTimeOver; }

		/// <summary>
		/// �^�C����Ԃ��Z�b�g
		/// </summary>
		/// <param name="status">true:�^�C���I�[�o�[|false:�Q�[���N���A</param>
		static void SetIsTimeOver(const bool status) { timestatus->m_IsTimeOver = status; }

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~TimeStatus();

	private:

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		TimeStatus();

		/// <summary>
		/// �ǂݍ��݊֘A
		/// </summary>
		static void LoadObject();

		bool m_IsTimeOver;	//�^�C���I�[�o�[������?

		static std::unique_ptr<TimeStatus> timestatus;	//���g�̎���
    };
}