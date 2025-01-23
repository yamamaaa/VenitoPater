#include<Dxlib.h>
#include "HatUi.h"
#include"../AvoidStatus/AvoidStatus.h"
#include"../../../JsonMaster/JsonManager/JsonManager.h"

namespace object
{
	//実態を空に
	std::unique_ptr<HatUi>HatUi::hatui = nullptr;

	HatUi::HatUi()
	{
		//処理なし
	}

	HatUi::~HatUi()
	{
		//処理なし
	}

	void HatUi::Initialize()
	{
		//もし実体がなかったらインスタンス生成
		if (!hatui)
		{
			hatui.reset(new HatUi);
		}

		LoadUi();
	}

	void HatUi::LoadUi()
	{
		hatui->m_UiPos = { 0, 0 };
		hatui->m_UiHandle = -1;
		hatui->m_IsMoveDone = true;
		hatui->m_IsMoveDown = false;

		//画像の読み込み
		hatui->m_UiHandle = LoadGraph(jsonmaster::JsonManager::ImgData_Instance()->Get_PlayData_Instance()->GetUiData_Hat().c_str());
	}

	void HatUi::SetMove()
	{
		//もし回避状態でなければ
		if (!AvoidStatus::GetIsAvoid())
		{
			hatui->m_IsMoveDone = false;	//動き処理セット
			hatui->m_IsMoveDown = true;		//動く方向セット
			hatui->m_UiPos.y = m_UIMOVE_POS;	//座標セット
		}
		else
		{
			hatui->m_IsMoveDone = false;
		}
	}

	void HatUi::MoveUi()
	{
		//下に動かす場合
		if (hatui->m_IsMoveDown)
		{
			//画像を特定の位置まで移動
			hatui->m_UiPos.y += hatui->m_UIMOVE_SPEED;
			if (hatui->m_UiPos.y == 0.0f)
			{
				hatui->m_IsMoveDone = true;
				hatui->m_IsMoveDown = false;
			}
		}
		else
		{
			//画像を特定の位置まで移動
			hatui->m_UiPos.y -= hatui->m_UIMOVE_SPEED;
			if (hatui->m_UiPos.y == m_UIMOVE_POS)
			{
				hatui->m_IsMoveDone = true;
				AvoidStatus::SetIsAvoid(false);		//回避行動の解除
			}
		}
	}

	void HatUi::DrawUi()
	{
		//画像の表示
		DrawGraph(static_cast<int>(hatui->m_UiPos.x), static_cast<int>(hatui->m_UiPos.y), hatui->m_UiHandle, TRUE);
	}
}