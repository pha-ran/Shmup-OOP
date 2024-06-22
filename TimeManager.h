#pragma once

class TimeManager
{
public:
	static constexpr int FRAMES_PER_SECOND = 50;
	static constexpr int SECOND = 1000;
	static constexpr int MILLISECONDS_PER_FRAME = SECOND / FRAMES_PER_SECOND;

public:
	static TimeManager& GetInstance(void) noexcept;

public:
	unsigned long GetDeltaTime(void) const noexcept;
	void Reset(void) noexcept;
	void NextFrame(void) noexcept;

private:
	TimeManager(void) noexcept;
	~TimeManager(void) noexcept;

private:
	unsigned long _delta;
	unsigned long _current;
	unsigned long _previous;
	unsigned long _previousFrame;
	unsigned long _previousSecond;
	unsigned long _framePerSecond;
	unsigned long _deltaPerSecond;
	signed long _error;

	static TimeManager _timeManager;
};
