#include "SceneManager.h"
#include"../../Scene/SceneBase/SceneBase.h"
#include"../Title/Title.h"
#include"../../Fps/Fps.h"
#include"../../Object/ObjectManager/ObjectManager.h"
#include"../../Transitor/FadeTransitor/FadeTransitor.h"
#include"../../SoundController/SoundController.h"

namespace scene
{
    SceneManager::SceneManager()
        :m_HoldScene(nullptr)
        , fps(new fps::Fps)
    {
        //����������
        object::ObjectManager::Initialize();
        transitor::FadeTransitor::Initialize();
        sound_controller::SoundController::Initialize();

        //���݂̃V�[�����^�C�g���ɐݒ�
        m_NowScene.emplace(new Title);

        //�}�E�X�̕\���ݒ�
        SetMouseDispFlag(TRUE);
    }

    SceneManager::~SceneManager()
    {
        //�����Ȃ�
    }

    void SceneManager::GameLoop()
    {
        // �G�X�P�[�v�L�[��������邩�E�C���h�E��������܂Ń��[�v
        while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
        {
            //�V�[���̃t���[
            UpdateScene();    //�X�V����
            ChangeScene();    //�؂�ւ�����
            DrawScene();      //�`�揈��
        }
    }

    void SceneManager::UpdateScene()
    {
        //���݂̃V�[�����X�V����mHoldScene�ɑ��
        fps->Update();
        m_HoldScene = m_NowScene.top()->UpdateScene(fps->GetDeltaTime());
    }

    void SceneManager::DrawScene()
    {
        ClearDrawScreen();					// ��ʂ��N���A
        m_NowScene.top()->DrawScene();		// ���̃V�[����\��

        DrawLine(960, 0, 960, 1080, GetColor(255, 0, 255), FALSE);  //������
        DrawLine(0, 540, 1920, 540, GetColor(0, 255, 255), FALSE);

        ScreenFlip();						// ����ʂ̓��e��\��ʂɔ��f
    }

    void SceneManager::ChangeScene()
    {
        // ���̃V�[���������ł͂Ȃ�������
        if (m_NowScene.top().get() != m_HoldScene)
        {
            //���݂̃V�[�����폜���A���̃V�[���ɐ؂�ւ�
            m_NowScene.pop();
            m_NowScene.emplace(m_HoldScene);
        }
    }
}

