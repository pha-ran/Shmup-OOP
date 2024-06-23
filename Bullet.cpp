#include "Bullet.h"
#include "OutputManager.h"
#include "TimeManager.h"
#include "GameManager.h"

void Bullet::Update(void) noexcept
{
	if (_moveDelta < _deltaPerMove)
	{
		_moveDelta += TimeManager::GetInstance().GetDeltaTime();
		return;
	}

	_moveDelta = 0;

	if (_type == GameManager::Type::PLAYER_BULLET)
		_y -= 1;
	else if (_type == GameManager::Type::ENEMY_BULLET)
		_y += 1;

	if (_y < 0 || _y >= OutputManager::CONSOLE_HEIGHT)
		Destroy();
}

void Bullet::Render(void) noexcept
{
	if (_destroy)
		return;

	if (_type == GameManager::Type::PLAYER_BULLET)
		OutputManager::GetInstance().DrawSprite(_x, _y, L'o');
	else if (_type == GameManager::Type::ENEMY_BULLET)
		OutputManager::GetInstance().DrawSprite(_x, _y, L'x');
}

void Bullet::OnCollision(BaseObject* other) noexcept
{
	if (other->Type() == GameManager::Type::PLAYER && _type == GameManager::Type::ENEMY_BULLET ||
		other->Type() == GameManager::Type::ENEMY && _type == GameManager::Type::PLAYER_BULLET)
		Destroy();
}

Bullet::Bullet(char type, char x, char y, int deltaPerMove) noexcept
	: _deltaPerMove(deltaPerMove), _moveDelta(0)
{
	_destroy = false;
	_type = type;
	_x = x;
	_y = y;
}
