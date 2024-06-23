#include "Engine.h"
#include "SceneManager.h"
#include "TimeManager.h"

Engine Engine::_engine;

Engine& Engine::GetInstance(void) noexcept
{
	return _engine;
}

int Engine::Run(void) noexcept
{
	for (;;)
	{
		SceneManager::GetInstance().Update();
		SceneManager::GetInstance().Render();

		TimeManager::GetInstance().NextFrame();
	}

	return 0;
}

Engine::Engine(void) noexcept
{
	;
}