/*
 * Valid menu operations
 */
enum oper_e
{
    oper_display_all_data_for_a_single_planet= 0, /*Display all the information available for a certain planet or any other celestial object contained in the data base*/
    oper_display_specific_fact_for_a_single_planet, /*Display a  specific fact from the the information available for all the planets or celestial objects contained in the data base*/
    oper_display_solar_system_data, /* Display all information for all the planets and celestial objects in the solar system in a given order*/
    oper_display_specific_fact_for_all_planets, /* Display a specific fact for all the planets and celestial objects contained in the data base in a given order*/
    oper_comparer, /* Obtain the factor of a certain magnitude for a planet or celestial object in relation to another*/
    oper_new_element,/*Add a new element to the data base.*/
    oper_exit, /* Operation to exit */
    oper_last /* Delimiter, keep as the last enum value! */
};

/*
 * Function to request user input. Only a single value can be requested at a
 * time. The function does not validate that the input is within valid values.
 * Arguments:
 * option: Pointer to user input, set by the function on successful user input
 *         request.
 * test:   String to display to the user when requesting input.
 * Return:
 * ERROR on user input error.
 */
int selection(unsigned int *option, const char *text);

/*
 * Function to print the menu.
 * Return:
 * ERROR if menu cannot be printed.
 */
int print_menu(void);

/*
 * Function to clear stdin in case of error. Recomented to be used if any
 * scanf function fails.
 */
void clear_input(void);

/*
 * This function simply welcomes the user and introduces the progmam
*/
int welcome_user(void);
