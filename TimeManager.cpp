#include "TimeManager.h"
#include "OutputManager.h"
#include <windows.h>
#include <stdio.h>

#pragma comment(lib, "winmm.lib")

TimeManager TimeManager::_timeManager;

TimeManager& TimeManager::GetInstance(void) noexcept
{
	return _timeManager;
}

unsigned long TimeManager::GetDeltaTime(void) const noexcept
{
	return _delta;
}

void TimeManager::Reset(void) noexcept
{
	_delta = 0;
	_current = timeGetTime();
	_previous = _current;
	_previousFrame = _current;
	_previousSecond = _current;
	_framePerSecond = 0;
	_deltaPerSecond = 0;
	_error = -1L;
}

void TimeManager::NextFrame(void) noexcept
{
	_previous = _current;
	_current = timeGetTime();

	if (_current - _previousSecond >= SECOND)
	{
		if (_error == -1L)
			_error = 0;
		else
			_error += _deltaPerSecond - SECOND;

		WCHAR buffer[32];
		swprintf_s(buffer, L"FPS %d (%d, %d)   ", _framePerSecond, _deltaPerSecond, _error);
		OutputManager::GetInstance().DrawUI(OutputManager::CONSOLE_WIDTH - 24, buffer);

		_framePerSecond = 0;
		_deltaPerSecond = 0;
		_previousSecond += SECOND;
		_previousFrame = _previousSecond;
	}

	DWORD frameTime = _current - _previousFrame;

	++_framePerSecond;
	_previousFrame += MILLISECONDS_PER_FRAME;

	if (frameTime < MILLISECONDS_PER_FRAME)
		Sleep(MILLISECONDS_PER_FRAME - frameTime);

	_delta = _current - _previous;
	_deltaPerSecond += _delta;
}

TimeManager::TimeManager(void) noexcept
{
	timeBeginPeriod(1);
	Reset();
}

TimeManager::~TimeManager(void) noexcept
{
	timeEndPeriod(1);
}
