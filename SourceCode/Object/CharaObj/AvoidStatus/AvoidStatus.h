#pragma once
#include<memory>

namespace object
{
	/// <summary>
	/// �����Ԋ֘A
	/// </summary>
	class AvoidStatus final
	{
	public:

		/// <summary>
		/// ������
		/// </summary>
		static void Initialize();

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~AvoidStatus();

		/// <summary>
		/// �����Ԃ��擾
		/// </summary>
		/// <returns>true:���|false:������Ă��Ȃ�</returns>
		static const bool GetIsAvoid(){ return avoidstatus->m_IsAvoid; }

		/// <summary>
		/// �����Ԃ��Z�b�g
		/// </summary>
		/// <param name="status">true:���|false:������Ă��Ȃ�</param>
		static void SetIsAvoid(const bool status) { avoidstatus->m_IsAvoid= status; }

	private:

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		AvoidStatus();

		/// <summary>
		/// �ǂݍ��݊֘A
		/// </summary>
		static void LoadObjec();

		bool m_IsAvoid ;			//����s������

		static std::unique_ptr<AvoidStatus> avoidstatus;	//���g�̎���
	};
}