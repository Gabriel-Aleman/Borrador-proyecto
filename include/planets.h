/*
 * MAX_STR_LENGHT: Maximum size allowed for a string.
 * LINE: Maximum size allowed for a line.
 *define AVAILABLE_INFORMATION: all the information that should be available for a planet in the data base
 */
#define MAX_STR_LENGHT 1000
#define LINE 1500
#define AVAILABLE_INFORMATION 16
#define AVAILABLE_SORT_CRITERIA 13

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

int show_available_sort_criteria(void);

int sort_by(planet_t *planet,  unsigned int num);

int alloc_planet_list(planet_t **planet, unsigned int num);

int insert_planets(planet_t *planet, unsigned int num);

int get_lines(void);

int print_data(planet_t *planet,int selected_planet);

int show_planets_in_data_base(planet_t *planet,unsigned int num);

int show_available_facts_in_data_base(void);

int show_all_data_for_single_a_planet(planet_t *planet,unsigned int num);

int show_specific_fact_for_a_planet(planet_t *planet,unsigned int num);

int show_all_data_for_all_planet(planet_t *planet, unsigned int num);

int show_specific_fact_for_all_planets(planet_t *planet,unsigned int num);