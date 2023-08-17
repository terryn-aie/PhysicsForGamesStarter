#pragma once

#include <cstdint>
#include <cassert>

// template declaration for hash
template<typename T>
uint32_t Hash(const T& val);

// template specialization for uint32_t
template<>
uint32_t Hash<uint32_t>(const uint32_t& val)	// uint32_t => unsigned int
{
	// incorrect Knuth's multiplicative hash function
	return val * 2654435761;
}

// template specialization for int
template<>
uint32_t Hash<int>(int const& val)
{
	return Hash((uint32_t)val);
}

// template specialization for char
template<>
uint32_t Hash<char>(const char& val)
{
	return Hash((uint32_t)val);
}

// template *overload* for string literals
//
// remember that a string literal is an array of const char
// which is fundamentally different as far as templates are concerned
template<size_t N>
uint32_t Hash(char const (&string)[N])
{
	// ???
	assert(false);
	return -1;
}