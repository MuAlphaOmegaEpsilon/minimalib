#pragma once
/// \file
/// \brief Generate a unique identifier, starting from a base name.

#include "concat.hpp"
/// Generate a UNIQUE name by appending the line number to the name provided.
#define UNIQUE(basename) CONCAT(basename, __LINE__)
