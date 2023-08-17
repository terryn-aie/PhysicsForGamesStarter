#pragma once

#include <cassert>

template<typename T>
class TList
{
public:
	TList();
	~TList();

	void Push_Front(const T & value);
	void Push_Back(const T & value);

	T & Front();
	T & Back();

	void Pop_Front();
	void Pop_Back();

	size_t Size() const;

	bool Empty() const;

	struct Node
	{
		T data;
		Node* prev;
		Node* next;

		Node()
		{
			prev = next = nullptr;
			data = T();
		}

		Node(const T& val)
		{
			prev = next = nullptr;
			data = val;
		}

		Node(const T& val, Node* pre, Node* nxt)
		{
			prev = pre;
			next = nxt;
			data = val;
		}
	};

	Node * pHead;
	Node * pTail;

	class Iterator
	{
	public:
		Iterator();
		Iterator(Node* startNode);

		Iterator& operator++();
		Iterator operator++(int);
		Iterator& operator--();
		Iterator operator--(int);

		T& operator*() const;

		bool operator==(const Iterator& rhs) const;
		bool operator!=(const Iterator& rhs) const;
	};

	void Insert(const Iterator& it, const T& val);

	Iterator begin();
	Iterator end();
};

template<typename T>
TList<T>::TList()
{
}

template<typename T>
TList<T>::~TList()
{
}

template<typename T>
void TList<T>::Push_Front(const T & value)
{
}

template<typename T>
void TList<T>::Push_Back(const T & value)
{
}

template<typename T>
T & TList<T>::Front()
{
	assert(false && "NOT YET IMPLEMENTED");
	T a;
	return a;
}

template<typename T>
T& TList<T>::Back()
{
	// TODO: insert return statement here
	assert(false && "NOT YET IMPLEMENTED");
	T a;
	return a;
}

template<typename T>
void TList<T>::Pop_Front()
{
}

template<typename T>
void TList<T>::Pop_Back()
{
}

template<typename T>
size_t TList<T>::Size() const
{
	return size_t();
}

template<typename T>
bool TList<T>::Empty() const
{
	return false;
}

template<typename T>
void TList<T>::Insert(const Iterator& it, const T& val)
{
}

template<typename T>
typename TList<T>::Iterator TList<T>::begin()
{
	return Iterator();
}

template<typename T>
typename TList<T>::Iterator TList<T>::end()
{
	return Iterator();
}

template<typename T>
TList<T>::Iterator::Iterator()
{

}

template<typename T>
TList<T>::Iterator::Iterator(Node* startNode)
{

}

template<typename T>
typename TList<T>::Iterator& TList<T>::Iterator::operator++()
{
	assert(false && "NOT YET IMPLEMENTED");
	return *this;
}

template<typename T>
typename TList<T>::Iterator TList<T>::Iterator::operator++(int)
{
	assert(false && "NOT YET IMPLEMENTED");
	return TList<T>::Iterator();
}

template<typename T>
typename TList<T>::Iterator& TList<T>::Iterator::operator--()
{
	assert(false && "NOT YET IMPLEMENTED");
	return *this;
}

template<typename T>
typename TList<T>::Iterator TList<T>::Iterator::operator--(int)
{
	assert(false && "NOT YET IMPLEMENTED");
	return TList<T>::Iterator();
}

template<typename T>
T& TList<T>::Iterator::operator*() const
{
	assert(false && "NOT YET IMPLEMENTED");
	T a;
	return a;
}

template<typename T>
bool TList<T>::Iterator::operator==(const Iterator& rhs) const
{
	return false;
}

template<typename T>
bool TList<T>::Iterator::operator!=(const Iterator& rhs) const
{
	return false;
}
