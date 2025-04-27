/**
 * @file vector.h
 * @author Andrea Di Antonio (github.com/diantonioandrea), Mattia Isgrò (github.com/mattiaisgro)
 * @brief Real vectors.
 * @date 2025-04-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#if !defined(VECTOR_H)
#define VECTOR_H

// Real numbers.

/**
 * @brief Real numbers.
 * 
 */
typedef double real_t;

#if !defined(TOLERANCE)

/**
 * @brief Real tolerance.
 * 
 */
#define TOLERANCE 2.0E-16L
#endif

// Vectors.

/**
 * @brief Real vectors.
 * 
 */
typedef struct Vector {
    unsigned int size;
    real_t* elements;
} vector_t;

// Vector methods.

[[nodiscard]] vector_t* new_Vector(const unsigned int);
[[nodiscard]] vector_t* new_Vector_ones(const unsigned int);

void copy_Vector(vector_t*, const vector_t*);
void free_Vector(vector_t*);

void sum_Vector(vector_t*, const vector_t*);
void sub_Vector(vector_t*, const vector_t*);
void mul_Vector(vector_t*, const real_t);
void div_Vector(vector_t*, const real_t);

real_t dot_Vector(const vector_t*, const vector_t*);

void println_Vector(const vector_t*);

#endif