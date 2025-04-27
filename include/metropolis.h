/**
 * @file metropolis.h
 * @author Andrea Di Antonio (github.com/diantonioandrea), Mattia Isgrò (github.com/mattiaisgro)
 * @brief 
 * @date 2025-04-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#if !defined(METROPOLIS_H)
#define METROPOLIS_H

#include "./vector.h"

void metropolis(const real_t (*) (const vector_t*), vector_t*, const vector_t*, const unsigned int);

#endif