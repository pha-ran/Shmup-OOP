#pragma once

class BaseObject
{
	friend class ObjectManager;

public:
	virtual ~BaseObject(void) noexcept {};

public:
	virtual void Update(void) noexcept = 0;
	virtual void Render(void) noexcept = 0;
	virtual void OnCollision(BaseObject* other) noexcept = 0;
	inline char Type(void) const noexcept { return _type; }
	inline void Destroy(void) noexcept { _destroy = true; }

protected:
	bool _destroy;
	char _type;
	char _x;
	char _y;
};
