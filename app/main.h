// STM32F030K6T6 or STM32F030F4P6
#if defined STM32F030K6T6
#elif defined STM32F030F4P6
#endif
/**
 * unsigned char  uint8_t
 * unsigned short uint16_t
 * unsigned int   uint32_t
 */

#define CLOCK_SPEED 16000000
#define USART_BAUD_RATE 115200
#define TIMER3_PERIOD_TICKS (unsigned int)(CLOCK_SPEED * 15 / USART_BAUD_RATE)
#define TIMER3_SEC_PER_PERIOD ((float)TIMER3_PERIOD_TICKS / CLOCK_SPEED)
#define TIMER3_MS_PER_PERIOD ((float)TIMER3_PERIOD_TICKS * 1000 / CLOCK_SPEED)
#define TIMER14_PERIOD 24
#define TIMER14_PRESCALER 0xFFFF
#define TIMER14_TACTS_PER_SECOND (CLOCK_SPEED / TIMER14_PERIOD / TIMER14_PRESCALER)

#define USART1_TX_DMA_CHANNEL DMA1_Channel2
#define USART1_TDR_ADDRESS (unsigned int)(&(USART1->TDR))
#define ADC1_DMA_CHANNEL DMA1_Channel1
#define ADC1_DR_ADDRESS (uint32_t)(&(ADC1->DR))
#define TEMPERATURE_SENSOR_ADC_CHANNEL ADC_Channel_3 // See ADC pin
#define HUMIDITY_SENSOR_ADC_CHANNEL ADC_Channel_7 // See ADC pin

#define NETWORK_STATUS_LED_PIN GPIO_Pin_5
#define NETWORK_STATUS_LED_PORT GPIOA
#define SERVER_AVAILABILITI_LED_PIN GPIO_Pin_6
#define SERVER_AVAILABILITI_LED_PORT GPIOA
#define ESP8266_CONTROL_PIN GPIO_Pin_15
#define ESP8266_CONTROL_PORT GPIOA
#define TEMPERATURE_SENSOR_ADC_PIN GPIO_Pin_3
#define TEMPERATURE_SENSOR_ADC_PORT GPIOA
#define HUMIDITY_SENSOR_ADC_PIN GPIO_Pin_7
#define HUMIDITY_SENSOR_ADC_PORT GPIOA

// General flags
#define USART_DATA_RECEIVED_FLAG 1
#define SERVER_IS_AVAILABLE_FLAG 2
#define SUCCESSUFULLY_CONNECTED_TO_NETWORK_FLAG 4
#define SEND_DEBUG_INFO_FLAG 8
#define TURN_FAN_ON_FLAG 16
#define SEND_FAN_INFO 32

#define GET_VISIBLE_NETWORK_LIST_TASK 1
#define DISABLE_ECHO_TASK 2
#define CONNECT_TO_NETWORK_TASK 4
//
#define GET_AP_CONNECTION_STATUS_AND_CONNECT_TASK 16
#define GET_OWN_IP_ADDRESS_TASK 32
#define SET_OWN_IP_ADDRESS_TASK 64
#define CONNECT_TO_SERVER_TASK 128
#define SET_BYTES_TO_SEND_IN_REQUEST_TASK 256
#define GET_REQUEST_SENT_AND_RESPONSE_RECEIVED_TASK 512
#define POST_REQUEST_SENT_TASK 1024
#define GET_CURRENT_DEFAULT_WIFI_MODE_TASK 2048
#define SET_DEFAULT_STATION_WIFI_MODE_TASK 4096
#define CLOSE_CONNECTION_TASK 8192
#define GET_CONNECTION_STATUS_TASK 16384
#define GET_SERVER_AVAILABILITY_REQUEST_TASK 32768
#define GET_SERVER_AVAILABILITY_TASK 65536
#define SEND_FAN_INFO_TASK 131072
#define SEND_FAN_INFO_REQUEST_TASK 262144

#define USART_DATA_RECEIVED_BUFFER_SIZE 1000
#define PIPED_REQUEST_COMMANDS_TO_SEND_SIZE 3
#define PIPED_REQUEST_CIPSTART_COMMAND_INDEX 0
#define PIPED_REQUEST_CIPSEND_COMMAND_INDEX 1
#define PIPED_REQUEST_INDEX 2

#define PIPED_TASKS_TO_SEND_SIZE 30
#define PIPED_TASKS_HISTORY_SIZE 10
#define DEFAULT_ACCESS_POINT_GAIN_SIZE 4

#define TIMER3_10MS (unsigned short)(10 / TIMER3_MS_PER_PERIOD)
#define TIMER3_100MS (unsigned short)(100 / TIMER3_MS_PER_PERIOD)
#define TIMER14_100MS 1
#define TIMER14_200MS 2
#define TIMER14_500MS 5
#define TIMER14_1S 10
#define TIMER14_2S 20
#define TIMER14_3S 30
#define TIMER14_5S 50
#define TIMER14_10S 102
#define TIMER14_30S 305
#define TIMER14_60S 610
#define TIMER14_10MIN 6103

typedef enum {
   EXECUTE_FUNCTION_IMMEDIATELY,
   DO_NOT_EXECUTE_FUNCTION_IMMEDIATELY
} ImmediatelyFunctionExecution;

typedef enum {
   HUMIDITY_SENSOR,
   TEMPERATURE_SENSOR
} ADCSource;

#define RECEIVED_USART_DATA_FOR_DEBUG_INFO_MAX_LENGTH 100

char USART_OK[] __attribute__ ((section(".text.const"))) = "OK";
char USART_ERROR[] __attribute__ ((section(".text.const"))) = "ERROR";
char ESP8226_REQUEST_DISABLE_ECHO[] __attribute__ ((section(".text.const"))) = "ATE0\r\n";
char ESP8226_REQUEST_GET_VISIBLE_NETWORK_LIST[] __attribute__ ((section(".text.const"))) = "AT+CWLAP\r\n";
char ESP8226_RESPONSE_VISIBLE_NETWORK_LIST_PREFIX[] __attribute__ ((section(".text.const"))) = "+CWLAP:";
char ESP8226_REQUEST_GET_AP_CONNECTION_STATUS[] __attribute__ ((section(".text.const"))) = "AT+CWJAP?\r\n";
char ESP8226_RESPONSE_NOT_CONNECTED_STATUS[] __attribute__ ((section(".text.const"))) = "No AP";
char ESP8226_REQUEST_CONNECT_TO_NETWORK_AND_SAVE[] __attribute__ ((section(".text.const"))) = "AT+CWJAP_DEF=\"<1>\",\"<2>\"\r\n";
char ESP8226_RESPONSE_CONNECTED[] __attribute__ ((section(".text.const"))) = "CONNECT";
char ESP8226_REQUEST_CONNECT_TO_SERVER[] __attribute__ ((section(".text.const"))) = "AT+CIPSTART=\"TCP\",\"<1>\",<2>\r\n";
char ESP8226_REQUEST_DISCONNECT_FROM_SERVER[] __attribute__ ((section(".text.const"))) = "AT+CIPCLOSE\r\n";
char ESP8226_REQUEST_START_SENDING[] __attribute__ ((section(".text.const"))) = "AT+CIPSEND=<1>\r\n";
char ESP8226_RESPONSE_START_SENDING_READY[] __attribute__ ((section(".text.const"))) = ">";
char ESP8226_RESPONSE_SUCCSESSFULLY_SENT[] __attribute__ ((section(".text.const"))) = "\r\nSEND OK\r\n";
char ESP8226_RESPONSE_ALREADY_CONNECTED[] __attribute__ ((section(".text.const"))) = "ALREADY CONNECTED";
char ESP8226_RESPONSE_PREFIX[] __attribute__ ((section(".text.const"))) = "+IPD";
char ESP8226_REQUEST_GET_CURRENT_DEFAULT_WIFI_MODE[] __attribute__ ((section(".text.const"))) = "AT+CWMODE_DEF?\r\n";
char ESP8226_RESPONSE_WIFI_MODE_PREFIX[] __attribute__ ((section(".text.const"))) = "+CWMODE_DEF:";
char ESP8226_RESPONSE_WIFI_STATION_MODE[] __attribute__ ((section(".text.const"))) = "1";
char ESP8226_REQUEST_SET_DEFAULT_STATION_WIFI_MODE[] __attribute__ ((section(".text.const"))) = "AT+CWMODE_DEF=1\r\n";
char ESP8226_REQUEST_GET_OWN_IP_ADDRESS[] __attribute__ ((section(".text.const"))) = "AT+CIPSTA_DEF?\r\n";
char ESP8226_RESPONSE_CURRENT_OWN_IP_ADDRESS_PREFIX[] __attribute__ ((section(".text.const"))) = "+CIPSTA_DEF:ip:";
char ESP8226_REQUEST_SET_OWN_IP_ADDRESS[] __attribute__ ((section(".text.const"))) = "AT+CIPSTA_DEF=\"<1>\"\r\n";
char DEBUG_STATUS_JSON[] __attribute__ ((section(".text.const"))) =
      "{\"gain\":\"<1>\",\"debugInfoIncluded\":<2>,\"errors\":\"<3>\",\"usartOverrunErrors\":\"<4>\",\"usartIdleLineDetections\":\"<5>\",\"usartNoiseDetection\":\"<6>\",\"usartFramingErrors\":\"<7>\",\"lastErrorTask\":\"<8>\",\"usartData\":\"<9>\",\"timeStamp\":\"<10>\"}";
char STATUS_JSON[] __attribute__ ((section(".text.const"))) = "{\"gain\":\"<1>\",\"debugInfoIncluded\":<2>,\"timeStamp\":\"<3>\"}";
char ESP8226_RESPONSE_OK_STATUS_CODE[] __attribute__ ((section(".text.const"))) = "\"statusCode\":\"OK\"";
char ESP8226_RESPONSE_HTTP_STATUS_400_BAD_REQUEST[] __attribute__ ((section(".text.const"))) = "HTTP/1.1 400 Bad Request";
char SERVER_STATUS_INCLUDE_DEBUG_INFO[] __attribute__ ((section(".text.const"))) = "\"includeDebugInfo\":true";
char TURN_FAN_ON[] __attribute__ ((section(".text.const"))) = "\"turnOn\":true";
char RESPONSE_CLOSED_BY_TOMCAT[] __attribute__ ((section(".text.const"))) = "\r\n+IPD,5:0\r\n\r\nCLOSED\r\n";
char ESP8226_REQUEST_SEND_STATUS_INFO_AND_GET_SERVER_AVAILABILITY[] __attribute__ ((section(".text.const"))) =
      "POST /server/esp8266/statusInfo HTTP/1.1\r\nContent-Length: <1>\r\nHost: <2>\r\nUser-Agent: ESP8266\r\nContent-Type: application/json\r\nAccept: application/json\r\nConnection: keep-alive\r\n\r\n<3>\r\n";
char ESP8226_REQUEST_SEND_FAN_INFO[] __attribute__ ((section(".text.const"))) =
      "POST /server/esp8266/bathroomFan HTTP/1.1\r\nContent-Length: <1>\r\nHost: <2>\r\nUser-Agent: ESP8266\r\nContent-Type: application/json\r\nAccept: application/json\r\nConnection: keep-alive\r\n\r\n<3>\r\n";
char DEBUG_STATUS_AND_FAN_DATA[] __attribute__ ((section(".text.const"))) =
      "{\"gain\":\"<1>\",\"debugInfoIncluded\":<2>,\"errors\":\"<3>\",\"usartOverrunErrors\":\"<4>\",\"usartIdleLineDetections\":\"<5>\",\"usartNoiseDetection\":\"<6>\",\"usartFramingErrors\":\"<7>\",\"lastErrorTask\":\"<8>\",\"usartData\":\"<9>\",\"timeStamp\":\"<10>\",\"humidity\":\"<11>\",\"temperature\":\"<12>\"}";
char STATUS_AND_FAN_DATA[] __attribute__ ((section(".text.const"))) = "{\"gain\":\"<1>\",\"debugInfoIncluded\":<2>,\"timeStamp\":\"<3>\",\"humidity\":\"<4>\",\"temperature\":\"<5>\"}";

void IWDG_Config();
void Clock_Config();
void Pins_Config();
void TIMER3_Confing();
void TIMER14_Confing();
void ADC_Config();
unsigned char handle_disable_echo_task(unsigned int current_piped_task_to_send, unsigned int *sent_flag);
unsigned char handle_get_connection_status_and_connect_task(unsigned int current_piped_task_to_send, unsigned int *sent_flag);
unsigned char handle_get_connection_status_task(unsigned int current_piped_task_to_send, unsigned int *sent_flag);
unsigned char handle_connect_to_network_task(unsigned int current_piped_task_to_send, unsigned int *sent_flag);
unsigned char handle_connect_to_server_task(unsigned int current_piped_task_to_send, unsigned int *sent_flag);
unsigned char handle_set_bytes_to_send_in_request_task(unsigned int current_piped_task_to_send, unsigned int *sent_flag);
unsigned char handle_get_request_sent_and_response_received_task(unsigned int current_piped_task_to_send, unsigned int *sent_flag);
unsigned char handle_get_current_default_wifi_mode_task(unsigned int current_piped_task_to_send, unsigned int *sent_flag);
unsigned char handle_set_default_station_wifi_mode_task(unsigned int current_piped_task_to_send, unsigned int *sent_flag);
unsigned char handle_get_own_ip_address_task(unsigned int current_piped_task_to_send, unsigned int *sent_flag);
unsigned char handle_set_own_ip_address_task(unsigned int current_piped_task_to_send, unsigned int *sent_flag);
unsigned char handle_close_connection_task(unsigned int current_piped_task_to_send, unsigned int *sent_flag);
unsigned char handle_get_visible_network_list_task(unsigned int current_piped_task_to_send, unsigned int *sent_task);
unsigned char handle_get_server_availability_task(unsigned int current_piped_task_to_send);
unsigned char handle_get_server_availability_request_task(unsigned int current_piped_task_to_send, unsigned int *sent_task);
unsigned char handle_send_fan_info_task(unsigned int current_piped_task_to_send);
unsigned char handle_send_fan_info_request_task(unsigned int current_piped_task_to_send, unsigned int *sent_task);
void reset_device_state();
void DMA_Config();
void USART_Config();
void disable_echo();
void get_network_list();
void connect_to_network();
void get_ap_connection_status();
void schedule_function_resending(void (*function_to_execute)(), unsigned short timeout, ImmediatelyFunctionExecution execute);
void get_server_avalability(unsigned int request_task);
void send_fan_info(unsigned int request_task);
void send_usard_data(char string[]);
float get_humidity();
float get_temperature();
float get_adc_voltage(ADCSource source);
unsigned char is_usart_response_contains_elements(char *data_to_be_contained[], unsigned char elements_count);
unsigned char is_usart_response_contains_element(char string_to_be_contained[]);
void clear_usart_data_received_buffer();
unsigned short get_received_data_length();
unsigned char is_received_data_length_equal(unsigned short length);
unsigned int get_current_piped_task_to_send();
void delete_current_piped_task();
void add_piped_task_to_send_into_tail(unsigned int task);
void add_piped_task_to_send_into_head(unsigned int task);
void delete_piped_task(unsigned int task);
void on_successfully_receive_general_actions(unsigned int sent_task);
void prepare_http_request_without_parameters(char request_template[], unsigned int request_task);
void prepare_http_request(char address[], char port[], char request[], void (*on_response)(), unsigned int request_task);
void resend_usart_get_request_using_global_final_task();
void connect_to_server();
void resend_usart_get_request(unsigned int final_task);
void set_bytes_amount_to_send();
void send_request(unsigned int sent_task_to_set);
void get_current_default_wifi_mode();
void set_default_wifi_mode();
void enable_esp8266();
void disable_esp8266();
unsigned char is_esp8266_enabled(unsigned char include_timer);
void clear_piped_request_commands_to_send();
void delete_all_piped_tasks();
unsigned char is_piped_task_to_send_scheduled(unsigned int task);
unsigned char is_piped_tasks_scheduler_full();
unsigned char is_piped_tasks_scheduler_empty();
void schedule_global_function_resending_and_send_request(unsigned int task, unsigned short timeout);
char *generate_request(char *request_template, char *json_payload_template, char *json_debug_payload_template, char *humidity, char *temperature);
void *add_debug_info(char *template, char *gain, char *debug_info_included, char *response_timestamp, char *humidity, char *temperature);
unsigned int calculate_response_timestamp();
void get_own_ip_address();
void set_own_ip_address();
void close_connection();
void add_error(unsigned int sent_task);
void check_connection_status_and_server_availability();
void check_visible_network_list();
void add_piped_task_into_history(unsigned int task);
unsigned int get_last_piped_task_in_history();
void *get_received_usart_error_data();
void save_default_access_point_gain();
