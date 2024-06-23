#include "Enemy.h"
#include "ObjectManager.h"
#include "OutputManager.h"
#include "TimeManager.h"
#include "GameManager.h"
#include "Bullet.h"

void Enemy::Update(void) noexcept
{
	UpdateMove();
	UpdateFire();
}

void Enemy::Render(void) noexcept
{
	OutputManager::GetInstance().DrawSprite(_x, _y, _sprite);
}

void Enemy::OnCollision(BaseObject* other) noexcept
{
	if (GameManager::Type::PLAYER_BULLET == other->Type())
		_hp -= 1;

	if (_hp <= 0)
	{
		GameManager::GetInstance()._enemyAlive -= 1;
		Destroy();
	}
}

void Enemy::UpdateMove(void) noexcept
{
	if (_moveDelta < _deltaPerMove)
	{
		_moveDelta += TimeManager::GetInstance().GetDeltaTime();
		return;
	}

	if (_moveIndex >= _moveCount)
		_moveIndex = 0;

	_x += _nx[_moveIndex];
	_y += _ny[_moveIndex];

	_moveDelta = 0;
	_moveIndex += 1;

	if (_x < 0)
		_x = 0;

	if (_y < 0)
		_y = 0;

	if (_x >= OutputManager::CONSOLE_WIDTH)
		_x = OutputManager::CONSOLE_WIDTH - 1;

	if (_y >= OutputManager::CONSOLE_HEIGHT)
		_y = OutputManager::CONSOLE_HEIGHT - 1;
}

void Enemy::UpdateFire(void) noexcept
{
	if (_fireDelta < _deltaPerFire)
	{
		_fireDelta += TimeManager::GetInstance().GetDeltaTime();
		return;
	}

	_fireDelta = 0;

	ObjectManager::GetInstance().Add(new Bullet(GameManager::Type::ENEMY_BULLET, _x, _y + 1, 60));
}
