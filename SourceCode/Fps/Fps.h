#pragma once
#include <DxLib.h>

namespace Fps
{
	class Fps
	{
	public:

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		Fps();

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~Fps();

		/// <summary>
		/// �X�V����
		/// </summary>
		void Update();

		/// <summary>
		/// �f���^�^�C���擾
		/// </summary>
		/// <returns>�f���^�^�C��</returns>
		float GetDeltaTime()const { return m_deltaTime; }

	private:

		float m_nowTime;		//���݂̎���
		float m_prevTime;		//�ߋ��̎���
		float m_deltaTime;		//�f���^�^�C��
	};
}

