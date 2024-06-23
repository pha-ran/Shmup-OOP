#include "GameManager.h"
#include <stdio.h>

GameManager GameManager::_gameManager;

GameManager& GameManager::GetInstance(void) noexcept
{
    return _gameManager;
}

void GameManager::Initialize(void) noexcept
{
    InitStageInfo();
    InitPlayerInfo();
    InitEnemyInfo();
}

void GameManager::InitStageInfo(void) noexcept
{
    int count;
    wchar_t tokenBuffer[FileManager::TOKEN_MAX];

    FileManager::GetInstance().GetFirstInteger(STAGE_CONFIG_FILE, &count);
    _stageInfo._count = count;

    for (int index = 0; index < count; ++index)
    {
        FileManager::GetInstance().GetNextString(tokenBuffer);
        swprintf_s(_stageInfo._fileName[index], FileManager::TOKEN_MAX, STAGE_INFO_PATH, tokenBuffer);
    }
}

void GameManager::InitPlayerInfo(void) noexcept
{
    ;
}

void GameManager::InitEnemyInfo(void) noexcept
{
    ;
}

GameManager::GameManager(void) noexcept
{
    ;
}

GameManager::~GameManager(void) noexcept
{
    ;
}
