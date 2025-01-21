#include <Dxlib.h>
#include "FadeTransitor.h"

namespace transitor
{
	FadeTransitor::FadeTransitor()
	{
		//読み込み関連
		LoadObject();
	}

	FadeTransitor::~FadeTransitor()
	{
		//処理無し
	}

	const void FadeTransitor::FadeProcessing()
	{
		//読み込み関連
		LoadObject();
	}

	void FadeTransitor::WaitTime()
	{
		if (!m_WaitDone)
		{
			m_WaitCount -= m_COUNT_DECREMENT;

			if (m_WaitCount <= 0.0f)
			{
				m_WaitDone = true;
			}
		}
	}

	void FadeTransitor::LoadObject()
	{
		m_IsFadeDone = false;			//終了ステータス初期値
		m_WaitDone = false;				//待機状態初期化
		m_CanFade = false;				//開始状態初期化
		m_WaitCount = m_WAITMAX;		//待ち時間カウント初期化
		m_Calculation = 0.0f;
	}

	void FadeTransitor::FadeOutStart(bool wait)
	{
		//スタートを遅らせるか
		if (wait)
		{
			WaitTime();	//遅らせるならカウント
		}
		else
		{
			m_WaitDone = true;
		}

		if (!m_CanFade)
		{
			m_Collar = m_COLLARCODE;	//カラーコード初期値
			m_CanFade = true;
		}

		if (m_WaitDone)
		{
			//だんだん画面を暗くする
			SetDrawBright(m_Collar, m_Collar, m_Collar);
			m_Collar -= static_cast<int>(m_Calculation);
			m_Calculation += m_DROPSPEED;

			if (m_Collar <= 0)
			{
				m_IsFadeDone = true;	//処理の完了
				m_Collar = 0;			//誤差の修正
			}
		}

		DrawFormatString(700, 300, GetColor(255, 255, 255), "カラーコード:%d", m_Collar);
	}

	void FadeTransitor::FadeInStart(bool wait)
	{
		//スタートを遅らせるか
		if (wait)
		{
			WaitTime();		//遅らせるならカウント
		}
		else
		{
			m_WaitDone = true;
		}

		if (!m_CanFade)
		{
			m_Collar = 0;	//カラーコード初期値
			m_CanFade = true;
		}

		if (m_WaitDone)
		{
			//だんだん画面を明るく
			SetDrawBright(m_Collar, m_Collar, m_Collar);
			m_Collar += static_cast<int>(m_Calculation);
			m_Calculation += m_RISESPEED;

			if (m_Collar >= m_COLLARCODE)
			{
				m_IsFadeDone = true;			//処理の完了
				m_Collar = m_COLLARCODE;		//誤差の修正
			}
		}

		DrawFormatString(700, 300, GetColor(255, 255, 255), "カラーコード:%d", m_Collar);
	}
}