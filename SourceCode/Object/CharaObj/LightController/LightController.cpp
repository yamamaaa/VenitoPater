#include "LightController.h"
#include "../../../JsonMaster/JsonManager/JsonManager.h"

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

		light_controller->m_ShadowHandol = LoadGraph(jsonmaster::JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetLightData_Shadow().c_str());
		light_controller->m_LightHandol = LoadGraph(jsonmaster::JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetLightData_Light().c_str());
		light_controller->m_BlackImgHandol = LoadGraph(jsonmaster::JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetLightData_Black().c_str());
	}

	void LightController::DrawLight()
	{
#if DEBUG
#else
		DrawGraph(0, 0, light_controller->m_ShadowHandol, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_ADD, 225);
		DrawGraph(light_controller->m_LightPos.x, light_controller->m_LightPos.y, light_controller->m_LightHandol, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
#endif // DEBUG

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

	void LightController::Processing()
	{
		DeleteGraph(light_controller->m_ShadowHandol);
		DeleteGraph(light_controller->m_LightHandol);
		DeleteGraph(light_controller->m_BlackImgHandol);

		light_controller.reset();
	}
}