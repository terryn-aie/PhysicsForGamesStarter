#pragma once

#include <cassert>

template<typename T>
class TForwardList
{
	struct Node
	{
		T data;
		Node * next;
	};

	Node * head;
public:
	TForwardList();
	~TForwardList();

	void Push_Front(const T & val);
	void Pop_Front();

	T & Front();
	const T & Front() const;

	void Remove(const T& val);
};

template<typename T>
TForwardList<T>::TForwardList()
{
	head = nullptr;
}

template<typename T>
TForwardList<T>::~TForwardList()
{
	while (head != nullptr)
	{
		Pop_Front();
	}
}

template<typename T>
void TForwardList<T>::Push_Front(const T & val)
{
	// create the node
	Node * babyNode = new Node();
	
	// give it data
	babyNode->data = val;
	// point it to the previous head
	babyNode->next = head;

	// babyNode becomes the new head
	head = babyNode;
}

template<typename T>
void TForwardList<T>::Pop_Front()
{
	assert(head != nullptr && "Head was null when attempting to pop it");

	// keep the old head
	Node * oldHead = head;

	// remove the old head from the list
	head = head->next;

	// clean-up the old head
	delete oldHead;
}

template<typename T>
T& TForwardList<T>::Front()
{
	return head->data;
}

template<typename T>
const T& TForwardList<T>::Front() const
{
	return head->data;
}