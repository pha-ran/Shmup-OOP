#include "OverScene.h"
#include "InputManager.h"
#include "OutputManager.h"
#include "SceneManager.h"
#include "GameManager.h"
#include "TitleScene.h"

void OverScene::Update(void) noexcept
{
	if (InputManager::GetInstance().GetKeyDown(VK_RETURN))
		SceneManager::GetInstance().LoadScene<TitleScene>();
}

void OverScene::Render(void) noexcept
{
	OutputManager::GetInstance().DrawString(52, 14, L"G A M E O V E R");
	OutputManager::GetInstance().DrawString(54, 16, L"press enter");
}

OverScene::OverScene(void) noexcept
{
	GameManager::GetInstance()._stageInfo._current = 0;
}
