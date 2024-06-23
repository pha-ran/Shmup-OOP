#include "Delegate.h"
#include "SceneManager.h"
#include "TitleScene.h"
#include "GameManager.h"

void Delegate::Initialize(void)
{
	GameManager::GetInstance().Initialize();
	SceneManager::GetInstance().LoadScene<TitleScene>();
}
