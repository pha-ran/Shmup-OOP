#include "LoadScene.h"
#include "ObjectManager.h"
#include "OutputManager.h"
#include "SceneManager.h"

void LoadScene::Update(void) noexcept
{
	;
}

void LoadScene::Render(void) noexcept
{
	OutputManager::GetInstance().DrawString(47, 19, L"l  o  a  d  i  n  g . . .");
}

LoadScene::LoadScene(void) noexcept
{
	;
}
