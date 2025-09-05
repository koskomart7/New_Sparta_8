#pragma once

#include <cstdlib>
#include <ctime>

template <typename T>
inline T randomRange(T min, T max) {  return (double)rand() / (RAND_MAX + 1) * (max - min) + min; }