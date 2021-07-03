#pragma once
#include "len.hpp"
#include <stdint.h>

// A general purpose sized string with a length.
// In case size is zero, then the string is read-only and null termination is not guaranteed since it may be a substring.
// Reading can be performed through the view member variable, while writing should only be performed through the data member variable in the case of non read-only strings.
struct str_t
{
union
{
	char* data;
	const char* view;
};
	uint32_t length;
	uint32_t size;
	[[nodiscard]] constexpr bool  operator==(const str_t& other) const noexcept;
	[[nodiscard]] constexpr bool  operator==(const char* other)  const noexcept;
	[[nodiscard]] constexpr str_t operator+()                    const noexcept;
	[[nodiscard]] constexpr       operator bool()                const noexcept { return view && length; }
	[[nodiscard]] constexpr str_t to_view()                      const noexcept { return str_t{{.view=data}, length, 0}; }
	[[nodiscard]] constexpr bool  is_view()                      const noexcept { return size == 0; }
};

[[nodiscard]]
constexpr bool str_t::operator==(const str_t& other) const noexcept
{
	if (length != other.length)
		return false;
	for (uint32_t i = 0; i < length; i++)
		if (view[i] != other.view[i])
			return false;
	return true;
}
[[nodiscard]]
constexpr bool str_t::operator==(const char* other) const noexcept
{
	const uint32_t n = len(other);
	if (length != n)
		return false;
	for (uint32_t i = 0; i < length; i++)
		if (view[i] != other[i])
			return false;
	return true;
}

template<uint32_t N>
[[nodiscard]]
constexpr static str_t str(char (&ptr)[N]) noexcept
{
	return str_t{{.data=ptr}, len(ptr), N};
}
[[nodiscard]]
constexpr static str_t str(char* ptr, uint32_t size) noexcept
{
	return str_t{{.data=ptr}, len(ptr), size};
}
[[nodiscard]]
constexpr static str_t str(const char* ptr) noexcept
{
	return str_t{{.view=ptr}, len(ptr), 0};
}

// The length of the string.
[[nodiscard]] constexpr static uint32_t len(str_t s) noexcept
{
	return s.length;
}

template<uint32_t MAX> struct strmax_t { str_t str; };

// The length of the string capped to the maximum allowed length.
template<uint32_t MAX>
[[nodiscard]] constexpr static uint32_t len(strmax_t<MAX> s) noexcept
{
	return MAX < s.length ? MAX : s.length;
}
