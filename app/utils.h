#include "stdlib.h"
#include "arm_math.h"

void set_flag(unsigned int *flags, unsigned int flag_value);
void reset_flag(unsigned int *flags, unsigned int flag_value);
unsigned char read_flag(unsigned int *flags, unsigned int flag_value);
unsigned char contains_string(char being_compared_string[], char string_to_be_contained[]);
void *set_string_parameters(char string[], char *parameters[]);
unsigned short get_string_length(char string[]);
unsigned char is_string_starts_with(char long_string[], char short_string[]);
char *float_to_string(float number, unsigned char precise);
unsigned int powi(unsigned int x, unsigned char y);
char *num_to_string(unsigned int number);
unsigned int divide_by_10(unsigned int dividend);
unsigned char get_first_digit(unsigned int long_digit);
void *array_to_string(char array[], unsigned char array_length);
char *get_gson_element_value(char *json_string, char *json_element_to_find);
