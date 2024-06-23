#pragma once

#include "BaseObject.h"
#include "List.h"

class ObjectManager
{
public:
	static ObjectManager& GetInstance(void) noexcept;

public:
	void Update(void) noexcept;
	void Render(void) noexcept;
	void Add(BaseObject* baseObject) noexcept;
	void Clear(void) noexcept;

private:
	ObjectManager(void) noexcept;
	~ObjectManager(void) noexcept;

private:
	List<BaseObject*> _list;

private:
	static ObjectManager _objectManager;
};
