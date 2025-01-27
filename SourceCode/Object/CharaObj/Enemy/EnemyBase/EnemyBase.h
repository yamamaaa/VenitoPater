#pragma once
#include <unordered_map>
#include"../../../ObjectBase/ObjectBase.h"
#include"../EnemyBase/EnemyLine_Tag.h"
#include "../EnemyManager/EnemyManager.h"
#include "../../../Time/TimeStatus/TimeStatus.h"

namespace GameSystem
{
	/// <summary>
	/// 画面サイズ取得用
	/// </summary>
	class Window;
}

namespace object
{
	/// <summary>
	/// 敵関連の基底クラス
	/// </summary>
	class EnemyBase :public ObjectBase
	{
	public:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="tagname">タグ名</param>
		EnemyBase(std::string tagname);

		/// <summary>
		/// デストラクタ
		/// </summary>
		virtual ~EnemyBase();

	protected:

		/// <summary>
		/// enemylineに当たっているか
		/// </summary>
		void IsHitEnemyLine();

		/// <summary>
		/// 現在表示できるか
		/// </summary>
		/// <returns>true;表示可|false:表示不可</returns>
		const bool IsObjDraw();

		/// <summary>
		/// 回避行動時のアクション
		/// </summary>
		/// <param name="deltatime">デルタタイム</param>
		void AvoidAction(const float deltatime);

		/// <summary>
		/// EmyLineに当たったらObjステータスの更新
		/// </summary>
		void ObjStatusUp();

		/// <summary>
		/// オブジェクト退出処理
		/// </summary>
		/// <param name="deltatime">デルタタイム</param>
		void ExitObj(const float deltatime);

		/// <summary>
		/// オブジェクトのリセット
		/// </summary>
		void ResetObj();

		/// <summary>
		/// 敵のアクション後処理
		/// </summary>
		void EnemyInAction();

		/// <summary>
		/// 当たったemylineのインデックス取得
		/// </summary>
		/// <returns>当たったemylineのインデックス</returns>
		const int GetHitLineIndex() const { return m_HitLineIndex; }
#ifdef DEBUG
		/// <summary>
		/// EnemyLineの画面内表示
		/// </summary>
		void EnemyLineDraw();
#endif

		const POINTS m_EMYBOX_SIZE = { 100,50 };		//EmyBoxのサイズ
#ifdef DEBUG
		const VECTOR m_emybox_collar = VGet(0, 0, 255);	//EmyBoxのカラーコード
#endif
		const POINTFLOAT m_EMYBOX_RESETPOS = { 900.0f,0.0f };	//EmyBoxの初期位置
		POINTFLOAT m_EnemyBoxPos = m_EMYBOX_RESETPOS;			//EmyBoxの座標

		int m_ObjImg[4];	//obj画像

		EnemyID m_IDnumber;	//敵識別番号

		int m_ObjDrawArea;			//オブジェクトが表示できるエリア
		bool m_IsActionLine;		//アクションライン通過したか
		bool m_CanAvoid;			//回避行動できるか
		bool m_IsAppear;			//オブジェクトが出現中か？

		bool m_IsEmyReset;		//オブジェクトをリセットするか

		//enemyline通過ごとの画像表示位置
		std::unordered_map<int, POINTFLOAT> m_DrawObjPos{};

	private:

		/// <summary>
		/// 読み込み関連
		/// </summary>
		void LoadObject() override;

		/// <summary>
		/// 更新
		/// </summary>
		/// <param name="deltatime">デルタタイム</param>
		void UpdateObj(const float deltatime) override {};

		/// <summary>
		/// 描画
		/// </summary>
		void DrawObj()override {};

		/// <summary>
		/// 移動処理
		/// </summary>
		/// <param name="deltatime">デルタタイム</param>
		void MoveObj(const float deltatime)override {};

		const float m_COUNTSPPED_RESET = 0.1f;	//敵のリセットを行うまで(カウントスピード)
		const float m_COUNTRESET_MAX = 100.0f;	//敵のリセットを行うまで(カウント最大値)

		const float m_COUSPPED_BLINKING = 0.1f;	//画面の点滅時間(カウントスピード)
		const float m_BLINKING_COUMAX = 20.0f;	//画面の点滅時間(カウント最大値)

		int m_HitLineIndex;		//当たったenemylineのindex
		float m_BlinkingCount;	//画面を点滅させる時間
		float m_ResetCount;		//リセットするまでのカウント

		GameSystem::Window* window;	//windowインスタンス

		//enemylinePos
		std::unordered_map<std::string, POINTS> m_EmyLine_Pos{
			{enemyline_tag.APPEAR,{0,50}},
			{enemyline_tag.REPLACE,{0,500}},
			{enemyline_tag.REPLACE_2,{0,800}},
			{enemyline_tag.ACTION,{0,1070}},
		};

#ifdef DEBUG
		//enemylineのカラーコード
		std::unordered_map<std::string, VECTOR> m_collarcode{
			{enemyline_tag.APPEAR,{255,140,0}},		//オレンジ
			{enemyline_tag.REPLACE,{0,255,0}},		//緑色
			{enemyline_tag.REPLACE_2,{255,255,0}},	//黄色
			{enemyline_tag.ACTION,{255,0,0}},		//赤色
		};
#endif
	};
}