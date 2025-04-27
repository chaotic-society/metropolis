/**
 * @file random.c
 * @author Andrea Di Antonio (github.com/diantonioandrea), Mattia Isgrò (github.com/mattiaisgro)
 * @brief 
 * @date 2025-04-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "random.h"

#include <stdlib.h>

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

    // [!] To be written.

}