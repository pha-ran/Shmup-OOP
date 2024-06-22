#pragma once

class Engine
{
public:
	static Engine& GetInstance(void) noexcept;

public:
	int Run(void) noexcept;

private:
	static Engine _engine;
};
