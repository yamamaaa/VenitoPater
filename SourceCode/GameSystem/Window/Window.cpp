#include "Window.h"

namespace GameSystem
{
    //���̂����
    std::unique_ptr<Window> Window::window = nullptr;

    void Window::Init()
    {
        //���̂ɉ��������Ă��Ȃ�������
        if (!window)
        {
            //���̓��ɃC���X�^���X�𐶐�
            window.reset(new Window);
        }
    }

    Window::Window()
    {
        //TRUE �E�B���h�E���[�h�ŋN��
        ChangeWindowMode(TRUE);
        //�E�B���h�E�̃T�C�Y��ݒ�
        SetGraphMode(static_cast<int>(WINDOW_SIZE.x), static_cast<int>(WINDOW_SIZE.y), COLOR_BIT);
        //�E�B���h�E�𑜓x���ێ������܂܃T�C�Y�{����ݒ�
        SetWindowSizeExtendRate(1.0);
        //�E�B���h�E�̃^�C�g���ύX
        SetMainWindowText("VenitoPater");
    }

    Window::~Window()
    {
        //�����Ȃ�
    }
}
