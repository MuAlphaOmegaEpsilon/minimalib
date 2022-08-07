#pragma once
#include "../fd.hpp"
[[gnu::naked]] static int close([[maybe_unused]] fd descriptor) noexcept
{
	asm("mov $3,%rax");
	asm("syscall");
	asm("retq");
}
