#pragma once

#include "BaseScene.h"

class OverScene : public BaseScene
{
public:
	void Update(void) noexcept override;
	void Render(void) noexcept override;

public:
	OverScene() noexcept;
	~OverScene() noexcept;
};
