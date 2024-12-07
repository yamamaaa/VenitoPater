#include<DxLib.h>

#include "Title.h"
#include"../ThreeDays/ThreeDays.h"
#include"../Result/GameOver/GameOver.h"
#include"../../LevelController/LevelController.h"
#include"../../LevelController/LevelStatus.h"

using namespace level_controller;

namespace scene
{
    Title::Title()
        :SceneBase()
    {
        LevelController::Initialize();
    }

    Title::~Title()
    {
        //�����Ȃ�
    }

    SceneBase* Title::UpdateScene(float deltaTime)
    {
        ////�V�[���؂�ւ�
        //if (CheckHitKey(KEY_INPUT_SPACE))
        //{
        //    //�v���C���ɐ؂�ւ�
        //    return new ThreeDays;
        //}

        //�v���C���ɐ؂�ւ�
        LevelController::SetLevel(levelStatus.NOMAL);
        return new ThreeDays();

        //return new GameOver();

        //F1�������ꂽ��m�[�}�����[�h
        if (CheckHitKey(KEY_INPUT_F1))
        {
            //�v���C���ɐ؂�ւ�
            LevelController::SetLevel(levelStatus.NOMAL);
            return new ThreeDays();
        }
        //F2�������ꂽ��n�[�h���[�h
        else if (CheckHitKey(KEY_INPUT_F2))
        {
            //�v���C���ɐ؂�ւ�
            LevelController::SetLevel(levelStatus.HARD);
            return new ThreeDays();
        }

        return this;
    }

    void Title::DrawScene()
    {
        DrawFormatString(0, 0, GetColor(255, 255, 255), "title");
        //�^�C�g�����S�\��
    }
}