#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "menu.h"
#include "defines.h"
#include "planets.h"

/*
 * Note that function descriptions are in the header files unless the function
 * is static.
 */

/*
 *In this".c" file you will find all the functions related to displayin any sort
 *of information in the program.
 */

/*
 * Facts that should be available in the data base.
 */
enum specific_fact {
  mass,
  diameter,
  density,
  gravity,
  escape_velocity,
  rotation_period,
  lenght_of_a_day,
  distance_from_the_sun,
  orbital_period,
  orbital_velocity,
  mean_temperature,
  pressure,moons,
  ring_system,
  magnetic_field
};

/*
 * Array of strings in which each string represents a fact that should be available
 * in the data base for each planet or celestial object.
 */

char available_information_in_the_database[AVAILABLE_INFORMATION][MAX_STR_LENGHT]={
    "Mass",
    "Diameter",
    "Density",
    "Gravity",
    "Escape velocity",
    "Rotation period",
    "Lenght of a day",
    "Distance from the sun",
    "Orbital period",
    "Orbital velocity",
    "Mean temperature",
    "Pressure",
    "Moons",
    "Ring system",
    "Magnetic field"
};

void show_available_facts_in_data_base(void)
{
  printf("\nAvailable information in the data base:\n");
  printf(".........................................................\n");
  for (int i = 0; i < AVAILABLE_INFORMATION-UNIT; ++i)
  {
    printf("%d-%s\n",i+UNIT,available_information_in_the_database[i]);
  }
  printf(".........................................................\n");
}


void print_data(planet_t *planet,int selected_planet){
  printf("\n\n%s\n",planet[selected_planet-UNIT].name);
  printf("================================================================\n");
  printf("Mass (10^24kg): %f\n",planet[selected_planet-UNIT].mass);
  printf("Diameter (km): %ld\n",planet[selected_planet-UNIT].diameter);
  printf("Density (kg/m^3): %ld\n",planet[selected_planet-UNIT].density);
  printf("Gravity (m/s^2):%f\n",planet[selected_planet-UNIT].gravity);
  printf("Escape velocity (Km/s):%f\n",planet[selected_planet-UNIT].escape_velocity);
  printf("Rotation period (hours):%f\n",planet[selected_planet-UNIT].rotation_period);
  printf("Lenght of a day (hours):%f\n",planet[selected_planet-UNIT].lenght_of_a_day);
  printf("Distance from the sun (10^6 km):%Lf\n",planet[selected_planet-UNIT].distance_from_the_sun);
  printf("Orbital period (terrestial days):%Lf\n",planet[selected_planet-UNIT].orbital_period);
  printf("Orbital velocity (km/s):%f\n",planet[selected_planet-UNIT].orbital_velocity);
  printf("Mean temperature (C):%d\n",planet[selected_planet-UNIT].mean_temperature);
  printf("Surface pressure (atm):%s\n",planet[selected_planet-UNIT].pressure);
  printf("Amount of known satelites:%u\n",planet[selected_planet-UNIT].moons);
  printf("Does the planet have a ring system?:%s\n",planet[selected_planet-UNIT].ring_system);
  printf("Does the planet have a global magnetic field?:%s\n",planet[selected_planet-UNIT].magnetic_field);
  printf("================================================================\n");
}

void show_planets_in_data_base(planet_t *planet,unsigned int num){
  printf("\nCurrent planets contained in the data base:\n");
  printf("..........................................................\n");

  for (int i = 0; i < num; ++i){
    printf("%d-%s\n",i+UNIT,planet[i].name);
  }
  printf("..........................................................\n");
}


int show_all_data_for_single_a_planet(planet_t *planet,unsigned int num)
{

  show_planets_in_data_base(planet,num);

  unsigned int selected_planet = 0;

  if (selection(&selected_planet, "Enter the plantet of which it's data is wanted") != NO_ERROR)
  {
    printf("Error.\n");
    return ERROR;
    }


 /*The user input needs to be at most the number of planets an celestial
  objects contained in the data base, otherwhise an error should appear.*/
  if (selected_planet>num)
  {
    printf("Error.\n");
    return ERROR;   
  }

  print_data(planet, selected_planet);
  return NO_ERROR;
}

int show_specific_fact_for_a_planet(planet_t *planet,unsigned int num)
{
  show_planets_in_data_base(planet,num);

  unsigned int selected_planet = 0;
  enum specific_fact selected_fact = 0;

  if (selection(&selected_planet, "Enter the planet of which it's data is wanted") != NO_ERROR)
  {
        printf("Error.\n");
        return ERROR;
  }

  /*The user input needs to be at most the number of planets an celestial
  objects contained in the data base, otherwhise an error should appear.*/
  if (selected_planet>num)
  {
    printf("Error.\n");
    return ERROR; 
  }

  show_available_facts_in_data_base();

  if (selection(&selected_fact, "Enter the fact to be obtained") != NO_ERROR)
  {
    printf("Error.\n");
    return ERROR;
  }

  printf("\n\n%s\n",planet[selected_planet-UNIT].name);
  printf("================================================================\n");
  switch(selected_fact-UNIT){
    case mass:
      printf("Mass (10^24kg): %f\n",planet[selected_planet-UNIT].mass);
      break;
    case diameter:
      printf("Diameter (km): %ld\n",planet[selected_planet-UNIT].diameter);      
      break;
    case density:
      printf("Density (kg/m^3): %ld\n",planet[selected_planet-UNIT].density);
      break;      
    case gravity:
      printf("Gravity (m/s^2):%f\n",planet[selected_planet-UNIT].gravity);
      break;
    case escape_velocity:
      printf("Escape velocity (Km/s):%f\n",planet[selected_planet-UNIT].escape_velocity);
      break;
    case rotation_period:
        printf("Rotation period (hours):%f\n",planet[selected_planet-UNIT].rotation_period);
        break;
    case lenght_of_a_day:
        printf("Lenght of a day (hours):%f\n",planet[selected_planet-UNIT].lenght_of_a_day);
        break;
    case distance_from_the_sun:
        printf("Distance from the sun (10^6 km):%Lf\n",planet[selected_planet-UNIT].distance_from_the_sun);
        break;    
    case orbital_period:
        printf("Orbital period (terrestial days):%Lf\n",planet[selected_planet-UNIT].orbital_period);
        break;
    case orbital_velocity:
        printf("Orbital velocity (km/s):%f\n",planet[selected_planet-UNIT].orbital_velocity);
        break;
    case mean_temperature:
        printf("Mean temperature (C):%d\n",planet[selected_planet-UNIT].mean_temperature);
        break;
    case pressure:
        printf("Surface pressure (atm):%s\n",planet[selected_planet-UNIT].pressure);
        break;
    case moons:
        printf("Amount of known satelites:%u\n",planet[selected_planet-UNIT].moons);
        break;
    case ring_system:
        printf("Does the planet have a ring system?:%s\n",planet[selected_planet-UNIT].ring_system);
        break;      
    case magnetic_field:
        printf("Does the planet have a global magnetic field?:%s\n",planet[selected_planet-UNIT].magnetic_field);
        break;  
    default:
        printf("Unknown option.\n");
  }
  printf("================================================================\n");
  return NO_ERROR;
}

/*
 * Compare function to leave  the list as it was for default right after showing all the data 
 * availablre in the data base arranged in a certain order for each planet or celestial object.
 */

static int distance_from_the_sun_from_nearest_to_farthest(const void *a, const void *b)
{
    return ((planet_t *)a)->distance_from_the_sun > ((planet_t *)b)->distance_from_the_sun;
}

int show_all_data_for_all_planet(planet_t *planet, unsigned int num)
{
  sort_by(planet, num);
    /*sort_by(list, sort, num_est);*/
  for (int i = 1; i < num+UNIT; ++i)
  {
    print_data(planet,i);
  }
  qsort((void *)planet, num, sizeof(planet_t),distance_from_the_sun_from_nearest_to_farthest);
  return NO_ERROR;   
}

int show_specific_fact_for_all_planets(planet_t *planet,unsigned int num)
{

  enum specific_fact selected_fact = 0;

  show_available_facts_in_data_base();

  if (selection(&selected_fact, "Enter the fact to be obtained") != NO_ERROR)
  {
    printf("Error.\n");
    return ERROR;
  }
/*fin de archivo*/
  for (int i = 0; i < num; ++i)
  {
    printf("\n\n%s\n",planet[i].name);
    printf("================================================================\n");
    switch(selected_fact-UNIT){
      case mass:
        printf("Mass (10^24kg): %f\n",planet[i].mass);
        break;
      case diameter:
        printf("Diameter (km): %ld\n",planet[i].diameter);      
        break;
      case density:
        printf("Density (kg/m^3): %ld\n",planet[i].density);
        break;      
      case gravity:
        printf("Gravity (m/s^2):%f\n",planet[i].gravity);
        break;
      case escape_velocity:
        printf("Escape velocity (Km/s):%f\n",planet[i].escape_velocity);
        break;
      case rotation_period:
        printf("Rotation period (hours):%f\n",planet[i].rotation_period);
        break;
      case lenght_of_a_day:
        printf("Lenght of a day (hours):%f\n",planet[i].lenght_of_a_day);
        break;
      case distance_from_the_sun:
        printf("Distance from the sun (10^6 km):%Lf\n",planet[i].distance_from_the_sun);
        break;    
      case orbital_period:
        printf("Orbital period (terrestial days):%Lf\n",planet[i].orbital_period);
        break;
      case orbital_velocity:
        printf("Orbital velocity (km/s):%f\n",planet[i].orbital_velocity);
        break;
      case mean_temperature:
        printf("Mean temperature (C):%d\n",planet[i].mean_temperature);
        break;
      case pressure:
        printf("Surface pressure (atm):%s\n",planet[i].pressure);
        break;
      case moons:
        printf("Amount of known satelites:%u\n",planet[i].moons);
        break;
      case ring_system:
        printf("Does the planet have a ring system?:%s\n",planet[i].ring_system);
        break;      
      case magnetic_field:
        printf("Does the planet have a global magnetic field?:%s\n",planet[i].magnetic_field);
        break;  
      default:
        printf("Unknown option.\n"); 
    }
    printf("================================================================\n");
  }
  return NO_ERROR;
}