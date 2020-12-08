#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "defines.h"
#include "menu.h"


int main(void)
{
    /* The cont variable is used to stop the program based on user input. */
    bool cont = true;

    /*
     * The list variable is used to store the pointer to the memory allocated
     * for the students list.
     */
   /* planets *list = NULL;*/

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
        switch (user_selection - 1)
        {
        case oper_display_planet_data:
            /*TODO*/
            break;
        case oper_display_solar_system_data:
            /*TODO*/
            break;
        case oper_comparer:
            /*TODO*/
            break;
        case oper_display_satelites:
            /*TODO*/
            break;
        case oper_add_satelite:
            /*TODO*/
            break;
        case oper_exit:
            cont = false;
            break;
        default:
            printf("Unknown option.\n");
        }
    }

    return 0;
}