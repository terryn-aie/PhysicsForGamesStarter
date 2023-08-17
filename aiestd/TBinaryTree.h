#pragma once

template <typename T>
class TBinaryTree
{
public:
	struct Vertex
	{
		// data stored in this Vertex
		T data;

		// left connection
		Vertex* left;

		// right connection
		Vertex* right;

		bool HasLeft() const;
		bool HasRight() const;

		Vertex();
	};

	void Insert(const T& value);
	bool Search(const T& value, Vertex*& found);

	TBinaryTree();

private:
	Vertex* root;
};

template<typename T>
bool TBinaryTree<T>::Vertex::HasLeft() const
{

}

template<typename T>
bool TBinaryTree<T>::Vertex::HasRight() const
{

}

template<typename T>
TBinaryTree<T>::Vertex::Vertex()
{
}


template<typename T>
void TBinaryTree<T>::Insert(const T& value)
{
}

template<typename T>
bool TBinaryTree<T>::Search(const T& value, Vertex*& found)
{
	return false;
}

template<typename T>
TBinaryTree<T>::TBinaryTree()
{
}
