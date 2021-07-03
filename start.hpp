#pragma once

#if _WIN32
const fd_t STDIN {};
const fd_t STDOUT {};
const fd_t STDERR {};
#endif

// Use the main symbol for the main() function, to prevent discrepancies between compilers and
// operating systems
#define main(...)                                                                                  \
	main(__VA_ARGS__) asm("main");                                                                 \
	int main(__VA_ARGS__)

extern "C" [[
#if __linux__ || __APPLE__
	noreturn,
#endif
	gnu::naked,
	gnu::used]] void
start()
{
#if __linux__ && __x86_64__
	asm("xor %rbp, %rbp");                 // Clean base pointer, required by ABI
	asm("mov (%rsp), %rdi");               // argc
	asm("lea 8(%rsp), %rsi");              // argv
	asm("lea 8(%rsi, %rdi, 8), %rdx");     // envp
	asm("andq $0xFFFFFFFFFFFFFFF0, %rsp"); // Align the stack to 16byte
	asm("call main");                      // Call main(argc, argv, envp)
	asm("mov %rax, %rdi");                 // Prepare main return value before exit call
	asm("mov $60, %rax");                  // Load exit code
	asm("syscall");
#elif __APPLE__ && __x86_64__
	asm("xor %rbp, %rbp");                 // Clean base pointer, required by ABI
	asm("mov (%rsp), %rdi");               // argc
	asm("lea 8(%rsp), %rsi");              // argv
	asm("lea 8(%rsi, %rdi, 8), %rdx");     // envp
	asm("andq $0xFFFFFFFFFFFFFFF0, %rsp"); // Align the stack to 16byte
	asm("call main");                      // Call main(argc, argv, envp)
	asm("mov %rax, %rdi");                 // Prepare main return value before exit call
	asm("mov $0x2000001, %rax");           // Load exit code
	asm("syscall");
#elif _WIN32 && __x86_64__
	#pragma message("Arguments are ordered the other way around")
	asm("mov $-10, %rcx");                 // Request STDIN handle
	asm("call GetStdHandle");              // docs.microsoft.com/en-us/windows/console/getstdhandle
	asm("movl %eax, STDIN(%rip)");         // Populate STDIN variable with GetStdHandle return value
	asm("mov $-11, %rcx");                 // Request STDOUT handle
	asm("call GetStdHandle");              // docs.microsoft.com/en-us/windows/console/getstdhandle
	asm("movl %eax, STDOUT(%rip)");        // Populate STDOUT variable with GetStdHandle return value
	asm("mov $-12, %rcx");                 // Request STDERR handle
	asm("call GetStdHandle");              // docs.microsoft.com/en-us/windows/console/getstdhandle
	asm("movl %eax, STDERR(%rip)");        // Populate STDOUT variable with GetStdHandle return value
	asm("call GetCommandLineA");           // Defined in processenv.h, fills RAX with entire cmdline string
	asm("xor %rcx, %rcx");                 // RCX will be later filled with argc
	asm("xor %r8, %r8");                   // R8 will be later used to count cmdline string length
	asm("mov %rsp, %r9");                  // R9 will be later used to restore the original RSP
	// Start extracting arguments from whole cmdline string
	asm("loop_extract_arg:");
	asm("inc %r8");                        // Increment cmdline string length
	asm("cmpb $0, (%rax, %r8, 1)");        // Compare '\0' against current character
	asm("je loop_extract_arg_end");        // Break the loop if a null termination character is found
	asm("cmpb $32, (%rax, %r8, 1)");       // Compare ' ' against current character
	asm("jle arg_found");                  // Enter the loop body if the argument was found
	asm("jmp loop_extract_arg");           // Perform new loop iteration
	// Loop body
	asm("arg_found:");
	asm("movb $0,(%rax, %r8, 1)");         // Write '\0' at the end of each arg, hence replacing every ' '
	asm("inc %rcx");                       // Increment argc
	asm("inc %r8");                        // Increment cmd line string length
	asm("lea (%rax, %r8, 1), %rdx");       // Compute into RDX the address of the newly found argument
	asm("push %rdx");                      // Add RDX to the list of arguments
	asm("jmp loop_extract_arg");
	// Loop exit
	asm("loop_extract_arg_end:");
	asm("push %rax");                      // Push to the stack argv[0]
	asm("inc %rcx");                       // Increment argc
	// Call main and exit
	asm("mov %rsp, %rdx");                 // Use RSP as argv
	asm("push %r9");                       // Push the previous content of RSP
	asm("call main");
	asm("pop %rsp");                       // Restore the previously pushed content of RSP
	asm("ret");                            // Return back to the OS the value in RAX
#else
	#pragma message("Unimplemented start function")
#endif
}

// Copyright (C) 2024 Tommaso Bonvicini <tommasobonvicini@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-or-later
