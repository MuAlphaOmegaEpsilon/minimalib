#pragma once

constexpr int EXIT_SUCCESS {0};
constexpr int EXIT_FAILURE {1};

[[gnu::naked, noreturn]] static void sys_exit(int exit_code) noexcept
{
#if __gnu_linux__ && __x86_64__
	asm("mov $60,%rax");
	asm("syscall");
#elif __APPLE__ && __x86_64__
	asm("mov $0x2000001,%rax");
	asm("syscall");
// #elif _WIN32 && __x86_64__
#else
	#pragma message("Unimplemented exit function")
#endif
}
