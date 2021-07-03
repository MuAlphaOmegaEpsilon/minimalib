#include "str.hpp"
#include "start.hpp"
#include "test.hpp"
bool str_view_initializers()
{
	TEST_CASE
	constexpr str_t foo_0 = str("foo 0");

	char buffer[]{"foo_1"};
	str_t foo_1 = str(buffer);

	return TEST(foo_0.is_view()  )
	    && TEST(foo_1.is_view()  )
	    && TEST(foo_0.length == 5)
	    && TEST(foo_1.length == 5)
	    && TEST(foo_0.size   == 0)
	    && TEST(foo_1.size   == 0);
}
bool str_initializers()
{
	TEST_CASE
	char buffer_0[9]{"foo_0"};
	str_t foo_0 = str(&buffer_0);

	char buffer_1[]{"foo_1"};
	str_t foo_1 = str(&buffer_1);

	return TEST(!foo_0.is_view() )
	    && TEST(!foo_1.is_view() )
	    && TEST(foo_0.length == 5)
	    && TEST(foo_1.length == 5)
	    && TEST(foo_0.size   == 9)
	    && TEST(foo_1.size   == 6);
}
int main()
{
	TEST_MAIN
	bool pass {true};
	pass &= str_view_initializers();
	pass &= str_initializers();
	return pass ? 0 : 1;
}

