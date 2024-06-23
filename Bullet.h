#pragma once

#include "BaseObject.h"

class Bullet : public BaseObject
{
public:
	void Update(void) noexcept override;
	void Render(void) noexcept override;
	void OnCollision(BaseObject* other) noexcept override;

public:
	Bullet(char type, char x, char y, int deltaPerMove) noexcept;

private:
	int _deltaPerMove;
	int _moveDelta;
};
