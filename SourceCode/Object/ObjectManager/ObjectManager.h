#pragma once
#include <Dxlib.h>
#include <memory>
#include <unordered_map>
#include <string>

namespace object
{
	class ObjectBase;

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
		static void NowSceneSet(std::vector<std::string> scene_objtag);

		/// <summary>
		/// オブジェクト登録
		/// </summary>
		/// <param name="newobj">登録するオブジェクト</param>
		static void Entry(ObjectBase* newobj);

		/// <summary>
		/// 全オブジェクトの更新処理
		/// </summary>
		/// <param name="deltatime">デルタタイム</param>
		static void UpdateAllObj(float deltatime);

		/// <summary>
		/// すべてのオブジェクトの描画
		/// </summary>
		static void DrawAllObj();

		/// <summary>
		/// オブジェクトの移動処理
		/// </summary>
		static void MoveAllObj();

		/// <summary>
		/// オブジェクトの死亡処理
		/// </summary>
		/// <param name="unnecobj">不要なオブジェクト</param>
		static void OnDeadObj(std::shared_ptr<ObjectBase> unnecobj);

		/// <summary>
		/// 全オブジェクトの削除
		/// </summary>
		static void ReleaseAllObj();

		/// <summary>
		/// タグ種類の初めのオブジェクトを返す
		/// </summary>
		/// <param name="tagname">オブジェクトの種類</param>
		/// <returns>最初のオブジェクト</returns>
		ObjectBase* GetFirstGameObj(std::string tagname);

	private:

		ObjectBase* objectbase;

		/// <summary>
		/// コンストラクタ
		/// </summary>
		ObjectManager();

		static std::unique_ptr<ObjectManager> objectmanager;									// ObjectManagerの実体
		std::vector<std::string> m_SceneTag;													// 現在のシーンのオブジェクトタグ
		std::unordered_map<std::string, std::vector<std::shared_ptr<ObjectBase>>> m_Objects;	// オブジェクトリスト
    };
}
