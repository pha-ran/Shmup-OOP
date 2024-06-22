#pragma once

class InputManager
{
public:
	static constexpr int KEY_MAX = 0x100;

public:
	static InputManager& GetInstance(void) noexcept;

public:
	bool GetKeyDown(unsigned char key) noexcept;
	bool GetKey(unsigned char key) const noexcept;

private:
	InputManager(void) noexcept;
	~InputManager(void) noexcept;

private:
	bool _flag[KEY_MAX];

private:
	static InputManager _inputManager;
};
