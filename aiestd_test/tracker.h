#pragma once

#include <string>

#include "CppUnitTest.h"

class Tracker
{
	static int _count;

public:
	int data;

	Tracker()
	{
		++_count;
		data = 0;
	}

	Tracker(int newData)
	{
		++_count;
		data = newData;
	}

	Tracker(const Tracker &other)
	{
		++_count;
		data = other.data;
	}

	~Tracker()
	{
		--_count;
	}

	bool operator==(const Tracker &other) const
	{
		return data == other.data;
	}

	bool operator!=(const Tracker &other) const
	{
		return *this != other;
	}

	bool operator<(const Tracker &other) const
	{
		return data < other.data;
	}

	bool operator>(const Tracker &other) const
	{
		return data > other.data;
	}

	bool operator<=(const Tracker &other) const
	{
		return data <= other.data;
	}

	bool operator>=(const Tracker &other) const
	{
		return data >= other.data;
	}

	void static Reset()
	{
		_count = 0;
	}

	int static Count()
	{
		return _count;
	}

	bool static IsZero()
	{
		return _count == 0;
	}
};

namespace Microsoft
{
	namespace VisualStudio
	{
		namespace CppUnitTestFramework
		{
			template<> inline std::wstring ToString<Tracker>(const Tracker &t) { return std::to_wstring(t.data); }
		}
	}
}
