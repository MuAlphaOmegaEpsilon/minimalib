#include "start.hpp"
#include "sys_exit.hpp"
#include "test.hpp"

int main()
{
	TEST_MAIN
	sys_exit(EXIT_SUCCESS);
	return EXIT_FAILURE;
}
