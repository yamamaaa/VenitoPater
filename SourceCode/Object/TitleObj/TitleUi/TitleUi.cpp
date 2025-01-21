#include "TitleUi.h"
#include "../../ObjectTag/TitleObjectTag.h"

namespace object
{
	TitleUi::TitleUi()
		:ObjectBase(titleObjectTag.TITLEUI)
	{
		//“Ç‚Ýž‚ÝŠÖ˜A
		LoadObject();
	}

	TitleUi::~TitleUi()
	{
		//ˆ—‚È‚µ
	}

	void TitleUi::LoadObject()
	{
		m_ObjPos = { 370.0f,90.0f };
		m_TVScreenPos = { 470.0f,183.0f };

		m_ObjHandle = LoadGraph(JsonManager::ImgData_Instance()->Get_TitleData_Instance()->GetTVData().c_str());
		m_TVScreen_Handle= LoadGraph(JsonManager::ImgData_Instance()->Get_TitleData_Instance()->GetScreenData().c_str());
	}

	void TitleUi::UpdateObj(const float deltatime)
	{
	}

	void TitleUi::DrawObj()
	{
		//‰æ‘œ‚Ì•\Ž¦
		DrawGraph(static_cast<int>(m_TVScreenPos.x), static_cast<int>(m_TVScreenPos.y), m_TVScreen_Handle, TRUE);
		DrawGraph(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), m_ObjHandle, TRUE);
	}
}