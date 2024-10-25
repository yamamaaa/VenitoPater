#pragma once
#include<memory>

namespace jsonmaster
{
	/// <summary>
	/// Jsonデータ管理クラス
	/// </summary>
	class JsonManager final
	{
	public:

		/// <summary>
		/// 初期化
		/// </summary>
		static void InitJsonManager();

		/// <summary>
		/// イメージインスタンス
		/// </summary>
		/// <returns>イメージデータ</returns>
		//static class MasterImgData* ImgDataInstance() { return json_manager->masterimgdata.get(); }
		
		/// <summary>
		/// デストラクタ
		/// </summary>
		~JsonManager();

	private:

		/// <summary>
		/// コンストラクタ
		/// </summary>
		JsonManager();

		static std::unique_ptr<class JsonManager> json_manager;//自身の実態

		//std::unique_ptr<class MasterImgData> master_img_data;//ImgJsonの実態
	};
}