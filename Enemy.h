#pragma once

#include "BaseObject.h"

class Enemy : public BaseObject
{
	friend class GameManager;

public:
	void Update(void) noexcept override;
	void Render(void) noexcept override;
	void OnCollision(BaseObject* other) noexcept override;

private:
	void UpdateMove(void) noexcept;
	void UpdateFire(void) noexcept;

private:
	static constexpr int ENEMY_MOVE_COUNT_MAX = 20;

private:
	wchar_t _sprite;
	wchar_t _hp;
	wchar_t _deltaPerMove;
	wchar_t _deltaPerFire;
	int _moveDelta;
	int _fireDelta;
	wchar_t _moveCount;
	wchar_t _moveIndex;
	char _nx[ENEMY_MOVE_COUNT_MAX];
	char _ny[ENEMY_MOVE_COUNT_MAX];
};
