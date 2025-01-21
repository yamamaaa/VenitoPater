#pragma once
#include<string>
#include"../json.hpp"

using Json = nlohmann::json;

namespace json_imgdata
{
	/// <summary>
	/// Result����JsonImg�f�[�^�Ǘ��N���X
	/// </summary>
	class ResultData
	{
	public:

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		/// <param name="json">Json�t�@�C��</param>
		ResultData(Json json);

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~ResultData();

		const std::string GetClearData_BackGround()const { return gameClearData.background; }

		const std::string GetOverData_BackGround()const { return gameOverData.background; }
		const std::string GetOverData_Select()const { return gameOverData.select; }

	private:

		struct GameClearData
		{
			std::string background;
		}gameClearData;

		struct GameOverData
		{
			std::string background;
			std::string select;
		}gameOverData;
	};
}