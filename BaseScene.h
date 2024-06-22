#pragma once

class BaseScene
{
public:
	virtual ~BaseScene(void) noexcept = 0;

public:
	virtual void Update(void) noexcept = 0;
	virtual void Render(void) noexcept = 0;
};
