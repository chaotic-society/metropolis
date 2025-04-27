/**
 * @file metropolis.c
 * @author Andrea Di Antonio (github.com/diantonioandrea), Mattia Isgrò (github.com/mattiaisgro)
 * @brief 
 * @date 2025-04-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#if !defined(NDEBUG)
#include <assert.h>
#endif

#include "random.h"
#include "metropolis.h"

/**
 * @brief Simple Metropolis.
 * 
 * @param Function Function.
 * @param Vector_0 State.
 * @param Vector_1 Deviations.
 * @param Natural Depth.
 */
void metropolis(const real_t (*Function) (const vector_t*), vector_t* Vector_0, const vector_t* Vector_1, const unsigned int Natural) {
    #if !defined(NDEBUG)
    assert(Vector_0->size == Vector_1->size);
    #endif

    vector_t* Vector_2 = new_Vector(Vector_0->size);

    for(unsigned int j = 0; j < Natural; ++j) {

        // Sample.
        random_gaussian(Vector_2, Vector_1);

        // Proposal.
        sum_Vector(Vector_2, Vector_0);

        // Acceptance and step.
        if(random_uniform() < Function(Vector_2) / Function(Vector_0))
            copy_Vector(Vector_0, Vector_2);
    }

    free_Vector(Vector_2);
}