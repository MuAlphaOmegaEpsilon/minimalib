#include <stdint.h>

struct str_t
{
union
{
	char* data;
	const char* view;
};
	uint32_t length;
	uint32_t size;
};

str_t cat_unsafe_0(str_t dst, uint64_t v) noexcept
{
	const char n00 = static_cast<char>('0' + (v % 10));
	v /= 10;
	const char n01 = static_cast<char>('0' + (v % 10));
	v /= 10;
	const char n02 = static_cast<char>('0' + (v % 10));
	v /= 10;
	const char n03 = static_cast<char>('0' + (v % 10));
	v /= 10;
	const char n04 = static_cast<char>('0' + (v % 10));
	v /= 10;
	const char n05 = static_cast<char>('0' + (v % 10));
	v /= 10;
	const char n06 = static_cast<char>('0' + (v % 10));
	v /= 10;
	const char n07 = static_cast<char>('0' + (v % 10));
	v /= 10;
	const char n08 = static_cast<char>('0' + (v % 10));
	v /= 10;
	const char n09 = static_cast<char>('0' + (v % 10));
	v /= 10;
	const char n10 = static_cast<char>('0' + (v % 10));
	v /= 10;
	const char n11 = static_cast<char>('0' + (v % 10));
	v /= 10;
	const char n12 = static_cast<char>('0' + (v % 10));
	v /= 10;
	const char n13 = static_cast<char>('0' + (v % 10));
	v /= 10;
	const char n14 = static_cast<char>('0' + (v % 10));
	v /= 10;
	const char n15 = static_cast<char>('0' + (v % 10));
	v /= 10;
	const char n16 = static_cast<char>('0' + (v % 10));
	v /= 10;
	const char n17 = static_cast<char>('0' + (v % 10));
	v /= 10;
	const char n18 = static_cast<char>('0' + (v % 10));
	v /= 10;
	const char n19 = static_cast<char>('0' + (v % 10));
	dst.data[dst.length++] = n19;
	dst.data[dst.length++] = n18;
	dst.data[dst.length++] = n17;
	dst.data[dst.length++] = n16;
	dst.data[dst.length++] = n15;
	dst.data[dst.length++] = n14;
	dst.data[dst.length++] = n13;
	dst.data[dst.length++] = n12;
	dst.data[dst.length++] = n11;
	dst.data[dst.length++] = n10;
	dst.data[dst.length++] = n09;
	dst.data[dst.length++] = n08;
	dst.data[dst.length++] = n07;
	dst.data[dst.length++] = n06;
	dst.data[dst.length++] = n05;
	dst.data[dst.length++] = n04;
	dst.data[dst.length++] = n03;
	dst.data[dst.length++] = n02;
	dst.data[dst.length++] = n01;
	dst.data[dst.length++] = n00;
	return dst;
}

str_t cat_unsafe_1(str_t dst, uint64_t v) noexcept
{
	const unsigned int n00 = v % 10;
	v /= 10;
	const unsigned int n01 = v % 10;
	v /= 10;
	const unsigned int n02 = v % 10;
	v /= 10;
	const unsigned int n03 = v % 10;
	v /= 10;
	const unsigned int n04 = v % 10;
	v /= 10;
	const unsigned int n05 = v % 10;
	v /= 10;
	const unsigned int n06 = v % 10;
	v /= 10;
	const unsigned int n07 = v % 10;
	v /= 10;
	const unsigned int n08 = v % 10;
	v /= 10;
	const unsigned int n09 = v % 10;
	v /= 10;
	const unsigned int n10 = v % 10;
	v /= 10;
	const unsigned int n11 = v % 10;
	v /= 10;
	const unsigned int n12 = v % 10;
	v /= 10;
	const unsigned int n13 = v % 10;
	v /= 10;
	const unsigned int n14 = v % 10;
	v /= 10;
	const unsigned int n15 = v % 10;
	v /= 10;
	const unsigned int n16 = v % 10;
	v /= 10;
	const unsigned int n17 = v % 10;
	v /= 10;
	const unsigned int n18 = v % 10;
	v /= 10;
	const unsigned int n19 = v % 10;
	dst.data[dst.length++] = static_cast<char>('0' + n19);
	dst.data[dst.length++] = static_cast<char>('0' + n18);
	dst.data[dst.length++] = static_cast<char>('0' + n17);
	dst.data[dst.length++] = static_cast<char>('0' + n16);
	dst.data[dst.length++] = static_cast<char>('0' + n15);
	dst.data[dst.length++] = static_cast<char>('0' + n14);
	dst.data[dst.length++] = static_cast<char>('0' + n13);
	dst.data[dst.length++] = static_cast<char>('0' + n12);
	dst.data[dst.length++] = static_cast<char>('0' + n11);
	dst.data[dst.length++] = static_cast<char>('0' + n10);
	dst.data[dst.length++] = static_cast<char>('0' + n09);
	dst.data[dst.length++] = static_cast<char>('0' + n08);
	dst.data[dst.length++] = static_cast<char>('0' + n07);
	dst.data[dst.length++] = static_cast<char>('0' + n06);
	dst.data[dst.length++] = static_cast<char>('0' + n05);
	dst.data[dst.length++] = static_cast<char>('0' + n04);
	dst.data[dst.length++] = static_cast<char>('0' + n03);
	dst.data[dst.length++] = static_cast<char>('0' + n02);
	dst.data[dst.length++] = static_cast<char>('0' + n01);
	dst.data[dst.length++] = static_cast<char>('0' + n00);
	return dst;
}

str_t cat_unsafe_2(str_t dst, uint64_t v) noexcept
{
	const unsigned int n00 = (v /        1UL) % 10;
	const unsigned int n01 = (v /        10UL) % 10;
	const unsigned int n02 = (v /        100UL) % 10;
	const unsigned int n03 = (v /        1000UL) % 10;
	const unsigned int n04 = (v /        10000UL) % 10;
	const unsigned int n05 = (v /        100000UL) % 10;
	const unsigned int n06 = (v /        1000000UL) % 10;
	const unsigned int n07 = (v /        10000000UL) % 10;
	const unsigned int n08 = (v /        100000000UL) % 10;
	const unsigned int n09 = (v /        1000000000UL) % 10;
	const unsigned int n10 = (v /        10000000000UL) % 10;
	const unsigned int n11 = (v /        100000000000UL) % 10;
	const unsigned int n12 = (v /        1000000000000UL) % 10;
	const unsigned int n13 = (v /        10000000000000UL) % 10;
	const unsigned int n14 = (v /        100000000000000UL) % 10;
	const unsigned int n15 = (v /        1000000000000000UL) % 10;
	const unsigned int n16 = (v /        10000000000000000UL) % 10;
	const unsigned int n17 = (v /        100000000000000000UL) % 10;
	const unsigned int n18 = (v /        1000000000000000000UL) % 10;
	const unsigned int n19 = (v /        10000000000000000000UL) % 10;
	dst.data[dst.length++] = static_cast<char>('0' + n19);
	dst.data[dst.length++] = static_cast<char>('0' + n18);
	dst.data[dst.length++] = static_cast<char>('0' + n17);
	dst.data[dst.length++] = static_cast<char>('0' + n16);
	dst.data[dst.length++] = static_cast<char>('0' + n15);
	dst.data[dst.length++] = static_cast<char>('0' + n14);
	dst.data[dst.length++] = static_cast<char>('0' + n13);
	dst.data[dst.length++] = static_cast<char>('0' + n12);
	dst.data[dst.length++] = static_cast<char>('0' + n11);
	dst.data[dst.length++] = static_cast<char>('0' + n10);
	dst.data[dst.length++] = static_cast<char>('0' + n09);
	dst.data[dst.length++] = static_cast<char>('0' + n08);
	dst.data[dst.length++] = static_cast<char>('0' + n07);
	dst.data[dst.length++] = static_cast<char>('0' + n06);
	dst.data[dst.length++] = static_cast<char>('0' + n05);
	dst.data[dst.length++] = static_cast<char>('0' + n04);
	dst.data[dst.length++] = static_cast<char>('0' + n03);
	dst.data[dst.length++] = static_cast<char>('0' + n02);
	dst.data[dst.length++] = static_cast<char>('0' + n01);
	dst.data[dst.length++] = static_cast<char>('0' + n00);
	return dst;
}


str_t cat_unsafe_3(str_t dst, uint64_t v) noexcept
{
	dst.data[dst.length++] = static_cast<char>('0' + (v / 10000000000000000000UL % 10));
	dst.data[dst.length++] = static_cast<char>('0' + (v /  1000000000000000000UL % 10));
	dst.data[dst.length++] = static_cast<char>('0' + (v /   100000000000000000UL % 10));
	dst.data[dst.length++] = static_cast<char>('0' + (v /    10000000000000000UL % 10));
	dst.data[dst.length++] = static_cast<char>('0' + (v /     1000000000000000UL % 10));
	dst.data[dst.length++] = static_cast<char>('0' + (v /      100000000000000UL % 10));
	dst.data[dst.length++] = static_cast<char>('0' + (v /       10000000000000UL % 10));
	dst.data[dst.length++] = static_cast<char>('0' + (v /        1000000000000UL % 10));
	dst.data[dst.length++] = static_cast<char>('0' + (v /         100000000000UL % 10));
	dst.data[dst.length++] = static_cast<char>('0' + (v /          10000000000UL % 10));
	dst.data[dst.length++] = static_cast<char>('0' + (v /           1000000000UL % 10));
	dst.data[dst.length++] = static_cast<char>('0' + (v /            100000000UL % 10));
	dst.data[dst.length++] = static_cast<char>('0' + (v /             10000000UL % 10));
	dst.data[dst.length++] = static_cast<char>('0' + (v /              1000000UL % 10));
	dst.data[dst.length++] = static_cast<char>('0' + (v /               100000UL % 10));
	dst.data[dst.length++] = static_cast<char>('0' + (v /                10000UL % 10));
	dst.data[dst.length++] = static_cast<char>('0' + (v /                 1000UL % 10));
	dst.data[dst.length++] = static_cast<char>('0' + (v /                  100UL % 10));
	dst.data[dst.length++] = static_cast<char>('0' + (v /                   10UL % 10));
	dst.data[dst.length++] = static_cast<char>('0' + (v /                    1UL % 10));
	return dst;
}

static void cat_0(benchmark::State& state) {
  uint64_t i{};
  char buffer[32]{};
  str_t s{};
  for (auto _ : state) {
    benchmark::DoNotOptimize(s = cat_unsafe_0(str_t{.data=buffer}, i++));
  }
}
static void cat_1(benchmark::State& state) {
  uint64_t i{};
  char buffer[32]{};
  str_t s{};
  for (auto _ : state) {
    benchmark::DoNotOptimize(s = cat_unsafe_1(str_t{.data=buffer}, i++));
  }
}
static void cat_2(benchmark::State& state) {
  uint64_t i{};
  char buffer[32]{};
  str_t s{};
  for (auto _ : state) {
    benchmark::DoNotOptimize(s = cat_unsafe_2(str_t{.data=buffer}, i++));
  }
}
static void cat_3(benchmark::State& state) {
  uint64_t i{};
  char buffer[32]{};
  str_t s{};
  for (auto _ : state) {
    benchmark::DoNotOptimize(s = cat_unsafe_3(str_t{.data=buffer}, i++));
  }
}

BENCHMARK(cat_0);
BENCHMARK(cat_1);
BENCHMARK(cat_2);
BENCHMARK(cat_3);



