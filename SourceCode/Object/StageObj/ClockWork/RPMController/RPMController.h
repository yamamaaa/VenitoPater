#pragma once
#include <memory>

namespace object
{
	/// <summary>
	/// �[���}�C��]�ʊ֘A
	/// </summary>
	class RPMController final
	{
	public:

		/// <summary>
		/// ������
		/// </summary>
		static void Initialize();

		/// <summary>
		/// ��]��Hp�̎擾
		/// </summary>
		/// <returns>��]��Hp</returns>
		static const float GetRPMHp() { return rpm_controller->m_RPMHp; }

		/// <summary>
		/// ��]��Hp�̃Z�b�g
		/// </summary>
		/// <param name="areanum">�Z�b�g���������l</param>
		static void SetRPMHp(const float rpmhp) { rpm_controller->m_RPMHp = rpmhp; }

		/// <summary>
		/// ��]��HP�ő�l�擾
		/// </summary>
		/// <returns>��]��HP�ő�l</returns>
		static const float GetRPMHpMax() { return rpm_controller->m_RPMHPMAX; }

		/// <summary>
		/// ��]�����ʎ擾
		/// </summary>
		/// <returns>��]������</returns>
		static const float GetRPMDecrement() { return rpm_controller->m_RPM_DECREMENT; }

		/// <summary>
		/// ��]��HP�̏�Ԃ��擾
		/// </summary>
		/// <returns>true:HP0�ȉ�|false:HP0�ȏ�</returns>
		static const bool GetIsRPMLost() { return rpm_controller->m_IsRPMLost; }

		/// <summary>
		/// ��]��HP�̏�Ԃ��Z�b�g
		/// </summary>
		/// <param name="status">true:HP0�ȉ�|false:HP0�ȏ�</param>
		static void SetIsRPMLost(const bool status) { rpm_controller->m_IsRPMLost = status; }

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~RPMController();

	private:

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		RPMController();

		/// <summary>
		/// �ǂݍ��݊֘A
		/// </summary>
		static void LoadObjec();

		const float m_RPM_DECREMENT = 0.1f;		//��]������
		const float m_RPMHPMAX = 500;			//��]��HP�ő�l

		float m_RPMHp;						   //�[���}�C��]��HP
		bool m_IsRPMLost;					   //��]�ʂ�0�ɂȂ�����

		static std::unique_ptr<RPMController> rpm_controller;	//���g�̎���
	};
}