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

int add_planet(planet_t *planet, unsigned int num){
  
  FILE *fp= fopen("planets.csv", "a"); 

  if (fp == NULL) { 
    printf("Unable to open file.\n"); 
    return ERROR; 
  } 

  int ring_system,magnetic_field,yes=1,no=2;

  /*Adding new element's data into the array of structures*/
  printf("\n");
  printf("Enter the new element's name (make sure to write it in capital letters): ");
  scanf("%s",planet[num-UNIT].name);
  printf("Enter the new element's mass (10^24kg): ");
  scanf("%f",&planet[num-UNIT].mass);
  printf("Enter the new element's diameter (km): ");
  scanf("%ld",&planet[num-UNIT].diameter);
  printf("Enter the new element's density (kg/m^3): ");
  scanf("%ld",&planet[num-UNIT].density);
  printf("Enter the new element's gravity (m/s^2): ");
  scanf("%f",&planet[num-UNIT].gravity);
  printf("Enter the new element's escape escape velocity (Km/s): ");
  scanf("%f",&planet[num-UNIT].escape_velocity);
  printf("Enter the new element's rotation period (hours): ");
  scanf("%f",&planet[num-UNIT].rotation_period);
  printf("Enter the new element's lenght of a day (hours): ");
  scanf("%f",&planet[num-UNIT].lenght_of_a_day);
  printf("Enter the new element's distance from the sun (10^6 km): ");
  scanf("%Lf",&planet[num-UNIT].distance_from_the_sun);
  printf("Enter the new element's orbital period (terrestial days): ");
  scanf("%Lf",&planet[num-UNIT].orbital_period);
  printf("Enter the new element's orbital velocity (km/s): ");
  scanf("%f",&planet[num-UNIT].orbital_velocity);
  printf("Enter the new element's mean temperature (C): ");
  scanf("%d",&planet[num-UNIT].mean_temperature);
  printf("Enter the new element's surface pressure (atm):");
  scanf("%s",planet[num-UNIT].pressure);
  printf("Enter the new element's amount of known satelites: ");
  scanf("%u",&planet[num-UNIT].moons);
  printf("Does the new element have a ring system (1-Yes/2-No): ");
  scanf("%d",&ring_system);
  if (ring_system==yes)
  {
    strcpy(planet[num-UNIT].ring_system, "Yes");
  }
  else if(ring_system==no){
    strcpy(planet[num-UNIT].ring_system, "No");
  }
  else{
    printf("Invalid value \n");
  }
  printf("Does the new element have a global magnetic field(1-Yes/2-No) ");
  scanf("%d",&magnetic_field);
  if (magnetic_field==yes)
  {
    strcpy(planet[num-UNIT].magnetic_field, "Yes");
  }
  else if(magnetic_field==no){
    strcpy(planet[num-UNIT].magnetic_field, "No");
  }
  else{
    printf("Invalid value \n");
  }
   
  /*Adding new element's data into the data base*/
  fputs("\n",fp);
  fputs(planet[num-UNIT].name,fp);
  fputs(",",fp);
  fprintf(fp, "%f", planet[num-UNIT].mass);
  fputs(",",fp);
  fprintf(fp, "%ld",planet[num-UNIT].diameter);
  fputs(",",fp);
  fprintf(fp,"%ld",planet[num-UNIT].density);
  fputs(",",fp);
  fprintf(fp,"%f",planet[num-UNIT].gravity);
  fputs(",",fp);
  fprintf(fp,"%f",planet[num-UNIT].escape_velocity);
  fputs(",",fp);
  fprintf(fp,"%f",planet[num-UNIT].rotation_period);
  fputs(",",fp);
  fprintf(fp,"%f",planet[num-UNIT].lenght_of_a_day);
  fputs(",",fp);
  fprintf(fp,"%Lf",planet[num-UNIT].distance_from_the_sun);
  fputs(",",fp);
  fprintf(fp,"%Lf",planet[num-UNIT].orbital_period);
  fputs(",",fp);
  fprintf(fp,"%f",planet[num-UNIT].orbital_velocity);
  fputs(",",fp);
  fprintf(fp,"%d",planet[num-UNIT].mean_temperature);
  fputs(",",fp);
  fputs(planet[num-UNIT].pressure,fp);
  fputs(",",fp);
  fprintf(fp,"%u",planet[num-UNIT].moons);
  fputs(",",fp);
  fputs(planet[num-UNIT].ring_system,fp);
  fputs(",",fp);
  fputs(planet[num-UNIT].magnetic_field,fp);

  fclose(fp);
  return NO_ERROR;
}