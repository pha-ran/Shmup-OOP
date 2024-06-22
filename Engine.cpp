#include "Engine.h"
#include "TimeManager.h"
#include "OutputManager.h"

Engine Engine::_engine;

Engine& Engine::GetInstance(void) noexcept
{
	return _engine;
}

int Engine::Run(void) noexcept
{
	for (;;)
	{
		OutputManager::GetInstance().ClearBuffer();
		OutputManager::GetInstance().PrintBuffer();

		TimeManager::GetInstance().NextFrame();
	}

	return 0;
}

Engine::Engine(void) noexcept
{
	;
}

Engine::~Engine(void) noexcept
{
	;
}
