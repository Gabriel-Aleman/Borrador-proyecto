#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "defines.h"
#include "menu.h"
#include "planets.h"

int main(void)
{
    /* The cont variable is used to stop the program based on user input. */
    bool cont = true;

    /*
     * Try to open the file where there is all the information needed the proceed,
     *and then exit the program in case that the file was not found.
     */

     FILE *fp=fopen("planets.csv", "r");

    if (fp == NULL){
        printf("Unable to open file.\n");
        return ERROR;
    }

    int lines=get_lines();

    planet_t *planet=NULL;

    /*create the list where all the information will be allocated*/
    alloc_planet_list(&planet, lines);

    /*Insert the data from the file into the array of structures previosly made*/
    insert_planets(planet,lines);

    /*
    *Give the user a welcoming and introduce the program.
    */
    welcome_user();

    while (cont)
    {
        /*
         *The print_menu function displays the user menu in the screen. If the
         * menu cannot be displayed, then the program must exit with an error
         * code.
         */
        if (print_menu() != NO_ERROR)
        {
            printf("Cannot display options\n");
            /*
             * On display or read errors, the program must exit with the
             * Input/output error "EIO". For more information see:
             * https://www.gnu.org/software/libc/manual/html_node/Error-Codes.html
             */
            exit(EIO);
        }
        /*
         * The user_selection variable is used to store the user input. The
         * selection function request the user input and puts it on the
         * variable.
         * On error, the program must continue until the user selects a valid
         * option or exits.
         */
        unsigned int user_selection = 0;
        if (selection(&user_selection, "Select the  option you want to use") != NO_ERROR)
        {
            printf("Invalid option.\n");
            continue;
        }

        /*
         * Based on the user input, the program operations are called. See the
         * documentation in menu.h for more information about the options.
         */
        switch (user_selection - UNIT)
        {
        case oper_display_all_data_for_a_single_planet:
            show_all_data_for_single_a_planet(planet,lines);
            break;
        case oper_display_specific_fact_for_a_single_planet:
            show_specific_fact_for_a_planet(planet,lines);
            break;
        case oper_display_solar_system_data:
            show_all_data_for_all_planet(planet,lines);
            break;
        case oper_display_specific_fact_for_all_planets:
            show_specific_fact_for_all_planets(planet,lines);
            break;
        case oper_comparer:
            /*TODO*/
            break;
        case oper_exit:
            printf("\nExiting program...\n");
            cont = false;
            break;
        default:
            printf("Unknown option.\n");
        }
    }

    return NO_ERROR;
}