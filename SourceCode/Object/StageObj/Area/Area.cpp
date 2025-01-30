#include "Area.h"
#include "../../ObjectTag/Global_ObjectTag.h"
#include "../AreaNumController/AreaNumController.h"
#include "../../../SoundController/SoundController.h"

namespace object
{
	Area::Area()
		:ObjectBase(global_objecttag.AREA)
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
		for (int i = 0; i < 4; i++)
		{
			m_AreaImg[i] = LoadGraph(JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetStageData(i).c_str());
		}

		//表示エリアの初期値セット
		m_ObjHandle = m_AreaImg[AreaNumController::GetAreaNum()];

		sound_controller::SoundController::AddSoundData("../Asset/sound/play/bgm.mp3","bgm", 150, true);
	}

	void Area::UpdateObj(const float deltatime)
	{
		//表示エリアの更新
		m_ObjHandle = m_AreaImg[AreaNumController::GetAreaNum()];
		sound_controller::SoundController::StartSound("bgm");
	}

	void Area::DrawObj()
	{
		//エリアの表示
		DrawGraph(static_cast<int>(m_ObjPos.x), static_cast<int>(m_ObjPos.y), m_ObjHandle, TRUE);
	}
}