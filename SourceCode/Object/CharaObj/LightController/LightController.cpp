#include "LightController.h"

namespace object
{
	//実態を空に
	std::unique_ptr<LightController>LightController::light_controller = nullptr;

	LightController::LightController()
	{
		//処理なし
	}

	LightController::~LightController()
	{
		//処理なし
	}

	void LightController::Initialize()
	{
		//もし実体がなかったらインスタンス生成
		if (!light_controller)
		{
			light_controller.reset(new LightController);
		}

		LoadObject();
	}

	void LightController::LoadObject()
	{
		light_controller->m_LightPos.x = 0;
		light_controller->m_LightPos.y = 0;

		light_controller->m_IsBlinking = false;

		light_controller->m_ShadowHandol = LoadGraph("../Asset/image/light/shadow.png");
		light_controller->m_LightHandol = LoadGraph("../Asset/image/light/light.png");
		light_controller->m_BlackImgHandol = LoadGraph("../Asset/image/light/black.png");
	}

	void LightController::DrawLight()
	{
		/*DrawGraph(0, 0, light_controller->m_ShadowHandol, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_ADD, 225);
		DrawGraph(light_controller->m_LightPos.x, light_controller->m_LightPos.y, light_controller->m_LightHandol, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);*/

		if (light_controller->m_IsBlinking)
		{
			//20カウントのうち15回表示
			light_controller->m_DrawCount = (light_controller->m_DrawCount + 1) % m_PWRIOD;
			if (light_controller->m_DrawCount < m_NUMTIMES)
			{
				DrawGraph(0, 0, light_controller->m_BlackImgHandol, TRUE);
			}
		}
	}
}