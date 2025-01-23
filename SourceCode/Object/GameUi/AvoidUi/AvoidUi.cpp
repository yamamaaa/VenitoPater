#include "AvoidUi.h"
#include "../../ObjectTag/Global_ObjectTag.h"
#include "../../StageObj/AreaNumController/AreaNumController.h"

namespace object
{
	AvoidUi::AvoidUi()
		:ObjectBase(global_objecttag.AVOIDUI)
	{
		//読み込み関連
		LoadObject();
	}

	AvoidUi::~AvoidUi()
	{
		//処理なし
	}

	void AvoidUi::LoadObject()
	{
		//座標初期値
		m_ObjPos = { 180,920 };
		//画像読み込み
		m_ObjHandle = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetUiData_Aboido().c_str());
	}

	void AvoidUi::UpdateObj(const float deltatime)
	{
		//現在のエリア番号を取得
		int areanum = AreaNumController::GetAreaNum();
		
		//Uiを表示できるエリアか？
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
		//回避Ui表示
		if (m_CanDraw)
		{
			DrawGraph(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), m_ObjHandle, TRUE);
		}
	}
}