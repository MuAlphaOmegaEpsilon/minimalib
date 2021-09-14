#ifdef __gnu_linux__
	#define start _start
	#define SYSCALL_EXIT $60
#elif __APPLE__
	#define main _main
	#define SYSCALL_EXIT $0x2000001
#else
	#error Unsupported platform
#endif

.global start
.text

start:
	xor %rbp,%rbp			   # Clean base pointer, required by ABI
	mov (%rsp),%rdi			   # argc
	lea 8(%rsp),%rsi		   # argv
	lea 8(%rsi, %rdi, 8), %rdx # envp
	andq $0xfffffffffffffff0,%rsp	   # Align the stack to 16byte
	call main				   # Call main(argc, argv, envp)
	mov %rax,%rdi			   # Prepare main return value before exit call
	mov SYSCALL_EXIT,%rax	   # Load exit code
	syscall
