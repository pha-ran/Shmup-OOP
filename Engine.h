#pragma once

class Engine
{
public:
	static Engine& GetInstance(void) noexcept;

public:
	int Run(void) noexcept;
	void Exit(void) noexcept;

private:
	Engine(void) noexcept;

private:
	bool _exit;

private:
	static Engine _engine;
};
