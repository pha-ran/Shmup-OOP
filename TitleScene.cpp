#include "TitleScene.h"
#include "InputManager.h"
#include "OutputManager.h"
#include "SceneManager.h"

void TitleScene::Update(void) noexcept
{
	if (InputManager::GetInstance().GetKeyDown(VK_RETURN))
		SceneManager::GetInstance().LoadScene<TitleScene>();
}

void TitleScene::Render(void) noexcept
{
	OutputManager::GetInstance().DrawString(47, 7, L"C o n s o l e   S h m u p");
	OutputManager::GetInstance().DrawString(50, 19, L"press enter to start");
}

TitleScene::TitleScene(void) noexcept
{
	OutputManager::GetInstance().ClearUIBuffer();
}