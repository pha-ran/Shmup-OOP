#pragma once

#include <windows.h>

class InputManager
{
public:
	static constexpr int KEY_MAX = 0xFF;

public:
	static InputManager& GetInstance(void) noexcept;

public:
	bool GetKeyDown(unsigned char key) noexcept;
	bool GetKey(unsigned char key) const noexcept;

private:
	InputManager(void) noexcept;

private:
	bool _flag[KEY_MAX + 1];

private:
	static InputManager _inputManager;
};
