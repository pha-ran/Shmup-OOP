#pragma once

#include "BaseScene.h"

class ClearScene : public BaseScene
{
public:
	void Update(void) noexcept override;
	void Render(void) noexcept override;

public:
	ClearScene() noexcept;
	~ClearScene() noexcept;
};
