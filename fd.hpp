#pragma once
struct fd {
  unsigned int id;
};
static constexpr fd STDIN{0};
static constexpr fd STDOUT{1};
static constexpr fd STDERR{2};
