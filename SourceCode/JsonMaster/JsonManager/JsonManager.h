#pragma once
#include<memory>

#include "../ImageData/MasterImgData/MasterImgData.h"
#include "../TextData/MasterTextData/MasterTextData.h"

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

		///<summary>
		///イメージインスタンス
		///</summary>
		///<returns>イメージデータ</returns>
		static class json_imgdata::MasterImgData* ImgData_Instance() { return json_manager->master_img_data.get(); }

		///<summary>
		///テキストインスタンス
		///</summary>
		///<returns>テキストデータ</returns>
		static class json_textdata::MasterTextData* TextData_Instance() { return json_manager->master_text_data.get(); }

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

		std::unique_ptr<class json_imgdata::MasterImgData> master_img_data;
		std::unique_ptr<class json_textdata::MasterTextData> master_text_data;
	};
}