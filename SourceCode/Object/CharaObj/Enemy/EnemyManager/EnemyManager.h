#pragma once
#include <memory>
#include <unordered_map>
#include "../EnemyManager/EnemyID.h"

using namespace objecttag;

namespace object
{
	/// <summary>
	/// 敵関連の管理クラス
	/// </summary>
	class EnemyManager final
	{
	public:

		/// <summary>
		/// 初期化
		/// </summary>
		static void Initialize();

		/// <summary>
		/// 敵の出現設定
		/// </summary>
		static void EmyAppearSetting();

		/// <summary>
		/// 出現状態のセット
		/// </summary>
		/// <param name="id">敵識別番号</param>
		/// <param name="status">true:出現|false:出現していない</param>
		static void SetIsAppear(const EnemyID id,const bool status) { enemymanager->m_IsAppear[id] = status; }

		/// <summary>
		/// 出現状態の取得
		/// </summary>
		/// <param name="id">敵識別番号</param>
		/// <returns>出現状態</returns>
		static int GetIsAppear(const EnemyID id) { return enemymanager->m_IsAppear[id]; }

		/// <summary>
		/// 現在の出現総数セット
		/// </summary>
		/// <param name="num">出現数</param>
		static void SetAppearNumNow(const int num) { enemymanager->m_AppearNumNow = num; }

		/// <summary>
		/// 現在の出現総数の取得
		/// </summary>
		/// <param name="num">出現数</param>
		static int GetAppearNumNow() { return enemymanager->m_AppearNumNow; }

		/// <summary>
		/// 強化モンスターのアクションライン状態をセット
		/// </summary>
		/// <param name="status">true:ライン到達|false:到達していない</param>
		static void SetBeefUpEmyIsAction(const bool status) { enemymanager->m_BeefUpEmy_IsAction = status; }

		/// <summary>
		/// 強化モンスターがアクションラインに到達したか取得
		/// </summary>
		/// <returns>true:ライン到達|false:到達していない</returns>
		static bool GetBeefUpEmyIsAction() { return enemymanager->m_BeefUpEmy_IsAction; }

		/// <summary>
		/// 敵が動ける状態かセット
		/// </summary>
		/// <param name="status">true:可能|false:不可能</param>
		static void SetCanMove(const bool status) { enemymanager->m_CanMove = status; }

		/// <summary>
		/// 敵が動ける状態か取得
		/// </summary>
		/// <returns>true:可能|false:不可能</returns>
		static bool GetCanMove() { return enemymanager->m_CanMove; }

		//削除予定
		static void D_DrawStatus();

		/// <summary>
		/// デストラクタ
		/// </summary>
		~EnemyManager();

	private:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		EnemyManager();

		/// <summary>
		/// 読み込み関連
		/// </summary>
		static void LoadObjec();

		/// <summary>
		/// 敵の排出設定
		/// </summary>
		static void EmyRandlSetting();

		/// <summary>
		/// 出現カウント処理
		/// </summary>
		static void AppearCount();

		/// <summary>
		/// 出現処理
		/// </summary>
		static void EnemyAppear();


		EnemyID m_EmyId_Data;	//EnemyID一時保管用

		static const int m_EMYSCREEN_MAX = 3;	//画面内敵の出現総数
		static const int m_APPEAR_RANGE = 4;	//出現時のランダム範囲

		const float m_APPEARCOUNT_MAX = 600.0f;	//再び出現できるまでのカウント
		const float m_COUNT_DECREMENT = 5.0f;	//カウント減分値

		float m_AppearCount;					//敵の排出カウント
		int m_AppearNumNow ;					//現在の画面内敵の総数

		bool m_CanAppear = true;				//出現できるか
		bool m_BeefUpEmy_IsAction = false;		//特定の敵のアクションフラグ
		bool m_CanMove = true;					//動ける状態か

		//敵の出現フラグ
		std::unordered_map<EnemyID,bool> m_IsAppear{
			{memini,false},
			{nil,false},
			{spero,false},
			{ira,false},
		};

		static std::unique_ptr<EnemyManager> enemymanager;	//自身の実態
	};

}