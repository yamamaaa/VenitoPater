#pragma once
#include <memory>

namespace object
{
	/// <summary>
	/// �m���}�֘A
	/// </summary>
	class Norm final
	{
	public:

		/// <summary>
		/// ������
		/// </summary>
		static void Initialize();

		/// <summary>
		/// �m���}�X�V
		/// </summary>
		static void UpdateNorm();

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~Norm();

	private:

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		Norm();

		/// <summary>
		/// �ǂݍ��݊֘A
		/// </summary>
		static void LoadObjec();

		int m_NowNolm;				//���݂̃m���}
		const int m_MAXNOLM = 20;	//�m���}�B���l

		static std::unique_ptr<Norm> norm;	//���g�̎���
	};

}
