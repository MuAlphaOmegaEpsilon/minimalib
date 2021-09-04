#pragma once

extern "C" [[noreturn, gnu::naked, gnu::used]] void _start()
{
	asm("xor %rbp,%rbp");			   // Clean base pointer, required by ABI
	asm("mov (%rsp),%rdi");			   // argc
	asm("lea 8(%rsp),%rsi");		   // argv
	asm("lea 8(%rsi, %rdi, 8), %rdx"); // envp
	asm("call main");				   // Call main(argc, argv, envp)
	asm("mov %rax,%rdi");			   // Prepare main return value before exit call
	asm("mov $60,%rax");			   // Load exit code
	asm("syscall");
}
