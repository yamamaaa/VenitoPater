#include<DxLib.h>

#include "Title.h"
#include"../ThreeDays/ThreeDays.h"

namespace scene
{
    Title::Title()
        :SceneBase()
    {
        //�����Ȃ�
    }

    Title::~Title()
    {
        //�����Ȃ�
    }

    SceneBase* Title::UpdateScene(float deltaTime)
    {
        //�V�[���؂�ւ�
        if (CheckHitKey(KEY_INPUT_SPACE))
        {
            //�v���C���ɐ؂�ւ�
            return new ThreeDays;
        }
        return this;
    }

    void Title::DrawScene()
    {
        DrawFormatString(0, 0, GetColor(255, 255, 255), "title");
        //�^�C�g�����S�\��
    }
}