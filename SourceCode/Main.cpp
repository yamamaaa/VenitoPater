#include <DxLib.h>
#include <memory>

#include "../SourceCode/GameSystem/GameManager/GameManager.h"

using namespace GameSystem;

int WINAPI _stdcall WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int)
{
	//ゲームシーン管理
	std::shared_ptr<GameManager> gameManager(new GameManager);
	gameManager->Finalize();

	return 0;				// ソフトの終了 
}