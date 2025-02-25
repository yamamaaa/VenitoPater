#pragma once
#include "../../ObjectBase/ObjectBase.h"

namespace object
{
	/// <summary>
	/// �x��Ui�֘A
	/// </summary>
	class WarningUi :public ObjectBase
	{
	public:

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		WarningUi();

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~WarningUi();

	private:

		/// <summary>
		/// �ǂݍ��݊֘A
		/// </summary>
		void LoadObject() override;

		/// <summary>
		/// �X�V
		/// </summary>
		/// <param name="deltatime">�f���^�^�C��</param>
		void UpdateObj(const float deltatime) override;

		/// <summary>
		/// �`��
		/// </summary>
		void DrawObj()override;

		const int m_Hide_DrawArea = 3;			 //Ui��\���ł��Ȃ��G���A
		const float m_WARNING_VALUE = 100.0f;    //�x�����o��HP�̎c�ʒl

		const int m_PWRIOD = 20;	//�\������
		const int m_NUMTIMES = 10;	//�\����

		int m_DrawCount;	//�\���J�E���g
		bool m_CanDraw;		//Ui��\���ł��邩
		bool m_IsBlinking;	//�摜��_�ł����邩
	};
}