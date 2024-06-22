#pragma once

class BaseScene
{
public:
	virtual ~BaseScene(void) noexcept {};

public:
	virtual void Update(void) noexcept = 0;
	virtual void Render(void) noexcept = 0;
};
