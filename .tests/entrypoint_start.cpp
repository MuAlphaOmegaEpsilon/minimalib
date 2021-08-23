#include <entrypoint/start.hpp>
#include <test/test.hpp>

bool is_argc_valid(const int &argc) { return TEST(argc == 1); }
bool is_argv_valid(char **const &argv) { return TEST(argv); }
bool is_envp_valid(char **const &envp) { return TEST(envp); }

int main(int argc, char *argv[], char *envp[]) {
  TEST_MAIN();
  bool pass{true};
  pass &= TEST_SUITE(is_argc_valid(argc));
  pass &= TEST_SUITE(is_argv_valid(argv));
  pass &= TEST_SUITE(is_envp_valid(envp));
  return !pass;
}
