#pragma once

#ifdef __linux__
extern "C" [[noreturn, gnu::naked, gnu::used]] void _start()
{
	asm("xor %rbp,%rbp");				  // Clean base pointer, required by ABI
	asm("mov (%rsp),%rdi");				  // argc
	asm("lea 8(%rsp),%rsi");			  // argv
	asm("lea 8(%rsi, %rdi, 8), %rdx");	  // envp
	asm("andq $0xFFFFFFFFFFFFFFF0,%rsp"); // Align the stack to 16byte
	asm("call main");					  // Call main(argc, argv, envp)
	asm("mov %rax,%rdi");				  // Prepare main return value before exit call
	asm("mov $60,%rax");				  // Load exit code
	asm("syscall");
}
#elif __APPLE__
extern "C" [[noreturn, gnu::naked, gnu::used]] void start() asm("start");
extern "C" [[noreturn, gnu::naked, gnu::used]] void start()
{
	asm("xor %rbp,%rbp");				  // Clean base pointer, required by ABI
	asm("mov (%rsp),%rdi");				  // argc
	asm("lea 8(%rsp),%rsi");			  // argv
	asm("lea 8(%rsi, %rdi, 8), %rdx");	  // envp
	asm("andq $0xFFFFFFFFFFFFFFF0,%rsp"); // Align the stack to 16byte
	asm("call _main");					  // Call main(argc, argv, envp)
	asm("mov %rax,%rdi");				  // Prepare main return value before exit call
	asm("mov $0x2000001,%rax");			  // Load exit code
	asm("syscall");
}
#else
extern "C" [[noreturn, gnu::naked, gnu::used]] void start()
{
	asm("xor %rbp,%rbp");				  // Clean base pointer, required by ABI
	asm("mov (%rsp),%rcx");				  // argc
	asm("lea 8(%rsp),%rdx");			  // argv
	asm("lea 8(%rcx, %rdx, 8), %rdx");	  // envp
	asm("andq $0xFFFFFFFFFFFFFFF0,%rsp"); // Align the stack to 16byte
	asm("call _main");					  // Call main(argc, argv, envp)
	asm("push %rax");					  // Prepare main return value before exit call
	asm("mov $0x002C,%rax");			  // Load exit code
	asm("int 2E");
}
#endif
