/**
 * @file vector.c
 * @author Andrea Di Antonio (github.com/diantonioandrea), Mattia Isgrò (github.com/mattiaisgro)
 * @brief 
 * @date 2025-04-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#if !defined(NDEBUG)
#include <assert.h>
#include <math.h>
#endif

#include <stdlib.h>
#include <memory.h>

#include "vector.h"

/**
 * @brief Vector "zero-constructor".
 * 
 * @param Natural Size.
 * @return vector_t* 
 */
[[nodiscard]] vector_t* new_Vector(const unsigned int Natural) {
    #if !defined(NDEBUG)
    assert(Natural > 0);
    #endif

    vector_t* Vector = (vector_t*) malloc(sizeof(vector_t));

    #if !defined(NDEBUG)
    assert(Vector != NULL);
    #endif

    Vector->size = Natural;
    Vector->elements = (real_t*) calloc(Natural, sizeof(real_t));

    #if !defined(NDEBUG)
    assert(Vector->elements != NULL);
    #endif

    return Vector;
}

/**
 * @brief Vector "copy"
 * 
 * @param Vector_0 Vector.
 * @param Vector_1 Vector.
 */
void copy_Vector(vector_t* Vector_0, const vector_t* Vector_1) {
    #if !defined(NDEBUG)
    assert(Vector_0->size == Vector_1->size);
    #endif

    memcpy(Vector_0->elements, Vector_1->elements, Vector_0->size * sizeof(real_t));
}

/**
 * @brief Vector "destructor".
 * 
 * @param Vector Vector.
 */
void free_Vector(vector_t* Vector) {
    free(Vector->elements);
    free(Vector);
}

/**
 * @brief Vector sum.
 * 
 * @param Vector_0 Vector.
 * @param Vector_1 Vector.
 */
void sum_Vector(vector_t* Vector_0, const vector_t* Vector_1) {
    #if !defined(NDEBUG)
    assert(Vector_0->size == Vector_1->size);
    #endif

    for(unsigned int j = 0; j < Vector_0->size; ++j)
        Vector_0->elements[j] += Vector_1->elements[j];
}

/**
 * @brief Vector subtraction.
 * 
 * @param Vector_0 Vector.
 * @param Vector_1 Vector.
 */
void sub_Vector(vector_t* Vector_0, const vector_t* Vector_1) {
    #if !defined(NDEBUG)
    assert(Vector_0->size == Vector_1->size);
    #endif

    for(unsigned int j = 0; j < Vector_0->size; ++j)
        Vector_0->elements[j] -= Vector_1->elements[j];
}

/**
 * @brief Vector scalar product.
 * 
 * @param Vector Vector.
 * @param real Scalar.
 */
void mul_Vector(vector_t* Vector, const real_t real) {
    for(unsigned int j = 0; j < Vector->size; ++j)
        Vector->elements[j] *= real;
}

/**
 * @brief Vector scalar division.
 * 
 * @param Vector Vector.
 * @param real Scalar.
 */
void div_Vector(vector_t* Vector, const real_t real) {
    #if !defined(NDEBUG)
    assert(fabs(real) > 2.0E-16L); // [!] Temporary tolerance on small numbers.
    #endif

    for(unsigned int j = 0; j < Vector->size; ++j)
        Vector->elements[j] /= real;
}

/**
 * @brief Vector dot product.
 * 
 * @param Vector_0 Vector.
 * @param Vector_1 Vector.
 * @return real_t Scalar.
 */
real_t dot_Vector(const vector_t* Vector_0, const vector_t* Vector_1) {
    #if !defined(NDEBUG)
    assert(Vector_0->size == Vector_1->size);
    #endif

    real_t real = 0.0;

    for(unsigned int j = 0; j < Vector_0->size; ++j)
        real += Vector_0->elements[j] * Vector_1->elements[j];

    return real;
}