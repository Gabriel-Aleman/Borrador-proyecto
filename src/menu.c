#include <stdio.h>

#include "defines.h"
#include "menu.h"

/*
 * Local definition for the menu. It is defined here locally because it is not
 * used outside of this file.
 */
typedef struct menu_s
{
    enum oper_e option; /* User option */
    const char *text; /* Text to be printed on the screen for the user */
} menu_t;

/*
 * Global variable to declare an array of menu options. These are the options to
 * be used on the program menu.
 */
menu_t options[] = {
    {.option = oper_display_all_data_for_a_single_planet, .text = "Display all the information available in the data base for a planet or any other celestial objects."},
    {.option = oper_display_specific_fact_for_a_single_planet, .text = "Display a fact available in the data  base for a planet or any other celestial objects."},
    {.option = oper_display_solar_system_data, .text ="Display all the information available in the data base for all planets and other celestial objects."},
    {.option = oper_display_specific_fact_for_all_planets, .text = "Display a fact available in the data base of choice for all planets and other celestial objects."},
    {.option = oper_comparer, .text = "Obtain the ratio of a certain magnitude between two planets"},
    {.option = oper_exit, .text = "Exit"}};

void clear_input(void)
{
    /*
     * If scanf or any other function to get data from stdin fails, it is
     * possible that the stdin keeps garbage that won't be cleaned on its on.
     * This code gets all that garbage out of stdin.
     */
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


int welcome_user(void){
    printf("\nWelcome user!\n\n");
    printf("[COPERNICUS]\n\n");

}


int print_menu(void)
{
  printf("\nOption menu:\n");
  printf("---------------------------------------------------------------------------------------\n");
  for (int i = 0; i < oper_last; i++)
  {
      /*
        * Prints the globally defined menu options.
        */
      if (printf("%d. %s\n", options[i].option + UNIT,
                    options[i].text) == NO_ERROR)
      {
          return ERROR;
      }
  }
  printf("---------------------------------------------------------------------------------------\n");

  return NO_ERROR;
}


int selection(unsigned int *option, const char *text)
{
    if (printf("%s:\n", text) == NO_ERROR)
    {
        return ERROR;
    }

    /* Request user input using scanf. The scanf function always returns the
     * number of values that match the format. In this case, since the format
     * has a single integer value, scanf must return 1. If it doesn't, it means
     * that the user is writing something different from an integer.
     */
    if (scanf("%d", option) != UNIT)
    {
        clear_input();
        return ERROR;
    }
    return NO_ERROR;
}