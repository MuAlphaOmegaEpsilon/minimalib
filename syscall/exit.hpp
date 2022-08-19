#pragma once

constexpr int EXIT_SUCCESS {0};
constexpr int EXIT_FAILURE {1};

[[gnu::naked, maybe_unused, noreturn]] static void exit(int) noexcept
{
#if __gnu_linux__ && __x86_64__
	asm("mov $60,%rax");
	asm("syscall");
#elif __APPLE__ && __x86_64__
	asm("mov $0x2000001,%rax");
	asm("syscall");
#else
	#pragma message("Unimplemented write function")
#endif
}
