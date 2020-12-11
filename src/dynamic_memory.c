#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "defines.h"
#include "planets.h"

/*
 * Note that function descriptions are in the header files unless the function
 * is static.
 */

/*
 *In this".c" file you will find all the functions related to dynamic memory 
 *issues.
 */

int alloc_planet_list(planet_t **planet, unsigned int num)
{
    *planet = (planet_t *)malloc(num * sizeof(planet_t));

    if(*planet==NULL)                     
    {
        printf("Error! memory not allocated.");
        return ERROR;
    }

    memset(*planet, 0, num * sizeof(planet_t));

    return NO_ERROR;
}
