#include "Delegate.h"
#include "SceneManager.h"
#include "TitleScene.h"

void Delegate::Initialize(void)
{
	SceneManager::GetInstance().LoadScene<TitleScene>();
}
