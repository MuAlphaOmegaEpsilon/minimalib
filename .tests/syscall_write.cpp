#include <entrypoint/start.hpp>
#include <syscall/ewrite.hpp>
#include <syscall/write.hpp>
#include <test/test.hpp>

bool to_stdout()
{
	bool pass {true};
	pass &= TEST(write("") == 1);
	pass &= TEST(write(STDOUT, "") == 1);
	pass &= TEST(write(STDOUT, "", 1) == 1);
	pass &= TEST(write("A\n") == 3);
	pass &= TEST(write(STDOUT, "B\n") == 3);
	pass &= TEST(write(STDOUT, "C\n", 2) == 2);
	return pass;
}

bool to_stderr()
{
	bool pass {true};
	pass &= TEST(write(STDERR, "") == 1);
	pass &= TEST(write(STDERR, "", 1) == 1);
	pass &= TEST(write(STDERR, "B\n") == 3);
	pass &= TEST(write(STDERR, "C\n", 2) == 2);
	return pass;
}

bool generate_error()
{
	bool pass {true};
	pass &= TEST(write(fd_t {123}, "") == ewrite::BADF);
	pass &= TEST(write(STDOUT, "", UINT64_MAX) == ewrite::FAULT);
	return pass;
}

extern "C" int main()
{
	TEST_MAIN();
	bool pass {true};
	pass &= TEST_SUITE(to_stdout());
	pass &= TEST_SUITE(to_stderr());
	pass &= TEST_SUITE(generate_error());
	return !pass;
}
