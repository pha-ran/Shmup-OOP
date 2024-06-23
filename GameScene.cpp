#include "GameScene.h"
#include "ObjectManager.h"
#include "OutputManager.h"
#include "TimeManager.h"
#include "GameManager.h"
#include <stdio.h>

void GameScene::Update(void) noexcept
{
	ObjectManager::GetInstance().Update();
}

void GameScene::Render(void) noexcept
{
	ObjectManager::GetInstance().Render();

	if (GameManager::GetInstance()._stageInfo._current + 1 >= GameManager::GetInstance()._stageInfo._count)
	{
		OutputManager::GetInstance().DrawUI(OutputManager::CONSOLE_WIDTH / 2 - 5, L"LAST STAGE");
		return;
	}

	wchar_t buffer[16];
	swprintf_s(buffer, 16, L"STAGE %d", GameManager::GetInstance()._stageInfo._current + 1);
	OutputManager::GetInstance().DrawUI(OutputManager::CONSOLE_WIDTH / 2 - 4, buffer);
}

GameScene::GameScene(void) noexcept
{
	TimeManager::GetInstance().Reset();
}

GameScene::~GameScene(void) noexcept
{
	ObjectManager::GetInstance().Clear();
}
