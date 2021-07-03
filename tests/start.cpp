#include "start.hpp"
#include "test.hpp"
bool is_argc_valid(int argc)
{
	TEST_CASE
	return TEST(argc == 1);
}
bool is_argv_valid(char** argv)
{
	TEST_CASE
	return TEST(argv);
}
bool is_envp_valid(char** envp)
{
	TEST_CASE
	return TEST(envp);
}
int main(int argc, char* argv[], char* envp[])
{
	TEST_MAIN
	bool pass {true};
	pass &= is_argc_valid(argc);
	pass &= is_argv_valid(argv);
	pass &= is_envp_valid(envp);
	return pass ? 0 : 1;
}
