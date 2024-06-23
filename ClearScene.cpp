#include "ClearScene.h"
#include "InputManager.h"
#include "OutputManager.h"
#include "SceneManager.h"
#include "GameManager.h"
#include "TitleScene.h"
#include "LoadScene.h"

void ClearScene::Update(void) noexcept
{
	if (InputManager::GetInstance().GetKeyDown(VK_RETURN))
	{
		if (GameManager::GetInstance()._stageInfo._current >= GameManager::GetInstance()._stageInfo._count)
		{
			GameManager::GetInstance()._stageInfo._current = 0;
			SceneManager::GetInstance().LoadScene<TitleScene>();
			return;
		}

		SceneManager::GetInstance().LoadScene<LoadScene>();
	}
}

void ClearScene::Render(void) noexcept
{
	OutputManager::GetInstance().DrawString(55, 14, L"C L E A R");
	OutputManager::GetInstance().DrawString(54, 16, L"press enter");
}

ClearScene::ClearScene() noexcept
{
	GameManager::GetInstance()._stageInfo._current += 1;
}

ClearScene::~ClearScene() noexcept
{
}
