/**
 * @file random.h
 * @author Andrea Di Antonio (github.com/diantonioandrea), Mattia Isgrò (github.com/mattiaisgro)
 * @brief 
 * @date 2025-04-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#if !defined(RANDOM_H)
#define RANDOM_H

#include "./vector.h"

// Uniform.

real_t random_uniform();

// Gaussian.

void random_gaussian(vector_t*, const vector_t*);

#endif