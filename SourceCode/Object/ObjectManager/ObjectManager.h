#pragma once
#include <Dxlib.h>
#include <memory>
#include <unordered_map>
#include <string>

#include"../ObjectBase/ObjectBase.h"
#include"GameStatus.h"
#include"PlayMenu.h"

namespace object
{
	class ObjectManager final
	{
	public:

		/// <summary>
		/// マネージャーインスタンス生成
		/// </summary>
		static void Initialize();

		/// <summary>
		/// デストラクタ
		/// </summary>
		~ObjectManager();

		/// <summary>
		/// 現在のシーンタグをセット
		/// </summary>
		static void NowSceneSet(std::vector<std::string> scene_objtag) {
			objectmanager->m_SceneTag = scene_objtag;
		}

		/// <summary>
		/// オブジェクト登録
		/// </summary>
		/// <param name="newobj">登録するオブジェクト</param>
		static void Entry(ObjectBase* newobj);

		/// <summary>
		/// 全オブジェクトの更新処理
		/// </summary>
		/// <param name="deltatime">デルタタイム</param>
		static void UpdateAllObj(const float deltatime);

		/// <summary>
		/// すべてのオブジェクトの描画
		/// </summary>
		static void DrawAllObj();

		/// <summary>
		/// 全オブジェクトの削除
		/// </summary>
		static void ReleaseAllObj();

		/// <summary>
		/// 現在のゲーム状態を取得
		/// </summary>
		/// <returns>現在のゲーム状態</returns>
		static GameStatus GetNowGameState() { return objectmanager->m_NowGameStatus; }

		/// <summary>
		/// 現在のゲーム状態をセット
		/// </summary>
		/// <param name="stats">セットするゲーム状態</param>
		static void SetNowGameState(GameStatus stats) { objectmanager->m_NowGameStatus = stats; }

		/// <summary>
		/// 次のゲーム状態を取得
		/// </summary>
		/// <returns>現在のゲーム状態</returns>
		static GameStatus GetNextGameState() { return objectmanager->m_NextGameStatus; }

		/// <summary>
		/// 次のゲーム状態をセット
		/// </summary>
		/// <param name="stats">セットするゲーム状態</param>
		static void SetNextGameState(GameStatus stats) { objectmanager->m_NextGameStatus = stats; }

		/// <summary>
		/// 現在のプレイモードを取得
		/// </summary>
		/// <returns>プレイモード</returns>
		static PlayMenu GetPlayMode() { return objectmanager->m_PlayMode; }

		/// <summary>
		/// 現在のプレイモードをセット
		/// </summary>
		/// <param name="select">選んだプレイモード</param>
		static void SetPlayMode(PlayMenu select) { objectmanager->m_PlayMode = select; }

		/// <summary>
		/// 選んだオブジェクトの削除
		/// </summary>
		/// <param name="tagname">オブジェクトの種類</param>
		static void  ReleaseObj(std::string tagname);

		/// <summary>
		/// タグ種類の初めのオブジェクトを返す
		/// </summary>
		/// <param name="tagname">オブジェクトの種類</param>
		/// <returns>最初のオブジェクト</returns>
		static ObjectBase* GetFirstGameObj(std::string tagname);

	private:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		ObjectManager();

		GameStatus m_NowGameStatus;		//現在のゲーム状態
		GameStatus m_NextGameStatus;	//次のゲーム状態

		PlayMenu m_PlayMode;			//現在のプレイモード
		const std::string MENU = "menu";	//メニュータグ

		static std::unique_ptr<ObjectManager> objectmanager;									// ObjectManagerの実体
		std::vector<std::string> m_SceneTag;													// 現在のシーンのオブジェクトタグ
		std::unordered_map<std::string, std::vector<std::shared_ptr<ObjectBase>>> m_Objects;	// オブジェクトリスト
	};
}
