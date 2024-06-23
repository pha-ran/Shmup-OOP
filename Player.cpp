#include "Player.h"
#include "InputManager.h"
#include "ObjectManager.h"
#include "OutputManager.h"
#include "TimeManager.h"
#include "GameManager.h"
#include "Bullet.h"
#include <stdio.h>

void Player::Update(void) noexcept
{
	UpdateMove();
	UpdateFire();
}

void Player::Render(void) noexcept
{
	if (_destroy)
		return;

	OutputManager::GetInstance().DrawSprite(_x, _y, _sprite);

	wchar_t buffer[16];
	swprintf_s(buffer, 16, L"HP : %d", _hp);
	OutputManager::GetInstance().DrawUI(8, buffer);
}

void Player::OnCollision(BaseObject* other) noexcept
{
	if (GameManager::Type::ENEMY_BULLET == other->Type())
		_hp -= 1;

	if (_hp <= 0)
	{
		GameManager::GetInstance()._playerAlive = false;
		Destroy();
	}
}

void Player::UpdateMove(void) noexcept
{
	if (_moveDelta < _deltaPerMove)
	{
		_moveDelta += TimeManager::GetInstance().GetDeltaTime();
		return;
	}

	if (InputManager::GetInstance().GetKey(VK_UP))
	{
		_y -= 1;
		_moveDelta = 0;
	}

	if (InputManager::GetInstance().GetKey(VK_DOWN))
	{
		_y += 1;
		_moveDelta = 0;
	}

	if (InputManager::GetInstance().GetKey(VK_LEFT))
	{
		_x -= 1;
		_moveDelta = 0;
	}

	if (InputManager::GetInstance().GetKey(VK_RIGHT))
	{
		_x += 1;
		_moveDelta = 0;
	}

	if (_x < 0)
		_x = 0;

	if (_y < 0)
		_y = 0;

	if (_x >= OutputManager::CONSOLE_WIDTH)
		_x = OutputManager::CONSOLE_WIDTH - 1;

	if (_y >= OutputManager::CONSOLE_HEIGHT)
		_y = OutputManager::CONSOLE_HEIGHT - 1;
}

void Player::UpdateFire(void) noexcept
{
	if (_fireDelta < _deltaPerFire)
	{
		_fireDelta += TimeManager::GetInstance().GetDeltaTime();
		return;
	}

	if (InputManager::GetInstance().GetKey(VK_SPACE))
	{
		ObjectManager::GetInstance().Add(new Bullet(GameManager::Type::PLAYER_BULLET, _x, _y - 1, 40));
		_fireDelta = 0;
	}
}
