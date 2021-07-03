#include "start.hpp"
#include "sys_write.hpp"
#include "test.hpp"

bool to_stdout()
{
	TEST_CASE
	bool pass {true};
	pass &= TEST(sys_write("") == 0);
	pass &= TEST(sys_write(STDOUT, "") == 0);
	pass &= TEST(sys_write(STDOUT, "", 1) == 1);
	pass &= TEST(sys_write("A\n") == 2);
	pass &= TEST(sys_write(STDOUT, "B\n") == 2);
	pass &= TEST(sys_write(STDOUT, "C\n", 2) == 2);
	return pass;
}

bool to_stderr()
{
	TEST_CASE
	bool pass {true};
	pass &= TEST(sys_write(STDERR, "") == 0);
	pass &= TEST(sys_write(STDERR, "", 1) == 1);
	pass &= TEST(sys_write(STDERR, "B\n") == 2);
	pass &= TEST(sys_write(STDERR, "C\n", 2) == 2);
	return pass;
}

bool generate_error()
{
	TEST_CASE
	bool pass {true};
	pass &= TEST(sys_write(fd_t {123}, "") < 0);
	pass &= TEST(sys_write(STDOUT, "", UINT64_MAX) < 0);
	return pass;
}

int main()
{
	TEST_MAIN
	bool pass {true};
	pass &= to_stdout();
	pass &= to_stderr();
	pass &= generate_error();
	return pass ? 0 : 1;
}
