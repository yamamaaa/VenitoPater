#pragma once
#include<string>
#include"../json.hpp"

using Json = nlohmann::json;

namespace json_fontdata
{
	/// <summary>
	/// Story����JsonFont�f�[�^�Ǘ��N���X
	/// </summary>
	class StoryData
	{
	public:

		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		/// <param name="json">Json�t�@�C��</param>
		StoryData(Json json);

		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		~StoryData();

		const std::string GetFontPath()const { return font; }
		const const char *Get_FontTagToChar()const { return fonttag.c_str(); }

	private:

		std::string font;
		std::string fonttag;
	};
}