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

		if (_exit)
			break;
	}

	return 0;
}

void Engine::Exit(void) noexcept
{
	_exit = true;
}

Engine::Engine(void) noexcept
	: _exit(false)
{
	;
}
