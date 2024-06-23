#pragma once

#include "BaseObject.h"

class Player : public BaseObject
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
	wchar_t _sprite;
	wchar_t _hp;
	wchar_t _deltaPerMove;
	wchar_t _deltaPerFire;
	int _moveDelta;
	int _fireDelta;
};
