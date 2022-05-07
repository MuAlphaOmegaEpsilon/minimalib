#pragma once

extern "C" [[noreturn, gnu::naked, gnu::used]] void start()
{
#if __linux__ && __x86_64__
	asm("xor %rbp, %rbp");				   // Clean base pointer, required by ABI
	asm("mov (%rsp), %rdi");			   // argc
	asm("lea 8(%rsp), %rsi");			   // argv
	asm("lea 8(%rsi, %rdi, 8), %rdx");	   // envp
	asm("andq $0xFFFFFFFFFFFFFFF0, %rsp"); // Align the stack to 16byte
	asm("call main");					   // Call main(argc, argv, envp)
	asm("mov %rax, %rdi");				   // Prepare main return value before exit call
	asm("mov $60, %rax");				   // Load exit code
	asm("syscall");
#elif __APPLE__ && __x86_64__
	asm("xor %rbp, %rbp");				   // Clean base pointer, required by ABI
	asm("mov (%rsp), %rdi");			   // argc
	asm("lea 8(%rsp), %rsi");			   // argv
	asm("lea 8(%rsi, %rdi, 8), %rdx");	   // envp
	asm("andq $0xFFFFFFFFFFFFFFF0, %rsp"); // Align the stack to 16byte
	asm("call _main");					   // Call main(argc, argv, envp)
	asm("mov %rax, %rdi");				   // Prepare main return value before exit call
	asm("mov $0x2000001, %rax");		   // Load exit code
	asm("syscall");
#else
	#pragma message("Unimplemented start function")
#endif
}
