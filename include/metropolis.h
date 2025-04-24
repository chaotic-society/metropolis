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

/**
 * @brief Real numbers.
 * 
 */
typedef double real_t;

/**
 * @brief Vector.
 * 
 */
typedef struct Vector {
    real_t* elements;
    unsigned int size;
} vector_t;

// Metropolis.
vector_t metropolis(const real_t (*) (const vector_t), vector_t*, const vector_t, const unsigned int);

#endif