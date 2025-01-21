#pragma once
#include <Dxlib.h>
#include <memory>
#include <unordered_map>
#include <string>

#include"../ObjectBase/ObjectBase.h"
#include"../ObjectManager/GameStatus.h"

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
		/// ゲーム状態を取得
		/// </summary>
		/// <returns>現在のゲーム状態</returns>
		static GameStatus GetGameState() { return objectmanager->m_GameStatus; }

		/// <summary>
		/// ゲーム状態をセット
		/// </summary>
		/// <param name="stats">セットするゲーム状態</param>
		static void SetGameState(GameStatus stats) { objectmanager->m_GameStatus = stats; }

		/// <summary>
		/// 現在のシーン名取得
		/// </summary>
		/// <returns>現在のシーン名</returns>
		static std::string GetNowSceneName() { return objectmanager->m_NowScene_Name; }

		/// <summary>
		/// 現在のシーン名セット
		/// </summary>
		/// <param name="stats">現在のシーン名</param>
		static void SetNowSceneName(std::string scenename) { objectmanager->m_NowScene_Name = scenename; }

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

		std::string m_NowScene_Name;	//現在のシーン名

		GameStatus m_GameStatus;	//ゲーム状態

		static std::unique_ptr<ObjectManager> objectmanager;									// ObjectManagerの実体
		std::vector<std::string> m_SceneTag;													// 現在のシーンのオブジェクトタグ
		std::unordered_map<std::string, std::vector<std::shared_ptr<ObjectBase>>> m_Objects;	// オブジェクトリスト
	};
}
