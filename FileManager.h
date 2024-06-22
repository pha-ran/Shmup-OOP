#pragma once

class FileManager
{
public:
	static constexpr int FILE_MAX = 4096;
	static constexpr int TOKEN_MAX = 128;
	static constexpr const wchar_t* DELIMITER = L" \t\r\n";

public:
	static FileManager& GetInstance(void) noexcept;

public:
	void GetFirstString(const wchar_t* fileName, wchar_t* tokenBuffer) noexcept;
	void GetFirstInteger(const wchar_t* fileName, int* tokenBuffer) noexcept;
	void GetNextString(wchar_t* tokenBuffer) noexcept;
	void GetNextInteger(int* tokenBuffer) noexcept;

private:
	FileManager(void) noexcept;

private:
	wchar_t _fileBuffer[FILE_MAX / 2];
	wchar_t* _context;

	static FileManager _fileManager;
};
