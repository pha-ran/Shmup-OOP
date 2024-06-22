#include "FileManager.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable:6386)
#pragma warning(disable:6387)
#pragma warning(disable:26495)

FileManager FileManager::_fileManager;

FileManager& FileManager::GetInstance(void) noexcept
{
    return _fileManager;
}

void FileManager::GetFirstString(const wchar_t* fileName, wchar_t* tokenBuffer) noexcept
{
	FILE* file;
	long fileSize;

	_wfopen_s(&file, fileName, L"rb");

	fseek(file, 0, SEEK_END);
	fileSize = ftell(file);

	fseek(file, 2, SEEK_SET);
	fread(_fileBuffer, 1, __min(fileSize, FILE_MAX) - 2, file);
	fclose(file);

	_fileBuffer[(__min(fileSize, FILE_MAX) - 2) / 2] = L'\0';

	_context = NULL;
	wcscpy_s(tokenBuffer, TOKEN_MAX, wcstok_s(_fileBuffer, DELIMITER, &_context));
}

void FileManager::GetFirstInteger(const wchar_t* fileName, int* tokenBuffer) noexcept
{
	wchar_t buffer[TOKEN_MAX];

	GetFirstString(fileName, buffer);

	*tokenBuffer = _wtoi(buffer);
}

void FileManager::GetNextString(wchar_t* tokenBuffer) noexcept
{
	wcscpy_s(tokenBuffer, TOKEN_MAX, wcstok_s(NULL, DELIMITER, &_context));
}

void FileManager::GetNextInteger(int* tokenBuffer) noexcept
{
	wchar_t buffer[TOKEN_MAX];

	wcscpy_s(buffer, TOKEN_MAX, wcstok_s(NULL, DELIMITER, &_context));
	*tokenBuffer = _wtoi(buffer);
}

FileManager::FileManager(void) noexcept
{
	;
}
