#include "Engine.h"
#include "TimeManager.h"

Engine Engine::_engine;

Engine& Engine::GetInstance(void) noexcept
{
	return _engine;
}

int Engine::Run(void) noexcept
{
	TimeManager::GetInstance().Reset();

	for (;;)
	{
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
