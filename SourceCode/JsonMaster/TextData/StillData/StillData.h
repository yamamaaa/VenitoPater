#pragma once
#include<string>
#include"../json.hpp"

using Json = nlohmann::json;

namespace json_textdata
{
	/// <summary>
	/// Still��JsonText�f�[�^�Ǘ��N���X
	/// </summary>
	class StillData
	{
	public:

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		/// <param name="json">Json�t�@�C��</param>
		StillData(Json json);

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~StillData();

		const std::string GetLineData_Day_0()const { return lineData.day_0; }
		const std::string GetLineData_Day_1()const { return lineData.day_1; }
		const std::string GetLineData_Day_2()const { return lineData.day_2; }
		const std::string GetLineData_Day_3()const { return lineData.day_3; }
		const std::string GetLineData_Day_4()const { return lineData.day_4; }
		const std::string GetLineData_Day_5()const { return lineData.day_5; }

		const std::string GetDrawImgData_Day_0()const { return drawImgData.day_0; }
		const std::string GetDrawImgData_Day_1()const { return drawImgData.day_1; }
		const std::string GetDrawImgData_Day_2()const { return drawImgData.day_2; }
		const std::string GetDrawImgData_Day_3()const { return drawImgData.day_3; }
		const std::string GetDrawImgData_Day_4()const { return drawImgData.day_4; }

	private:

		struct LineData
		{
			std::string day_0;
			std::string day_1;
			std::string day_2;
			std::string day_3;
			std::string day_4;
			std::string day_5;
		}lineData;

		struct DrawImgData
		{
			std::string day_0;
			std::string day_1;
			std::string day_2;
			std::string day_3;
			std::string day_4;
		}drawImgData;
	};
}