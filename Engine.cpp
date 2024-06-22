#include "Engine.h"

Engine Engine::_engine;

Engine& Engine::GetInstance(void) noexcept
{
	return _engine;
}

int Engine::Run(void) noexcept
{
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
