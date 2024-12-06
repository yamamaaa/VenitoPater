#include "Norm.h"
#include "../../ObjectManager/ObjectManager.h"

namespace object
{
	//���̂̒��g�����
	std::unique_ptr<Norm>Norm::norm = nullptr;

	Norm::Norm()
	{
		//�����Ȃ�
	}

	Norm::~Norm()
	{
		//�����Ȃ�
	}

	void Norm::Initialize()
	{
		//���Ԃ��Ȃ�������
		if (!norm)
		{
			//�C���X�^���X����
			norm.reset(new Norm);
		}

		LoadObjec();
	}

	void Norm::LoadObjec()
	{
		//�m���}������
		norm->m_NowNolm = 0;
	}

	void Norm::UpdateNorm()
	{
		norm->m_NowNolm++;

		//�����m���}�B��������
		if (norm->m_NowNolm == norm->m_MAXNOLM)
		{
			//�Q�[���N���A
			ObjectManager::SetGameState(GameClear);
		}
	}
}


