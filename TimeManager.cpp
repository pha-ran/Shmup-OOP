#include "TimeManager.h"
#include <windows.h>
#include <stdio.h>

#pragma comment (lib, "winmm.lib")

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
	if (GetAsyncKeyState(VK_ESCAPE))
		Sleep(234);

	wprintf_s(L"delta : %d\n", _delta);

	_previous = _current;
	_current = timeGetTime();

	if (_current - _previousSecond >= SECOND)
	{
		if (_error == -1L)
			_error = 0;
		else
			_error += _deltaPerSecond - SECOND;

		wprintf_s(L"FPS %d (%d, %d)\n", _framePerSecond, _deltaPerSecond, _error);

		_framePerSecond = 0;
		_deltaPerSecond = 0;
		_previousSecond += SECOND;
		_previousFrame = _previousSecond;
	}

	++_framePerSecond;

	DWORD frameTime = _current - _previousFrame;

	if (frameTime < MILLISECONDS_PER_FRAME)
		Sleep(MILLISECONDS_PER_FRAME - frameTime);
	
	_previousFrame += MILLISECONDS_PER_FRAME;

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
