#include "SceneManager.h"
#include "OutputManager.h"

SceneManager SceneManager::_sceneManager;

SceneManager& SceneManager::GetInstance(void) noexcept
{
	return _sceneManager;
}

void SceneManager::Update(void) noexcept
{
	if (_changer)
		_changer->Change();

	_scene->Update();
}

void SceneManager::Render(void) noexcept
{
	OutputManager::GetInstance().ClearBuffer();
	_scene->Render();
	OutputManager::GetInstance().PrintBuffer();
}

SceneManager::SceneManager(void) noexcept
	: _scene(nullptr), _changer(nullptr)
{
	;
}
