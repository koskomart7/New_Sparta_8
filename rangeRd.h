#pragma once

#include <random>

int randomRange(int min, int max) { return (double) rand() / (RAND_MAX + 1) * (max - min) + min; }