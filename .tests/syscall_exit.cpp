#include <entrypoint/start.hpp>
#include <syscall/exit.hpp>
#include <test/test.hpp>

extern "C" int main()
{
	TEST_MAIN();
	exit(EXIT_SUCCESS);
	return EXIT_FAILURE;
}
