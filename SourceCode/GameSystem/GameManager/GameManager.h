#include<DxLib.h>
#include<memory>

#include "../../Scene/SceneManager/SceneManager.h"

namespace GameSystem
{
    class Window;
    class GameSetting;

    /// <summary>
    /// �Q�[���S�̂̐i�s�Ǘ��N���X
    /// </summary>
    class GameManager final
    {
    public:

        /// <summary>
        /// �R���X�g���N�^
        /// </summary>
        GameManager();

        /// <summary>
        /// �f�X�g���N�^
        /// </summary>
        ~GameManager();

        /// <summary>
        /// �㏈��
        /// </summary>
        void Finalize();

    private:

        Window* window;
        GameSetting* gamesetting;

        //�V�[���}�l�[�W���[
        std::unique_ptr<class scene::SceneManager> sceneManager;
    };
}