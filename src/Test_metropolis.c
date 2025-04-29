/**
 * @file vector.c
 * @author Andrea Di Antonio (github.com/diantonioandrea), Mattia Isgrò (github.com/mattiaisgro)
 * @brief 
 * @date 2025-04-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdlib.h>
#include <stdio.h>

#include "metropolis.h"

real_t Function(const vector_t*);

int main(int argc, char** argv) {

    const unsigned int Natural_0 = 10; // Size.
    const unsigned int Natural_1 = 16; // Depth.
    const unsigned int Natural_2 = 50; // Tests.

    vector_t* Vector_0 = new_Vector(Natural_0); // State.
    vector_t* Vector_1 = new_Vector_ones(Natural_0); // Deviations.

    // Metropolis.
    for(unsigned int j = 0; j < Natural_2; ++j) {
        metropolis(Function, Vector_0, Vector_1, Natural_1);
        print_Vector(Vector_0);
        
        if (j + 1 < Natural_2)
            printf(",\n");
    }

    // Clean-up.
    free_Vector(Vector_0);
    free_Vector(Vector_1);

    return 0;
}

/**
 * @brief Test function.
 * 
 * @param Vector Vector.
 * @return real_t PDF value (No normalization).
 */
real_t Function(const vector_t* Vector) { return 1.0 / (1.0 + dot_Vector(Vector, Vector)); }