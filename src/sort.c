#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "planets.h"
#include "defines.h"
#include "menu.h"

enum sorting 
{
    mass_sort,
    diameter_sort,
    density_sort,
    gravity_sort,
    escape_velocity_sort,
    rotation_period_sort,
    lenght_of_a_day_sort,
    distance_from_the_sun_sort,
    orbital_period_sort,
    orbital_velocity_sort,
    mean_temperature_sort,
    moons_sort,
    name_sort
};

char available_sort_criteria[AVAILABLE_SORT_CRITERIA][MAX_STR_LENGHT]={
    "Sort by mass",
    "sort by diameter",
    "Sort by density",
    "Sort by gravity",
    "Sort by escape velocity",
    "Sort by rotation period",
    "Sort by lenght of a day",
    "Sort by distance from the sun",
    "Sort by orbital period",
    "Sort by orbital velocity",
    "Sort by mean temperature",
    "Sort by number of satelites",
    "Sort by alphabetical order"
};

int show_available_sort_criteria(void){
  printf("\nAvailable sort criteria:\n");
  printf(".........................................................\n");
  for (int i = 0; i < AVAILABLE_SORT_CRITERIA; ++i)
  {
    printf("%d-%s\n",i+UNIT,available_sort_criteria[i]);
  }
  printf(".........................................................\n");
  return NO_ERROR;
}

/*
 * Compare function based on the mass.
 */

static int mass_com(const void *a, const void *b)
{
    return ((planet_t *)a)->mass < ((planet_t *)b)->mass;
}

/*
 * Compare function based on the diameter.
 */

static int diameter_com(const void *a, const void *b)
{
    return ((planet_t *)a)->diameter < ((planet_t *)b)->diameter;
}

/*
 * Compare function based on the density.
 */

static int density_com(const void *a, const void *b)
{
    return ((planet_t *)a)->density < ((planet_t *)b)->density;
}

/*
 * Compare function based on the gravity.
 */

static int gravity_com(const void *a, const void *b)
{
    return ((planet_t *)a)->gravity < ((planet_t *)b)->gravity;
}

/*
 * Compare function based on the escape velocity.
 */

static int escape_velocity_com(const void *a, const void *b)
{
    return ((planet_t *)a)->escape_velocity < ((planet_t *)b)->escape_velocity;
}

/*
 * Compare function based on the rotation period.
 */

static int rotation_period_com(const void *a, const void *b)
{
    return ((planet_t *)a)->rotation_period < ((planet_t *)b)->rotation_period;
}

/*
 * Compare function based on the length of a day.
 */

static int length_of_a_day_com(const void *a, const void *b)
{
    return ((planet_t *)a)->lenght_of_a_day < ((planet_t *)b)->lenght_of_a_day;
}

/*
 * Compare function based on the distance from the sun.
 */

static int distance_from_the_sun_com(const void *a, const void *b)
{
    return ((planet_t *)a)->distance_from_the_sun < ((planet_t *)b)->distance_from_the_sun;
}

/*
 * Compare function based on the orbital period from the sun.
 */

static int orbital_period_com(const void *a, const void *b)
{
    return ((planet_t *)a)->orbital_period < ((planet_t *)b)->orbital_period;
}

/*
 * Compare function based on the orbital velocity from the sun.
 */

static int orbital_velocity_com(const void *a, const void *b)
{
    return ((planet_t *)a)->orbital_velocity < ((planet_t *)b)->orbital_velocity;
}

/*
 * Compare function based on the mean temperature.
 */

static int mean_temperature_com(const void *a, const void *b)
{
    return ((planet_t *)a)->mean_temperature < ((planet_t *)b)->mean_temperature;
}

/*
 * Compare function based on the number of moons.
 */

static int moons_com(const void *a, const void *b)
{
    return ((planet_t *)a)->moons < ((planet_t *)b)->moons;
}

/*
 * Compare function based on alphabetical order.
 */

static int name_com(const void *a, const void *b)
{
    return strcmp(((planet_t*)a)->name, ((planet_t *)b)->name);
}

int sort_by(planet_t *planet,  unsigned int num)
{
    unsigned int sorting_sort=0;
    show_available_sort_criteria();

    if (selection(&sorting_sort, "Enter the criteria by which it is desired to sort the data") != NO_ERROR)
    {
      printf("Error.\n");
      return ERROR;
    }

   if (sorting_sort>AVAILABLE_SORT_CRITERIA)
    {
      printf("Error.\n");
      return ERROR; 
    }
    /*
     * Function pointer to have a single call to qsort with the right compare
     * function pointer.
     */
    int (*comp_func)(const void *, const void *) = NULL;

    switch (sorting_sort-UNIT)
    {
    case mass_sort:
        comp_func = mass_com;
        break;
    case diameter_sort:
        comp_func = diameter_com;
        break;
    case density_sort:
        comp_func = density_com;
        break;
    case gravity_sort:
        comp_func = gravity_com;
        break;
    case escape_velocity_sort:
        comp_func = escape_velocity_com;
        break;
    case rotation_period_sort:
        comp_func = rotation_period_com;
        break;
    case lenght_of_a_day_sort:
        comp_func = length_of_a_day_com;
        break;
    case distance_from_the_sun_sort:
        comp_func = distance_from_the_sun_com;
        break;
    case orbital_period_sort:
        comp_func = orbital_period_com;
        break;
    case orbital_velocity_sort:
        comp_func = orbital_velocity_com;
        break;
    case mean_temperature_sort:
        comp_func = mean_temperature_com;
        break;
    case moons_sort:
        comp_func = moons_com;
        break;
    case name_sort:
        comp_func = name_com;
        break;
    default:
        comp_func = NULL;
    }

    qsort((void *)planet, num, sizeof(planet_t), comp_func);
}
