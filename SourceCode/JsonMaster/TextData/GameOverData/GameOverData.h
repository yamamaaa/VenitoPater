#pragma once
#include<string>
#include"../json.hpp"

using Json = nlohmann::json;

namespace json_textdata
{
    /// <summary>
    /// ameOver��JsonText�f�[�^�Ǘ��N���X
    /// </summary>
    class GameOverData
    {
	public:

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		/// <param name="json">Json�t�@�C��</param>
		GameOverData(Json json);

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~GameOverData();

		const std::string GetGameOverData_line_0()const { return line_0; }
		const std::string GetGameOverData_line_1()const { return line_1; }
		const std::string GetGameOverData_line_2()const { return line_2; }
		const std::string GetGameOverData_line_3()const { return line_3; }

		const std::string GetGameOverData_TimeOver()const { return timeover; }

	private:

		std::string line_0;
		std::string line_1;
		std::string line_2;
		std::string line_3;

		std::string timeover;
    };
}

