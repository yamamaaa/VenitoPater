#pragma once
#include <unordered_map>
#include "../../MouseBase/MouseBase.h"
#include "PlayMenu.h"

namespace object
{
	/// <summary>
	/// Title��ʂł�mode�I���֘A
	/// </summary>
	class SelectMode :public MouseBase
	{
    public:

        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        SelectMode();

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~SelectMode();

    private:

        /// <summary>
        /// �ǂݍ��݊֘A
        /// </summary>
        void LoadObject() override;

        /// <summary>
        /// �I�u�W�F�N�g�̍X�V
        /// </summary>
        /// <param name="deltatime">�f���^�^�C��</param>
        void UpdateObj(const float deltatime) override;

        /// <summary>
        /// �I�u�W�F�N�g�̕`��
        /// </summary>
        void DrawObj() override;

        int m_SelectIndex;        //�C���f�b�N�X

        int m_MenuHandol;         //���j���[�摜�n���h��
        POINTFLOAT m_MenuPos;     //���j���[�摜�ʒu
        POINTFLOAT m_SelectPos;   //�Z���N�g�摜�ʒu

        //TitleMenu�̃J�[�\��Hit�ʒu
        std::unordered_map<int, POINTFLOAT> m_HitPos{
            {PlayMenu::PlayTutorial,{650.0f,450.0f}},
            {PlayMenu::PlayNewGame,{650.0f,570.0f}},
            {PlayMenu::PlayRankingMode,{650.0f,690.0f}},
        };

        //TitleMenu��selectUi�ʒu
        std::unordered_map<int, POINTFLOAT> m_SelectMenuPos{
            {PlayMenu::PlayTutorial,{537.0f,437.0f}},
            {PlayMenu::PlayNewGame,{537.0f,550.0f}},
            {PlayMenu::PlayRankingMode,{537.0f,670.0f}},
        };
	};
}