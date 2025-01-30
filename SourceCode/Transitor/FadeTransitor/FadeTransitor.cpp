#include <Dxlib.h>
#include "FadeTransitor.h"
#include "../../MouseStatus/MouseStatus.h"
#include "../../SoundController/SoundController.h"

namespace transitor
{
	std::unique_ptr<FadeTransitor>FadeTransitor::fadetransitor = nullptr;

	FadeTransitor::FadeTransitor()
	{
		//処理なし
	}

	FadeTransitor::~FadeTransitor()
	{
		//処理なし
	}

	void FadeTransitor::Initialize()
	{
		//実態が空ならインスタンス生成
		if (!fadetransitor)
		{
			fadetransitor.reset(new FadeTransitor);
		}

		//読み込み関連
		LoadObject();
	}

	void FadeTransitor::LoadObject()
	{
		fadetransitor->m_IsFadeDone = false;						//終了ステータス初期値
		fadetransitor->m_IsWait = false;							//待機状態初期化
		fadetransitor->m_CanFade = false;							//開始状態初期化
		fadetransitor->m_WaitCount = fadetransitor->m_WAITMAX;		//待ち時間カウント初期化
		fadetransitor->m_Calculation = 0.0f;
		fadetransitor->m_Color = 0;
	}

	void FadeTransitor::FadeInStart(const float deltatime)
	{
		if (!fadetransitor->m_CanFade)
		{
			fadetransitor->m_Color = 0;	//カラーコード初期値
			fadetransitor->m_CanFade = true;
			mousestatus::MouseStatus::SetIsFadeDone(false);		//入力の受付を停止
		}

		if (fadetransitor->m_CanFade)
		{
			if (fadetransitor->m_Color >= m_COLORCODE)
			{
				fadetransitor->m_IsFadeDone = true;			//処理の完了
				fadetransitor->m_Color = m_COLORCODE;		//誤差の修正
				mousestatus::MouseStatus::SetIsFadeDone(true);		//入力の受付を開始
			}
			else
			{
				fadetransitor->m_Color += static_cast<int>(fadetransitor->m_Calculation);
				fadetransitor->m_Calculation += fadetransitor->m_RISESPEED * deltatime;
			}
		}
	}

	void FadeTransitor::FadeOutStart(const float deltatime)
	{
		//スタートを遅らせる
		if (!fadetransitor->m_IsWait)
		{
			WaitTime(deltatime);
		}

		if (!fadetransitor->m_CanFade)
		{
			fadetransitor->m_Color = m_COLORCODE;	//カラーコード初期値
			fadetransitor->m_CanFade = true;
			mousestatus::MouseStatus::SetIsFadeDone(false);		//入力の受付を停止
		}

		if (fadetransitor->m_IsWait)
		{
			sound_controller::SoundController::BGMSoundFadeOut(deltatime);

			if (fadetransitor->m_Color <= 0)
			{
				if (!sound_controller::SoundController::IsDoneSoundFade())
					return;

				fadetransitor->m_IsFadeDone = true;	//処理の完了
				fadetransitor->m_Color = 0;			//誤差の修正
				sound_controller::SoundController::FadeSoundProcessing();
				mousestatus::MouseStatus::SetIsFadeDone(true);		//入力の受付を開始
			}
			else
			{
				//だんだん画面を暗くする
				fadetransitor->m_Color -= static_cast<int>(fadetransitor->m_Calculation);
				fadetransitor->m_Calculation += fadetransitor->m_DROPSPEED * deltatime;
			}
		}
	}

	void FadeTransitor::DrawFade()
	{
		SetDrawBright(fadetransitor->m_Color, fadetransitor->m_Color, fadetransitor->m_Color);
		DrawFormatString(700, 300, GetColor(255, 255, 255), "カラーコード:%d", fadetransitor->m_Color);
	}

	void FadeTransitor::WaitTime(const float deltatime)
	{
		fadetransitor->m_WaitCount -= fadetransitor->m_COUNT_DECREMENT* deltatime;

		if (fadetransitor->m_WaitCount <= 0.0f)
		{
			fadetransitor->m_IsWait = true;
		}
	}

	void FadeTransitor::FadeProcessing()
	{
		//読み込み関連
		LoadObject();
	}
}