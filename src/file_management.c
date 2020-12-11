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
 *In this".c" file you will find all the functions related to file management 
 *issues.
 */

int insert_planets(planet_t *planet, unsigned int num)
{

    FILE *fp=fopen("planets.csv", "r");

    if (fp == NULL){
        printf("Unable to open file.\n");
        return ERROR;
    }

    char line_buffer[LINE];
    char buffer[MAX_STR_LENGHT];
    int i=0;

    memset(line_buffer,0,sizeof(line_buffer));
    memset(buffer,0,sizeof(buffer));

    while(fgets(line_buffer,LINE,fp)!=NULL && i<num){

        strncpy(planet[i].name,strtok(line_buffer,","),MAX_STR_LENGHT);
        planet[i].mass=atof(strtok(NULL,","));
        planet[i].diameter=atoi(strtok(NULL,","));
        planet[i].density=atoi(strtok(NULL,","));
        planet[i].gravity=atof(strtok(NULL,","));
        planet[i].escape_velocity=atof(strtok(NULL,","));
        planet[i].rotation_period=atof(strtok(NULL,","));
        planet[i].lenght_of_a_day=atof(strtok(NULL,","));
        planet[i].distance_from_the_sun=atof(strtok(NULL,","));     
        planet[i].orbital_period=atof(strtok(NULL,","));
        planet[i].orbital_velocity=atof(strtok(NULL,","));
        planet[i].mean_temperature=atof(strtok(NULL,","));
        strncpy(planet[i].pressure,strtok(NULL,","),MAX_STR_LENGHT);
        planet[i].moons=atoi(strtok(NULL,","));
        strncpy(planet[i].ring_system,strtok(NULL,","),MAX_STR_LENGHT);
        strncpy(planet[i].magnetic_field,strtok(NULL,","),MAX_STR_LENGHT);
        memset(buffer,0,sizeof(buffer));
        i++;
    }   
    fclose(fp);

    return NO_ERROR;
}

int get_lines(void){
  FILE *fp= fopen("planets.csv", "r"); 
  if (fp == NULL) { 
    printf("Unable to open file.\n"); 
    return ERROR; 
  } 
  int count = 1;  
  char c;   
  
  for (c = getc(fp); c != EOF; c = getc(fp)) {
    if (c == '\n'){ 
      count++;
    } 
  }
    /* Return the number of lines*/
  fclose(fp); 
  return count; 
}