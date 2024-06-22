#pragma once

#include <malloc.h>
#include <new>

#pragma warning(disable : 6011)

template <typename T>
class List
{
private:
	struct Node
	{
		T _data;
		Node* _prev;
		Node* _next;
	};

public:
	class Iterator
	{
	public:
		Iterator(Node* node = nullptr) noexcept
			: _node(node) {}

		Iterator& operator++() noexcept
		{
			_node = _node->_next;
			return *this;
		}

		Iterator& operator--() noexcept
		{
			_node = _node->_prev;
			return *this;
		}

		bool operator==(const Iterator& iterator) const noexcept
		{
			return _node == iterator._node;
		}

		bool operator!=(const Iterator& iterator) const noexcept
		{
			return _node != iterator._node;
		}

		T& operator*() const noexcept
		{
			return _node->_data;
		}

	private:
		Node* _node;
		friend class List <T>;
	};

public:
	Iterator begin(void) const noexcept
	{
		return Iterator(_head->_next);
	}

	Iterator end(void) const noexcept
	{
		return Iterator(_tail);
	}

public:
	List() noexcept
		: _size(0)
	{
		_head = static_cast<Node*>(malloc(sizeof(Node) * 2));
		_tail = _head + 1;

		_head->_prev = nullptr;
		_head->_next = _tail;

		_tail->_prev = _head;
		_tail->_next = nullptr;
	}

	List(const List<T>& list) = delete;
	List(List<T>&& list) = delete;

	~List() noexcept
	{
		free(_head);
	}

	List<T>& operator=(const List<T>& list) = delete;
	List<T>& operator=(List<T>&& list) = delete;

	size_t size(void) const noexcept
	{
		return _size;
	}

	bool empty(void) const noexcept
	{
		return 0 == _size;
	}

	template<typename... Args>
	Iterator emplace(const Iterator& it, Args&&... args) noexcept
	{
		Node* node = static_cast<Node*>(malloc(sizeof(Node)));
		new(node) T(std::forward<Args>(args)...);

		Node* temp = it._node;

		node->_prev = temp->_prev;
		node->_next = temp;

		temp->_prev->_next = node;
		temp->_prev = node;

		++_size;

		return Iterator(node);
	}

	Iterator erase(const Iterator& it) noexcept
	{
		Node* temp = it._node;
		Iterator next(temp->_next);

		temp->_prev->_next = temp->_next;
		temp->_next->_prev = temp->_prev;

		delete it._node;

		--_size;

		return next;
	}

	void clear(void) noexcept
	{
		while (!empty())
			erase(begin());
	}

private:
	size_t _size;
	Node* _head;
	Node* _tail;
};
