#include "utils.h"

char *malloc_addresses_g[MALLOC_ADDRESSES_SIZE];
unsigned int malloc_size_to_be_allocated_g;
unsigned int malloc_invoked_function_address_g;

void set_flag(unsigned int *flags, unsigned int flag_value) {
   *flags |= flag_value;
}

void reset_flag(unsigned int *flags, unsigned int flag_value) {
   *flags &= ~(*flags & flag_value);
}

unsigned char read_flag(unsigned int *flags, unsigned int flag_value) {
   return (*flags & flag_value) > 0 ? 1 : 0;
}

unsigned char contains_string(char being_compared_string[], char string_to_be_contained[]) {
   unsigned char found = 0;

   if (*being_compared_string == '\0' || *string_to_be_contained == '\0') {
      return found;
   }

   for (; *being_compared_string != '\0'; being_compared_string++) {
      unsigned char all_chars_are_equal = 1;

      for (char *char_address = string_to_be_contained; *char_address != '\0';
            char_address++, being_compared_string++) {
         if (*being_compared_string == '\0') {
            return found;
         }

         all_chars_are_equal = *being_compared_string == *char_address ? 1 : 0;

         if (!all_chars_are_equal) {
            break;
         }
      }

      if (all_chars_are_equal) {
         found = 1;
         break;
      }
   }
   return found;
}

/**
 * Do not forget to call free() function on returned pointer when it's no longer needed
 *
 * *parameters - array of pointers to strings. The last parameter has to be NULL
 */
void *set_string_parameters(char string[], char *parameters[]) {
   unsigned char open_brace_found = 0;
   unsigned char parameters_amount = 0;
   unsigned short result_string_length = 0;

   for (; parameters[parameters_amount] != NULL; parameters_amount++) {
   }

   // Calculate the length without symbols to be replaced ('<x>')
   for (char *string_pointer = string; *string_pointer != '\0'; string_pointer++) {
      if (*string_pointer == '<') {
         if (open_brace_found) {
            return NULL;
         }
         open_brace_found = 1;
         continue;
      }
      if (*string_pointer == '>') {
         if (!open_brace_found) {
            return NULL;
         }
         open_brace_found = 0;
         continue;
      }
      if (open_brace_found) {
         continue;
      }

      result_string_length++;
   }

   if (open_brace_found) {
      return NULL;
   }

   for (unsigned char i = 0; parameters[i] != NULL; i++) {
      result_string_length += get_string_length(parameters[i]);
   }
   // 1 is for the last \0 character
   result_string_length++;

   char *allocated_result = malloc(result_string_length); // (string_length + 1) * sizeof(char)

   if (allocated_result == NULL) {
      return NULL;
   }

   unsigned short result_string_index = 0, input_string_index = 0;
   for (; result_string_index < result_string_length - 1; result_string_index++) {
      char input_string_char = string[input_string_index];

      if (input_string_char == '<') {
         input_string_index++;
         input_string_char = string[input_string_index];

         if (input_string_char < '1' || input_string_char > '9') {
            return NULL;
         }

         unsigned short parameter_numeric_value = input_string_char - '0';
         if (parameter_numeric_value > parameters_amount) {
            return NULL;
         }

         input_string_index++;
         input_string_char = string[input_string_index];

         if (input_string_char >= '0' && input_string_char <= '9') {
            parameter_numeric_value = parameter_numeric_value * 10 + input_string_char - '0';
            input_string_index++;
         }
         input_string_index++;

         // Parameters are starting with 1
         char *parameter = parameters[parameter_numeric_value - 1];

         for (; *parameter != '\0'; parameter++, result_string_index++) {
            *(allocated_result + result_string_index) = *parameter;
         }
         result_string_index--;
      } else {
         *(allocated_result + result_string_index) = string[input_string_index];
         input_string_index++;
      }
   }
   *(allocated_result + result_string_length - 1) = '\0';
   return allocated_result;
}

unsigned short get_string_length(char string[]) {
   unsigned short length = 0;

   for (char *string_pointer = string; *string_pointer != '\0'; string_pointer++, length++) {
   }
   return length;
}

unsigned char is_string_starts_with(char long_string[], char short_string[]) {
   unsigned char starts_with = 1;

   for (unsigned short i = 0; short_string[i] != '\0'; i++) {
      if (long_string[i] == '\0' || long_string[i] != short_string[i]) {
         starts_with = 0;
         break;
      }
   }
   return starts_with;
}

/**
 * Do not forget to call free() function on returned pointer when it's no longer needed
 *
 * precise amount of digits in fractional part
 */
char *float_to_string(float number, unsigned char precise) {
   float integer_part;
   float fractional_part;
   fractional_part = modff(number, &integer_part);
   char *integer_part_string = num_to_string((unsigned int) integer_part);

   fractional_part += 1; // 1 is to be removed later
   fractional_part *= powi(10, precise);
   if (modff(fractional_part, &integer_part) >= 0.49f) { // &integer_part is not functionally used here
      fractional_part++;
   }
   unsigned int integer_of_fractional_part = (unsigned int) (fractional_part);
   char *fractional_part_string = num_to_string(integer_of_fractional_part);

   unsigned char integer_part_string_length = get_string_length(integer_part_string);
   unsigned char fractional_part_string_length = get_string_length(fractional_part_string) - 1; // first 1 is to be removed later
   char *result = malloc(integer_part_string_length + fractional_part_string_length + 2); // + '.' + '\0'

   unsigned char result_location = 0;
   for (unsigned char i = 0; i < integer_part_string_length; i++, result_location++) {
      *(result + result_location) = *(integer_part_string + i);
   }
   free(integer_part_string);

   *(result + result_location) = '.';
   result_location++;

   for (unsigned char i = 0; i < fractional_part_string_length; i++, result_location++) {
      *(result + result_location) = *(fractional_part_string + i + 1); // first 1 should not be read
   }
   free(fractional_part_string);
   *(result + result_location) = '\0';
   return result;
}

unsigned int powi(unsigned int x, unsigned char y) {
   unsigned int result = 1;

   for (unsigned char i = 0; i < y; i++) {
      result *= x;
   }
   return result;
}

/**
 * Do not forget to call free() function on returned pointer when it's no longer needed
 */
char *num_to_string(unsigned int number) {
   char *result_string_pointer = NULL;

   if (number == 0) {
      result_string_pointer = malloc(2);
      result_string_pointer[0] = '0';
      result_string_pointer[1] = '\0';
      return result_string_pointer;
   }

   unsigned char string_size = 1;
   unsigned int divider = 1;
   unsigned int divider_tmp = 10;

   for (unsigned char i = 0; divider_tmp <= number; i++) {
      divider = divider_tmp;
      divider_tmp *= 10;
      string_size++;
   }

   unsigned int remaining = number;
   unsigned char string_length = 0;

   while (string_size > 0) {
      unsigned char last_digit_was_zero = 0;
      if (remaining < divider) {
         last_digit_was_zero = 1;
      }
      unsigned char result_character = last_digit_was_zero ? 0 : get_first_digit(remaining);
      //unsigned char result_character = (unsigned char) (remaining / divider);

      if (result_string_pointer == NULL && result_character) {
         result_string_pointer = malloc(string_size + 1);
         string_length = string_size;
      }
      if (result_string_pointer != NULL) {
         unsigned char index = string_length - string_size;
         *(result_string_pointer + index) = result_character + '0';
      }

      if (!last_digit_was_zero) {
         remaining -= result_character * divider;
      }
      divider = divide_by_10(divider);
      //divider /= 10;
      string_size--;
   }
   result_string_pointer[string_length] = '\0';
   return result_string_pointer;
}

/**
 * Only 10, 100, 1000, e.t.c can be divided by 10
 */
unsigned int divide_by_10(unsigned int dividend) {
   if (dividend < 10) {
      return 0;
   }

   unsigned int subtrahend = 0;
   unsigned int subtrahend_tmp = 9;

   while (subtrahend_tmp < dividend) {
      subtrahend = subtrahend_tmp;
      subtrahend_tmp *= 10;
   }
   return dividend - subtrahend;
}

unsigned char get_first_digit(unsigned int long_digit) {
   if (long_digit < 10) {
      return (unsigned char) long_digit;
   }

   // Find the most subtrahend
   unsigned int subtrahend = 0;
   unsigned int subtrahend_tmp = 10;

   while (subtrahend_tmp <= long_digit) {
      subtrahend = subtrahend_tmp;
      subtrahend_tmp *= 10;
   }

   unsigned char result = 1;
   unsigned int remaining_result = long_digit - subtrahend;

   while (remaining_result >= subtrahend) {
      result++;
      remaining_result -= subtrahend;
   }
   return result;
}

/**
 * Do not forget to call free() function on returned pointer when it's no longer needed
 */
void *array_to_string(char array[], unsigned char array_length) {
   char *result = malloc(array_length + 1);

   for (unsigned char i = 0; i < array_length; i++) {
      result[i] = array[i];
   }
   result[array_length] = '\0';
   return result;
}

char *get_gson_element_value(char *json_string, char *json_element_to_find) {
   char *json_element_to_find_in_string = strstr(json_string, json_element_to_find);
   unsigned int json_element_to_find_length = (unsigned int) strnlen(json_element_to_find, 50);

   if (json_element_to_find_in_string != NULL) {
      json_element_to_find_in_string += json_element_to_find_length;
      json_element_to_find_in_string++;
   } else {
      return NULL;
   }

   if (*json_element_to_find_in_string != ':') {
      return NULL;
   }

   json_element_to_find_in_string++;
   if (*json_element_to_find_in_string == '\"') {
      json_element_to_find_in_string++;
   }

   char *json_element_to_find_value = json_element_to_find_in_string;
   unsigned int returning_value_length = 0;

   while (!(*json_element_to_find_value == '\0' || *json_element_to_find_value == '\"' || *json_element_to_find_value == '}')) {
      returning_value_length++;
      json_element_to_find_value++;
   }
   json_element_to_find_value = json_element_to_find_value - returning_value_length;

   char *returning_value = malloc(returning_value_length + 1);

   for (unsigned int i = 0; i < returning_value_length; i++) {
      *(returning_value + i) = *(json_element_to_find_value + i);
   }
   *(returning_value + returning_value_length) = '\0';
   return returning_value;
}

char *debug_malloc(unsigned int size, unsigned int invoked_function_address) {
   malloc_size_to_be_allocated_g = size;
   malloc_invoked_function_address_g = invoked_function_address;
   char *allocated_memory_location = malloc(size);
   add_debug_malloc_address(allocated_memory_location);
   return allocated_memory_location;
}

void debug_free(char *memory_location_to_free) {
   free(memory_location_to_free);
   remove_debug_malloc_address(memory_location_to_free);
}

void add_debug_malloc_address(char *allocated_memory_location) {
   for (unsigned short i = 0; i < MALLOC_ADDRESSES_SIZE; i++) {
      char *current_location = malloc_addresses_g[i];

      if (current_location == NULL) {
         malloc_addresses_g[i] = allocated_memory_location;
         break;
      }
   }
}

void remove_debug_malloc_address(char *freed_memory_location) {
   for (unsigned short i = 0; i < MALLOC_ADDRESSES_SIZE; i++) {
      char *current_location = malloc_addresses_g[i];

      if (current_location == freed_memory_location) {
         malloc_addresses_g[i] = NULL;
         break;
      }
   }
}
