#pragma once

#include "BaseScene.h"

class GameScene : public BaseScene
{
public:
	void Update(void) noexcept override;
	void Render(void) noexcept override;

public:
	GameScene(void) noexcept;
	~GameScene(void) noexcept;
};
