#include "Area.h"
#include "../../ObjectTag/Global_ObjectTag.h"
#include "../AreaNumController/AreaNumController.h"

namespace object
{
	Area::Area()
		:ObjectBase(global_objecttag.STAGE)
	{
		//�ǂݍ��݊֘A
		LoadObject();
	}

	Area::~Area()
	{
		//�����Ȃ�
	}

	void Area::LoadObject()
	{
		//�C���X�^���X����
		AreaNumController::Initialize();

		//���W�ݒ�
		m_ObjPos.x = 0;
		m_ObjPos.y = 0;

		//�摜�̓ǂݍ���
		m_AreaImg[0] = LoadGraph("../Asset/image/stage/area_0.png");
		m_AreaImg[1] = LoadGraph("../Asset/image/stage/area_1.png");
		m_AreaImg[2] = LoadGraph("../Asset/image/stage/area_2.png");
		m_AreaImg[3] = LoadGraph("../Asset/image/stage/area_3.png");

		//�\���G���A�̏����l�Z�b�g
		m_ObjHandle = m_AreaImg[AreaNumController::GetAreaNum()];
	}

	void Area::UpdateObj(const float deltatime)
	{
		//�\���G���A�̍X�V
		m_ObjHandle = m_AreaImg[AreaNumController::GetAreaNum()];
	}

	void Area::DrawObj()
	{
		//�G���A�̕\��
		DrawGraph(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), m_ObjHandle, TRUE);
	}
}