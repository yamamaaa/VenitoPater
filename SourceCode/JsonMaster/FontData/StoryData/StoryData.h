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

		const std::string GetFontData()const { return font; }
		const std::string Get_FontTagData()const { return fonttag; }

	private:

		std::string font;
		std::string fonttag;
	};
}