#include "GameManager.h"
#include <stdio.h>

#pragma warning(disable:26495)

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

Player& GameManager::GetPlayer(wchar_t sprite, char x, char y)
{
    for (int index = 0; index < _playerInfo._count; ++index)
    {
        if (sprite != _playerInfo._player[index]._sprite)
            continue;

        _playerInfo._player[index]._x = x;
        _playerInfo._player[index]._y = y;

        return _playerInfo._player[index];
    }

    __debugbreak();
}

Enemy& GameManager::GetEnemy(wchar_t sprite, char x, char y)
{
    for (int index = 0; index < _enemyInfo._count; ++index)
    {
        if (sprite != _enemyInfo._enemy[index]._sprite)
            continue;

        _enemyInfo._enemy[index]._x = x;
        _enemyInfo._enemy[index]._y = y;

        return _enemyInfo._enemy[index];
    }

    __debugbreak();
}

void GameManager::InitStageInfo(void) noexcept
{
    int count;
    wchar_t tokenBuffer[FileManager::TOKEN_MAX];

    FileManager::GetInstance().GetFirstInteger(STAGE_CONFIG_FILE, &count);
    
    _stageInfo._count = count;
    _stageInfo._current = 0;

    for (int index = 0; index < count; ++index)
    {
        FileManager::GetInstance().GetNextString(tokenBuffer);
        swprintf_s(_stageInfo._fileName[index], FileManager::TOKEN_MAX, STAGE_INFO_PATH, tokenBuffer);
    }
}

void GameManager::InitPlayerInfo(void) noexcept
{
    int count;
    int index;
    wchar_t tokenBuffer[FileManager::TOKEN_MAX];
    wchar_t fileName[PLAYER_INFO_MAX][FileManager::TOKEN_MAX]{};

    FileManager::GetInstance().GetFirstInteger(PLAYER_CONFIG_FILE, &count);

    _playerInfo._count = count;
    _playerAlive = false;

    for (index = 0; index < count; ++index)
    {
        FileManager::GetInstance().GetNextString(tokenBuffer);
        swprintf_s(fileName[index], FileManager::TOKEN_MAX, PLAYER_INFO_PATH, tokenBuffer);
    }

    for (index = 0; index < count; ++index)
    {
        int i;

        _playerInfo._player[index]._destroy = false;
        _playerInfo._player[index]._type = Type::PLAYER;

        FileManager::GetInstance().GetFirstString(fileName[index], tokenBuffer);
        _playerInfo._player[index]._sprite = tokenBuffer[0];

        FileManager::GetInstance().GetNextInteger(&i);
        _playerInfo._player[index]._hp = i;

        FileManager::GetInstance().GetNextInteger(&i);
        _playerInfo._player[index]._deltaPerMove = i;

        FileManager::GetInstance().GetNextInteger(&i);
        _playerInfo._player[index]._deltaPerFire = i;

        _playerInfo._player[index]._moveDelta = 0;
        _playerInfo._player[index]._fireDelta = 0;
    }
}

void GameManager::InitEnemyInfo(void) noexcept
{
    int count;
    int index;
    wchar_t tokenBuffer[FileManager::TOKEN_MAX];
    wchar_t fileName[PLAYER_INFO_MAX][FileManager::TOKEN_MAX]{};

    FileManager::GetInstance().GetFirstInteger(ENEMY_CONFIG_FILE, &count);

    _enemyInfo._count = count;
    _enemyAlive = 0;

    for (index = 0; index < count; ++index)
    {
        FileManager::GetInstance().GetNextString(tokenBuffer);
        swprintf_s(fileName[index], FileManager::TOKEN_MAX, ENEMY_INFO_PATH, tokenBuffer);
    }

    for (index = 0; index < count; ++index)
    {
        int i;

        _enemyInfo._enemy[index]._destroy = false;
        _enemyInfo._enemy[index]._type = Type::ENEMY;

        FileManager::GetInstance().GetFirstString(fileName[index], tokenBuffer);
        _enemyInfo._enemy[index]._sprite = tokenBuffer[0];

        FileManager::GetInstance().GetNextInteger(&i);
        _enemyInfo._enemy[index]._hp = i;

        FileManager::GetInstance().GetNextInteger(&i);
        _enemyInfo._enemy[index]._deltaPerMove = i;

        FileManager::GetInstance().GetNextInteger(&i);
        _enemyInfo._enemy[index]._deltaPerFire = i;

        _enemyInfo._enemy[index]._moveDelta = 0;
        _enemyInfo._enemy[index]._fireDelta = 0;

        wchar_t moveFileName[FileManager::TOKEN_MAX];
        FileManager::GetInstance().GetNextString(tokenBuffer);
        swprintf_s(moveFileName, FileManager::TOKEN_MAX, ENEMY_MOVE_PATH, tokenBuffer);

        FileManager::GetInstance().GetFirstInteger(moveFileName, &i);
        _enemyInfo._enemy[index]._moveCount = i;
        _enemyInfo._enemy[index]._moveIndex = 0;

        for (int moveIndex = 0; moveIndex < _enemyInfo._enemy[index]._moveCount; ++moveIndex)
        {
            FileManager::GetInstance().GetNextInteger(&i);
            _enemyInfo._enemy[index]._nx[moveIndex] = i;

            FileManager::GetInstance().GetNextInteger(&i);
            _enemyInfo._enemy[index]._ny[moveIndex] = i;
        }
    }
}

GameManager::GameManager(void) noexcept
{
    ;
}
