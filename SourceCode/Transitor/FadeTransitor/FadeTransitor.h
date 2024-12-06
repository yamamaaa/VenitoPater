#pragma once

namespace transitor
{
	class FadeTransitor
	{
	public:

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		FadeTransitor();

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~FadeTransitor();

		/// <summary>
		/// �t�F�[�h�A�E�g������
		/// </summary>
		/// <param name="wait">true:start�����炷|false:start�����炳�Ȃ�</param>
		void FadeOutStart(bool wait);

		/// <summary>
		/// �t�F�[�h����������������
		/// </summary>
		/// <returns>true:����|false:������</returns>
		const bool IsFadeDone() const { return m_IsFadeDone; }

	private:

		/// <summary>
		/// WaitTimer�ň�莞�ԑ҂�
		/// </summary>
		void WaitTimerStart();

		/// <summary>
		/// �ǂݍ��݊֘A
		/// </summary>
		void LoadObject();

		const int m_DROPSPEED = 15;		//�������x
		const int m_COLLARCODE = 255;	//�J���[�R�[�h

		int m_DropCollar;				//�����J���[�R�[�h

		bool m_IsFadeDone;				//�������I�������
		bool m_WaitDone;				//��莞�ԑ҂�����

		float m_WaitCount;				//��莞�ԃJ�E���g
	};

}