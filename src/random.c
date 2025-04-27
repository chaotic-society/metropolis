/**
 * @file random.c
 * @author Andrea Di Antonio (github.com/diantonioandrea), Mattia Isgrò (github.com/mattiaisgro)
 * @brief 
 * @date 2025-04-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#if !defined(NDEBUG)
#include <assert.h>
#endif

#include <stdlib.h>

#define _USE_MATH_DEFINES
#include <math.h>

#include "random.h"

/**
 * @brief Uniform distribution in [0, 1].
 * 
 * @return real_t Random number.
 */
real_t random_uniform() { return (real_t) rand() / RAND_MAX; }

/**
 * @brief Multivariate centered Gaussian distribution.
 * 
 * @param Vector_0 Vector.
 * @param Vector_1 Deviations.
 */
void random_gaussian(vector_t* Vector_0, const vector_t* Vector_1) {
    #if !defined(NDEBUG)
    assert(Vector_0->size == Vector_1->size);
    #endif

    for(unsigned int j = 0; j < Vector_0->size; ++j) {
        #if !defined(NDEBUG)
        real_t Real = random_uniform();

        do {
            Real = random_uniform();
        } while(Real <= TOLERANCE);

        Vector_0->elements[j] = sqrtl(-2.0L * log(Real)) * sin(2.0L * M_PI * random_uniform()) * Vector_1->elements[j];
        #else
        Vector_0->elements[j] = sqrtl(-2.0L * log(random_uniform())) * sin(2.0L * M_PI * random_uniform()) * Vector_1->elements[j];
        #endif
    }
}