#pragma once

#include "BaseScene.h"

class TitleScene : public BaseScene
{
public:
	void Update(void) noexcept override;
	void Render(void) noexcept override;

public:
	TitleScene(void) noexcept;
};
