#include "InputManager.h"
#include <windows.h>

#pragma warning(disable:26495)

InputManager InputManager::_inputManager;

InputManager& InputManager::GetInstance(void) noexcept
{
	return _inputManager;
}

bool InputManager::GetKeyDown(unsigned char key) noexcept
{
	if (GetAsyncKeyState(key) & 0x8000)
	{
		if (_flag[key])
			return false;

		_flag[key] = true;
		return true;
	}
	else
		_flag[key] = false;

	return false;
}

bool InputManager::GetKey(unsigned char key) const noexcept
{
	if (GetAsyncKeyState(key) & 0x8000)
		return true;

	return false;
}

InputManager::InputManager(void) noexcept
{
	for (int index = 0; index < KEY_MAX; ++index)
		_flag[index] = false;
}
