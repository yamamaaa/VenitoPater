#include "Area.h"
#include "../../ObjectTag/Global_ObjectTag.h"
#include "../AreaNumController/AreaNumController.h"

namespace object
{
	Area::Area()
		:ObjectBase(global_objecttag.STAGE)
	{
		//読み込み関連
		LoadObject();
	}

	Area::~Area()
	{
		//処理なし
	}

	void Area::LoadObject()
	{
		//インスタンス生成
		AreaNumController::Initialize();

		//座標設定
		m_ObjPos.x = 0;
		m_ObjPos.y = 0;

		//画像の読み込み
		m_AreaImg[0] = LoadGraph("../Asset/image/stage/area_0.png");
		m_AreaImg[1] = LoadGraph("../Asset/image/stage/area_1.png");
		m_AreaImg[2] = LoadGraph("../Asset/image/stage/area_2.png");
		m_AreaImg[3] = LoadGraph("../Asset/image/stage/area_3.png");

		//表示エリアの初期値セット
		m_ObjHandle = m_AreaImg[AreaNumController::GetAreaNum()];
	}

	void Area::UpdateObj(const float deltatime)
	{
		//表示エリアの更新
		m_ObjHandle = m_AreaImg[AreaNumController::GetAreaNum()];
	}

	void Area::DrawObj()
	{
		//エリアの表示
		DrawGraph(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), m_ObjHandle, TRUE);
	}
}