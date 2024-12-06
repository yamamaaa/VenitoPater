#pragma once
#include "../../ObjectBase/ObjectBase.h"

namespace object
{
	/// <summary>
	/// �G���A�֘A
	/// </summary>
	class Area :public ObjectBase
	{
	public:

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		Area();

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~Area();

	private:

		/// <summary>
		/// �ǂݍ��݊֘A
		/// </summary>
		void LoadObject() override;

		/// <summary>
		/// �I�u�W�F�N�g�̍X�V
		/// </summary>
		/// <param name="deltatime">�f���^�^�C��</param>
		void UpdateObj(const float deltatime) override;

		/// <summary>
		/// �I�u�W�F�N�g�̕`��
		/// </summary>
		void DrawObj() override;

		int m_AreaImg[4];       //�e�G���A�̉摜
	};
}