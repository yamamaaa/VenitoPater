#pragma once
#include <memory>

namespace object
{
	/// <summary>
	/// �G���A�i���o�[�֘A
	/// </summary>
	class AreaNumController final
	{
	public:

		/// <summary>
		/// ������
		/// </summary>
		static void Initialize();

		/// <summary>
		/// ���݂̃G���A�ԍ����擾
		/// </summary>
		/// <returns>���݂̃G���A�ԍ�</returns>
		static const int GetAreaNum() { return areanum_controller->m_NowAreaNum; }

		/// <summary>
		/// �G���A�ԍ����Z�b�g
		/// </summary>
		/// <param name="areanum">�Z�b�g�������ԍ�</param>
		static void SetAreaNum(const int areanum) { areanum_controller->m_NowAreaNum = areanum; }

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~AreaNumController();

	private:

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		AreaNumController();

		/// <summary>
		/// �ǂݍ��݊֘A
		/// </summary>
		static void LoadObjec();

		int m_NowAreaNum;	//���݂̃G���A�ԍ�

		static std::unique_ptr<AreaNumController> areanum_controller;	//���g�̎���
	};
}