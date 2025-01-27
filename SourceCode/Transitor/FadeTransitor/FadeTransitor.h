#pragma once
#include<memory>

namespace transitor
{
	/// <summary>
	/// ��ʐ؂�ւ��֘A_�t�F�[�h
	/// </summary>
	class FadeTransitor final
	{
	public:

		/// <summary>
		/// ������
		/// </summary>
		static void Initialize();

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~FadeTransitor();

		/// <summary>
		/// �t�F�[�h�C��������
		/// </summary>
		/// <param name="deltatime">�f���^�^�C��</param>
		static void FadeInStart(const float deltatime);

		/// <summary>
		/// �t�F�[�h�A�E�g������
		/// </summary>
		/// <param name="deltatime">�f���^�^�C��</param>
		static void FadeOutStart(const float deltatime);

		/// <summary>
		/// �t�F�[�h�̕`��
		/// </summary>
		static void DrawFade();

		/// <summary>
		/// �t�F�[�h����������������
		/// </summary>
		/// <returns>true:����|false:������</returns>
		static const bool IsFadeDone() { return fadetransitor->m_IsFadeDone; }

		/// <summary>
		/// �t�F�[�h�㏈��
		/// </summary>
		/// <returns></returns>
		static const void FadeProcessing();

	private:

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		FadeTransitor();

		/// <summary>
		/// ��莞�ԑ҂�
		/// </summary>
		/// <param name="deltatime">�f���^�^�C��</param>
		static void WaitTime(const float deltatime);

		/// <summary>
		/// �ǂݍ��݊֘A
		/// </summary>
		static void LoadObject();

		const float m_DROPSPEED = 50.0f;		//�������x
		const float m_RISESPEED = 1.0f;			//�������x

		static const int m_COLORCODE = 255;	//�J���[�R�[�h

		const float m_WAITMAX = 1.2f;			//�҂�����
		const float m_COUNT_DECREMENT = 3.0f;	//�J�E���g�����l

		int m_Color;					//�J���[�R�[�h
		float m_Calculation;			//�Z�o

		bool m_IsFadeDone;				//�������I�������
		bool m_IsWait;					//��莞�ԑ҂�
		bool m_CanFade;					//�t�F�[�h�J�n�ł��邩

		float m_WaitCount;				//��莞�ԃJ�E���g

		static std::unique_ptr<class FadeTransitor> fadetransitor;//���g�̎���
	};

}