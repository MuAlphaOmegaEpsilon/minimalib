#include "itos10.hpp"
#include "uitos10.hpp"
#include <stdio.h>

void do_nothing(const char*) noexcept;

int main()
{
	puts("Signed integral values:");
	{
		char buffer[21] {};
		puts(itos10(static_cast<int64_t>(INT64_MAX), &buffer));
	}
	{
		char buffer[21] {};
		puts(itos10(static_cast<int64_t>(INT64_MIN), &buffer));
	}
	{
		char buffer[12] {};
		puts(itos10(static_cast<int32_t>(INT32_MAX), &buffer));
	}
	{
		char buffer[12] {};
		puts(itos10(static_cast<int32_t>(INT32_MIN), &buffer));
	}
	{
		char buffer[7] {};
		puts(itos10(static_cast<int16_t>(INT16_MAX), &buffer));
	}
	{
		char buffer[7] {};
		puts(itos10(static_cast<int16_t>(INT16_MIN), &buffer));
	}
	{
		char buffer[5] {};
		puts(itos10(static_cast<int8_t>(INT8_MAX), &buffer));
	}
	{
		char buffer[5] {};
		puts(itos10(static_cast<int8_t>(INT8_MIN), &buffer));
	}
	{
		char buffer[5] {};
		puts(itos10(static_cast<int8_t>(0), &buffer));
	}

	puts("Unsigned integral values:");
	{
		char buffer[21] {};
		puts(uitos10(static_cast<uint64_t>(UINT64_MAX), &buffer));
	}
	{
		char buffer[11] {};
		puts(uitos10(static_cast<uint32_t>(UINT32_MAX), &buffer));
	}
	{
		char buffer[6] {};
		puts(uitos10(static_cast<uint16_t>(UINT16_MAX), &buffer));
	}
	{
		char buffer[4] {};
		puts(uitos10(static_cast<uint8_t>(UINT8_MAX), &buffer));
	}
	{
		char buffer[4] {};
		puts(uitos10(static_cast<uint8_t>(0), &buffer));
	}
	return 0;
}
