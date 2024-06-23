#include "ObjectManager.h"

ObjectManager ObjectManager::_objectManager;

ObjectManager& ObjectManager::GetInstance(void) noexcept
{
	return _objectManager;
}

void ObjectManager::Update(void) noexcept
{
	for (List<BaseObject*>::Iterator it1 = _list.begin(); it1 != _list.end(); ++it1)
	{
		(*it1)->Update();

		List<BaseObject*>::Iterator it2 = it1;

		for (++it2; it2 != _list.end(); ++it2)
		{
			if ((*it1)->_x != (*it2)->_x)
				continue;

			if ((*it1)->_y != (*it2)->_y)
				continue;

			(*it1)->OnCollision(*it2);
			(*it2)->OnCollision(*it1);
		}
	}

	for (List<BaseObject*>::Iterator it = _list.begin(); it != _list.end();)
	{
		if (!(*it)->_destroy)
		{
			++it;
			continue;
		}

		delete (*it);
		it = _list.erase(it);
	}
}

void ObjectManager::Render(void) noexcept
{
	for (List<BaseObject*>::Iterator it = _list.begin(); it != _list.end(); ++it)
	{
		(*it)->Render();
	}
}

void ObjectManager::Add(BaseObject* baseObject) noexcept
{
	_list.emplace(_list.end(), baseObject);
}

void ObjectManager::Clear(void) noexcept
{
	for (List<BaseObject*>::Iterator it = _list.begin(); it != _list.end();)
	{
		delete (*it);
		it = _list.erase(it);
	}
}

ObjectManager::ObjectManager(void) noexcept
{
	;
}

ObjectManager::~ObjectManager(void) noexcept
{
	Clear();
}
