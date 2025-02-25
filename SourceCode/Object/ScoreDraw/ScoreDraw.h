#pragma once

#include"../../Object/ObjectBase/ObjectBase.h"


/// <summary>
/// 画面サイズ関連
/// </summary>
namespace GameSystem
{
	class Window;
}

namespace object
{
    /// <summary>
    /// スコア関連
    /// </summary>
    class ScoreDraw :public ObjectBase
    {
	public:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		ScoreDraw();

		/// <summary>
		/// デストラクタ
		/// </summary>
		~ScoreDraw();

	private:

		/// <summary>
		/// 読み込み関連
		/// </summary>
		void LoadObject() override;

		/// <summary>
		/// ハイスコアの取得
		/// </summary>
		void HighScoreGet();

		/// <summary>
		/// ハイスコアのセット
		/// </summary>
		void HighScoreSet();

		/// <summary>
		/// 更新
		/// </summary>
		/// <param name="deltatime">デルタタイム</param>
		void UpdateObj(const float deltatime) override;

		/// <summary>
		/// 表示用スコアのセット
		/// </summary>
		/// <param name="drawobj">表示用obj</param>
		/// <param name="ans">総数</param>
		/// <param name="isset">セットするか</param>
		/// <param name="deltatime">デルタタイム</param>
		void DrawScoreSet(int& drawobj, int ans, bool& isset, const float deltatime);

		/// <summary>
		/// クリックUiのアニメーションを行う
		/// </summary>
		/// <param name="deltatime">デルタタイム</param>
		void ClickUiMoveAnim(const float deltatime);

		/// <summary>
		/// ハイスコアの表示
		/// </summary>
		void HighScoreDraw();

		/// <summary>
		/// 描画
		/// </summary>
		void DrawObj()override;

		std::string m_JsonTag[6];	//サウンド用Jsonタグ

		GameSystem::Window* window;
		POINTS m_WindowSize;

		int m_FontHandle_Text;		//フォントハンドル_テキスト
		int m_FontHandle_Score;		//フォントハンドル_スコア
		int m_FontHandle_Item;		//フォントハンドル_アイテム数

		const POINTS m_FONTSIZE_TEXT = { 30,10 };	 //フォントサイズ_テキスト
		const POINTS m_FONTSIZE_SCORE = { 150,60 };  //フォントサイズ_スコア
		const POINTS m_FONTSIZE_ITEM = { 100,20 };     //フォントサイズ_アイテム数

		POINTFLOAT m_UiPos;		//クリックUi座標
		POINTFLOAT m_NItem_Pos; //アイテム数座標_ノーマル
		POINTFLOAT m_RItem_Pos; //アイテム数座標_レア

		std::string m_ItemText = "%d個";
		std::string m_ScoreText = "%d点";

		float m_Compute_Spped;							//計算スピード
		const float m_COMPUTE_SPEED_ITEM = 240.0f;		//計算スピード_アイテム
		const float m_COMPUTE_SPEED_SCORE = 2400.0f;	//計算スピード_スコア

		const float m_COUNT_DECREMENT = 2.4f;	//カウント減らし量
		const float m_WEIT_MAX = 2.4f;			//待ち時間

		bool m_IsNItemSet;		//アイテム数をセットしたか_ノーマル
		bool m_IsRItemSet;		//アイテム数をセットするか
		bool m_IsScoreSet;		//スコアをセットしたか

		bool m_IsWait;		//待ち時間を設けるか
		bool m_CanClick;	//クリックできるか
		bool m_IsClick;		//クリックしたか

		float m_WaitCount;	//待ち時間カウント

		int m_Score;		//スコア
		int m_Score_Draw;	//スコア_表示用
		int m_HighScore;	//ハイスコア
		int m_HighScore_Draw;	//ハイスコア_表示用

		bool m_IsHighScore_Up;		//ハイスコアを更新したか

		int m_NItemNum;		//アイテム総数_ノーマル
		int m_NItem_Draw;	//アイテム_表示用_ノーマル

		int m_RItemNum;		//アイテム総数_レア
		int m_RItem_Draw;	//アイテム_表示用_レア

		bool m_IsMove_Up;       //移動向きを上に切り替えるか

		const float m_MOVESPEED = 30.0f;						//移動スピード
		const float m_MOVEPOS_MAX = 3.0f;						//クリックUi移動量最大値
		const POINTFLOAT m_UIPOS_RESET = { 910,1015 };		    //クリックUi初期位置

		VECTOR m_NowColor;                             //現在の文字色
		const VECTOR m_COLOR_DEFAULT = VGet(255, 255, 255);  //白色
    };
}