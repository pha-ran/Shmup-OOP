#pragma once

#include "FileManager.h"

class GameManager
{
public:
	enum Type
	{
		PLAYER = 1,
		ENEMY,
		PLAYER_BULLET,
		ENEMY_BULLET
	};

public:
	static GameManager& GetInstance(void) noexcept;

public:
	void Initialize(void) noexcept;

private:
	static constexpr const wchar_t* STAGE_CONFIG_FILE = L"Config\\stage.txt";
	static constexpr const wchar_t* STAGE_INFO_PATH = L"Config\\stage\\%s";
	static constexpr int STAGE_INFO_MAX = 10;

	static constexpr const wchar_t* PLAYER_CONFIG_FILE = L"Config\\player.txt";
	static constexpr const wchar_t* PLAYER_INFO_PATH = L"Config\\player\\%s";
	static constexpr int PLAYER_INFO_MAX = 10;

	static constexpr const wchar_t* ENEMY_CONFIG_FILE = L"Config\\enemy.txt";
	static constexpr const wchar_t* ENEMY_INFO_PATH = L"Config\\enemy\\%s";
	static constexpr int ENEMY_INFO_MAX = 10;

	static constexpr const wchar_t* ENEMY_MOVE_PATH = L"Config\\enemy\\move\\%s";

public:
	struct StageInfo
	{
		char _count;
		char _current;
		wchar_t _fileName[STAGE_INFO_MAX][FileManager::TOKEN_MAX];
	} _stageInfo;

	struct PlayerInfo
	{
		char _count;
	};

	struct EnemyInfo
	{
		char _count;
	};

private:
	void InitStageInfo(void) noexcept;
	void InitPlayerInfo(void) noexcept;
	void InitEnemyInfo(void) noexcept;

private:
	GameManager(void) noexcept;
	~GameManager(void) noexcept;

private:
	static GameManager _gameManager;
};
