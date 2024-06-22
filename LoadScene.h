#pragma once

#include "BaseScene.h"

class LoadScene : public BaseScene
{
public:
	void Update(void) noexcept override;
	void Render(void) noexcept override;

public:
	LoadScene(void) noexcept;
};
