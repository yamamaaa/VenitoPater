#include "IOUtility.h"

namespace jsonmaster
{
	IOUtility::IOUtility()
	{
		//�����Ȃ�
	}

	IOUtility::~IOUtility()
	{
		//�����Ȃ�
	}

	Json IOUtility::Analysis(std::string fileName)
	{
		Json result;

		//�t�@�C���ǂݍ���
		std::ifstream ifs(fileName.c_str());
		//�t�@�C���̉��
		result = Json::parse(ifs);
		//�t�@�C�������
		ifs.close();

		return result;
	}
}