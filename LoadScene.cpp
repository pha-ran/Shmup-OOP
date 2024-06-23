#include "LoadScene.h"
#include "FileManager.h"
#include "ObjectManager.h"
#include "OutputManager.h"
#include "SceneManager.h"
#include "GameManager.h"
#include "GameScene.h"

void LoadScene::Update(void) noexcept
{
	int index;
	int count;
	wchar_t buffer[FileManager::TOKEN_MAX];
	int x;
	int y;

	index = GameManager::GetInstance()._stageInfo._current;
	FileManager::GetInstance().GetFirstInteger(GameManager::GetInstance()._stageInfo._fileName[index], &count);
	
	FileManager::GetInstance().GetNextString(buffer);
	FileManager::GetInstance().GetNextInteger(&x);
	FileManager::GetInstance().GetNextInteger(&y);

	Player& playerPrefab = GameManager::GetInstance().GetPlayer(buffer[0], x, y);
	ObjectManager::GetInstance().Add(new Player(playerPrefab));

	GameManager::GetInstance()._playerAlive = true;
	--count;

	for (index = 0; index < count; ++index)
	{
		FileManager::GetInstance().GetNextString(buffer);
		FileManager::GetInstance().GetNextInteger(&x);
		FileManager::GetInstance().GetNextInteger(&y);

		Enemy& enemyPrefab = GameManager::GetInstance().GetEnemy(buffer[0], x, y);
		ObjectManager::GetInstance().Add(new Enemy(enemyPrefab));
	}

	GameManager::GetInstance()._enemyAlive = count;

	SceneManager::GetInstance().LoadScene<GameScene>();
}

void LoadScene::Render(void) noexcept
{
	OutputManager::GetInstance().DrawString(47, 19, L"l  o  a  d  i  n  g . . .");
}

LoadScene::LoadScene(void) noexcept
{
	;
}
