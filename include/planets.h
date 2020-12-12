/*
 * MAX_STR_LENGHT: Maximum size allowed for a string.
 * LINE: Maximum size allowed for a line.
 * AVAILABLE_INFORMATION: All the information that should be available for a planet 
 * or celestial object contained in the data base,
 * AVAILABLE_SORT_CRITERIA: All the criteria by which the elements of data base can be
 * arranged.
 * AVAILABLE_COMPARATION_CRITERIA: All the criteria by which the elements of the data
 * base can be compared. 
 */
#define MAX_STR_LENGHT 100
#define LINE 1500
#define AVAILABLE_INFORMATION 16
#define AVAILABLE_SORT_CRITERIA 13
#define AVAILABLE_COMPARATION_CRITERIA 10

/*
 * Structure to store planets information.
 */

typedef struct planet_s{
	char name[MAX_STR_LENGHT];
	float mass;
	long int diameter;
	long int density;
	float gravity;
	float escape_velocity;
	float rotation_period;
	float lenght_of_a_day;
	long double distance_from_the_sun;
	long double orbital_period;
	float orbital_velocity;
	int mean_temperature;
	char pressure[MAX_STR_LENGHT];
	unsigned int moons;
	char ring_system[MAX_STR_LENGHT];
	char magnetic_field[MAX_STR_LENGHT];
}planet_t;

/**************************************************************************/
/*DYNAMIC MEMORY ISSUES*/

/*
 * Allocate memory for the required number of planets or celestial objects
 * based on the contend of the base.
 * Argument:
 * planet: Double pointer to return the pointer where the planet list is
 *        allocated.
 * num: Number of elements to be allocated.
 * Return:
 * ERROR if the memory cannot be allocated.
 * NO_ERROR if the memory was succesfully  allocated.
 */
int alloc_planet_list(planet_t **planet, unsigned int num);

/*
 * Reallocate memory for the required number of planets or celestial objects.
 * Argument:
 * planet: Double pointer to return the pointer where the planet list is
 *        allocated.
 * num:   Number of elements to be reallocated.
 * Return:
 * ERROR if the memory cannot be reallocated.
 * NO_ERROR if the memory was succesfully  reallocated.
 */
int realloc_planet_list(planet_t **planet, unsigned int num);


/**************************************************************************/

/*FILE MANAGEMENT RELATED ISSUES*/

/*
 * Add a planet or celestial object into the array of structures
 * based on the content of the data base.
 * Argument:
 * planet: Pointer to where the list's memory is allocated.
 * num: Number of elements in the array of structures.
 * Return:
 * ERROR if the data base was not found.
 * NO_ERROR if the data base could be found.
 */
int insert_planets(planet_t *planet, unsigned int num);

/*
 * This function gets the number of lines in the data base.
 * Return:
 * ERROR if the data base was not found.
 * count if the data base could be found, and this parameter corresponds to
 * the number of lines in the file.
 */
int get_lines(void);


/*
 * Add a planet or celestial object into the array of structures
 * if requested by the user.
 * Argument:
 * planet: Pointer to where the list's memory is allocated.
 * num: Number of elements in the array of structures.
 * Return:
 * ERROR if the data base was not found.
 * NO_ERROR if the data base could be found and the functions task was
 * succesfully completed.
 */
int add_planet(planet_t *planet, unsigned int num);

/**************************************************************************/

/*DISPLAY DATA FUNCTIONS*/

/*
 * This function prints the criteria by which planets or celestial objects 
 * can be arranged. 
 */
void show_available_sort_criteria(void);

/*
 * This function prints the information available in the data base for each
 * planet or celestial object.
 */
void show_available_facts_in_data_base(void);

/*
 * This function prints the criteria by which all planets or celestial
 * objects can be compared.
 */
void show_comparable_facts_in_data_base(void);

/*
 * Sort planets or celestial objects according to provided value.
 * Argument:
 * planet: Pointer to where the list's memory is allocated.
 * num: Number of elements in the array of structures.
 * Return:
 * ERROR if there was a mistake while executing the function.
 * NO_ERROR the function's task could be completed.
 */
int sort_by(planet_t *planet,  unsigned int num);

/*
 * This function sole purpose is to print all the information for a planet
 * or celestial object so that it can be used later in other functions.
 * Argument:
 * planet: Pointer to where the list's memory is allocated.
 * num: Number of elements in the array of structures.
 */
void print_data(planet_t *planet,int selected_planet);


/*
 * This function simply prints the name for every single planet or celestial
 * object contained in the data base.
 * Argument:
 * planet: Pointer to where the list's memory is allocated.
 * num: Number of elements in the array of structures.
 * Return:
 * ERROR if there was a mistake while executing the function.
 * NO_ERROR the function's task could be completed.
 */
void show_planets_in_data_base(planet_t *planet,unsigned int num);

/*
 * This function prints all the data for the planet or celestial object
 * selected by the user.
 * Argument:
 * planet: Pointer to where the list's memory is allocated.
 * num: Number of elements in the array of structures.
 * Return:
 * ERROR if there was a mistake while executing the function.
 * NO_ERROR the function's task could be completed.
 */
int show_all_data_for_single_a_planet(planet_t *planet,unsigned int num);

/*
 * This function prints only the fact specified by the user for the planet 
 * or celestial object selected by the user.
 * Argument:
 * planet: Pointer to where the list's memory is allocated.
 * num: Number of elements in the array of structures.
 * Return:
 * ERROR if there was a mistake while executing the function.
 * NO_ERROR the function's task could be completed.
 */
int show_specific_fact_for_a_planet(planet_t *planet,unsigned int num);

/*
 * This function prints all the data for all the planets  or celestial 
 * objects contained in the data base.
 * Argument:
 * planet: Pointer to where the list's memory is allocated.
 * num: Number of elements in the array of structures.
 * Return:
 * ERROR if there was a mistake while executing the function.
 * NO_ERROR the function's task could be completed.
 */
int show_all_data_for_all_planet(planet_t *planet, unsigned int num);

/*
 * This function prints only the fact specified by the user for all the
 * planets or celestial objects contained in the data base.
 * Argument:
 * planet: Pointer to where the list's memory is allocated.
 * num: Number of elements in the array of structures.
 * Return:
 * ERROR if there was a mistake while executing the function.
 * NO_ERROR the function's task could be completed.
 */
int show_specific_fact_for_all_planets(planet_t *planet,unsigned int num);

/*
 * This function prints the ratio between a certain factor for a planet
 * or celestial object in relation to another.
 * Argument:
 * planet: Pointer to where the list's memory is allocated.
 * num: Number of elements in the array of structures.
 * Return:
 * ERROR if there was a mistake while executing the function.
 * NO_ERROR the function's task could be completed.
 */
int compare_planets(planet_t *planet,unsigned int num);




