#pragma once
#include <Dxlib.h>
#include <memory>

namespace object
{
	/// <summary>
	/// �Ɩ��֘A�N���X
	/// </summary>
	class LightController final
	{
	public:

		/// <summary>
		/// ������
		/// </summary>
		static void Initialize();

		/// <summary>
		/// ���C�g�̕`��
		/// </summary>
		static void DrawLight();

		/// <summary>
		/// ��ʂ�_�ł�������
		/// </summary>
		static void ScreenBlinking();

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~LightController();

	private:

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		LightController();

		/// <summary>
		/// �ǂݍ��݊֘A
		/// </summary>
		static void LoadObject();

		int m_DrawCount;	//�_�ŗp�摜�\���J�E���g

		static const int m_PWRIOD = 20;		//�\������
		static const int m_NUMTIMES = 15;	//�\����

		int m_ShadowHandol;		//�e�摜�n���h��
		int m_LightHandol;		//���C�g�摜�n���h��
		int m_BlackImgHandol;	//���摜�n���h��

		POINTS m_LightPos;	//���C�g���W

		static std::unique_ptr<LightController> light_controller;	//���g�̎���
	};
}