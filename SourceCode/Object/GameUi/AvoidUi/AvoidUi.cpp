#include "AvoidUi.h"
#include "../../ObjectTag/Global_ObjectTag.h"
#include "../../StageObj/AreaNumController/AreaNumController.h"

namespace object
{
	AvoidUi::AvoidUi()
		:ObjectBase(global_objecttag.AVOIDUI)
	{
		//�ǂݍ��݊֘A
		LoadObject();
	}

	AvoidUi::~AvoidUi()
	{
		//�����Ȃ�
	}

	void AvoidUi::LoadObject()
	{
		//���W�����l
		m_ObjPos = { 180,920 };
		//�摜�ǂݍ���
		m_ObjHandle = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetUiData_Aboido().c_str());
	}

	void AvoidUi::UpdateObj(const float deltatime)
	{
		//���݂̃G���A�ԍ����擾
		int areanum = AreaNumController::GetAreaNum();
		
		//Ui��\���ł���G���A���H
		if (areanum == m_Hide_DrawArea)
		{
			m_CanDraw = false;
		}
		else
		{
			m_CanDraw = true;
		}
	}

	void AvoidUi::DrawObj()
	{
		//���Ui�\��
		if (m_CanDraw)
		{
			DrawGraph(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), m_ObjHandle, TRUE);
		}
	}
}