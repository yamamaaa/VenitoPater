#include "TitleUi.h"
#include "../../ObjectTag/TitleObjectTag.h"

namespace object
{
	TitleUi::TitleUi()
		:ObjectBase(titleObjectTag.TITLEUI)
	{
		//読み込み関連
		LoadObject();
	}

	TitleUi::~TitleUi()
	{
		//処理なし
	}

	void TitleUi::LoadObject()
	{
		m_ObjPos = { 370.0f,90.0f };
		m_TVScreenPos = { 470.0f,183.0f };

		m_ObjHandle = LoadGraph("../Asset/image/title/tv.png");
		m_TVScreen_Handle= LoadGraph("../Asset/image/title/screen.png");
	}

	void TitleUi::UpdateObj(const float deltatime)
	{
	}

	void TitleUi::DrawObj()
	{
		//画像の表示
		DrawGraph(static_cast<int>(m_TVScreenPos.x), static_cast<int>(m_TVScreenPos.y), m_TVScreen_Handle, TRUE);
		DrawGraph(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), m_ObjHandle, TRUE);
	}
}