#pragma once
#include"../EnemyBase/EnemyBase.h"

namespace object
{
	/// <summary>
	/// Enemy_Ira�֘A
	/// </summary>
	class Ira:public EnemyBase
	{
	public:

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		Ira();

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~Ira();

	private:

		/// <summary>
		/// �ǂݍ��݊֘A
		/// </summary>
		void LoadObject() override;

		/// <summary>
		/// �X�V
		/// </summary>
		/// <param name="deltatime"></param>
		void UpdateObj(const float deltatime) override;

		/// <summary>
		/// �`��
		/// </summary>
		void DrawObj()override;

		/// <summary>
		/// �ړ�����
		/// </summary>
		void MoveObj(const float deltatime)override;
	};

}