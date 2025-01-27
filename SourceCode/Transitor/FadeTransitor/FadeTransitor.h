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
		/// �t�F�[�h�C��������
		/// </summary>
		/// <param name="wait">true:start�����炷|false:start�����炳�Ȃ�</param>
		void FadeInStart(bool wait);

		/// <summary>
		/// �t�F�[�h����������������
		/// </summary>
		/// <returns>true:����|false:������</returns>
		const bool IsFadeDone() const { return m_IsFadeDone; }

		/// <summary>
		/// �t�F�[�h�㏈��
		/// </summary>
		/// <returns></returns>
		const void FadeProcessing();

	private:

		/// <summary>
		/// ��莞�ԑ҂�
		/// </summary>
		void WaitTime();

		/// <summary>
		/// �ǂݍ��݊֘A
		/// </summary>
		void LoadObject();

		const float m_DROPSPEED = 5.0f;				//�������x
		const float m_RISESPEED = 0.01f;			//�������x

		const int m_COLORCODE = 255;	//�J���[�R�[�h

		const float m_WAITMAX = 50.0f;			//�҂�����
		const float m_COUNT_DECREMENT = 1.0f;	//�J�E���g�����l

		int m_Color;					//�J���[�R�[�h
		float m_Calculation;			//�Z�o

		bool m_IsFadeDone;				//�������I�������
		bool m_WaitDone;				//��莞�ԑ҂�����
		bool m_CanFade;					//�t�F�[�h�J�n�ł��邩

		float m_WaitCount;				//��莞�ԃJ�E���g
	};

}