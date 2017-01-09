float mf52_get_temperature(unsigned int adc_bits);

#define MF52_10K_POWER_SUPPLY 3.3f
#define MF52_R1_DIVIDER_RESISTOR 10000
#define MF52_ADC_RESOLUTION 4096

#define MF52_RESISTOR_VALUE_AT_MINUS_30 181700
#define MF52_RESISTOR_VALUE_AT_MINUS_25 133300
#define MF52_RESISTOR_VALUE_AT_MINUS_20 98880
#define MF52_RESISTOR_VALUE_AT_MINUS_15 74100
#define MF52_RESISTOR_VALUE_AT_MINUS_10 56060
#define MF52_RESISTOR_VALUE_AT_MINUS_5 42800
#define MF52_RESISTOR_VALUE_AT_0 98960
#define MF52_RESISTOR_VALUE_AT_5 25580
#define MF52_RESISTOR_VALUE_AT_10 20000
#define MF52_RESISTOR_VALUE_AT_15 15760
#define MF52_RESISTOR_VALUE_AT_20 12510
#define MF52_RESISTOR_VALUE_AT_25 10000
#define MF52_RESISTOR_VALUE_AT_30 8048
#define MF52_RESISTOR_VALUE_AT_35 6518
#define MF52_RESISTOR_VALUE_AT_40 5312
#define MF52_RESISTOR_VALUE_AT_45 4354
#define MF52_RESISTOR_VALUE_AT_50 3588
#define MF52_RESISTOR_VALUE_AT_55 2974
#define MF52_RESISTOR_VALUE_AT_60 2476
#define MF52_RESISTOR_VALUE_AT_65 2072
#define MF52_RESISTOR_VALUE_AT_70 1743
#define MF52_RESISTOR_VALUE_AT_75 1473
#define MF52_RESISTOR_VALUE_AT_80 1250
#define MF52_RESISTOR_VALUE_AT_85 1065
#define MF52_RESISTOR_VALUE_AT_90 911
#define MF52_RESISTOR_VALUE_AT_95 782.4f
#define MF52_RESISTOR_VALUE_AT_100 674.4f
#define MF52_RESISTOR_VALUE_AT_105 583.6f
#define MF52_RESISTOR_VALUE_AT_110 506.6f

#define MF52_GET_BITS(resistor_value) ((unsigned int)((MF52_10K_POWER_SUPPLY / (MF52_R1_DIVIDER_RESISTOR + resistor_value)) * resistor_value * MF52_ADC_RESOLUTION / MF52_10K_POWER_SUPPLY))

#define MF52_ADC_BITS_AT_MINUS_30 MF52_GET_BITS(MF52_RESISTOR_VALUE_AT_MINUS_30)
#define MF52_ADC_BITS_AT_MINUS_25 MF52_GET_BITS(MF52_RESISTOR_VALUE_AT_MINUS_25)
#define MF52_ADC_BITS_AT_MINUS_20 MF52_GET_BITS(MF52_RESISTOR_VALUE_AT_MINUS_20)
#define MF52_ADC_BITS_AT_MINUS_15 MF52_GET_BITS(MF52_RESISTOR_VALUE_AT_MINUS_15)
#define MF52_ADC_BITS_AT_MINUS_10 MF52_GET_BITS(MF52_RESISTOR_VALUE_AT_MINUS_10)
#define MF52_ADC_BITS_AT_MINUS_5 MF52_GET_BITS(MF52_RESISTOR_VALUE_AT_MINUS_5)
#define MF52_ADC_BITS_AT_0 MF52_GET_BITS(MF52_RESISTOR_VALUE_AT_0)
#define MF52_ADC_BITS_AT_5 MF52_GET_BITS(MF52_RESISTOR_VALUE_AT_5)
#define MF52_ADC_BITS_AT_10 MF52_GET_BITS(MF52_RESISTOR_VALUE_AT_10)
#define MF52_ADC_BITS_AT_15 MF52_GET_BITS(MF52_RESISTOR_VALUE_AT_15)
#define MF52_ADC_BITS_AT_20 MF52_GET_BITS(MF52_RESISTOR_VALUE_AT_20)
#define MF52_ADC_BITS_AT_25 MF52_GET_BITS(MF52_RESISTOR_VALUE_AT_25)
#define MF52_ADC_BITS_AT_30 MF52_GET_BITS(MF52_RESISTOR_VALUE_AT_30)
#define MF52_ADC_BITS_AT_35 MF52_GET_BITS(MF52_RESISTOR_VALUE_AT_35)
#define MF52_ADC_BITS_AT_40 MF52_GET_BITS(MF52_RESISTOR_VALUE_AT_40)
#define MF52_ADC_BITS_AT_45 MF52_GET_BITS(MF52_RESISTOR_VALUE_AT_45)
#define MF52_ADC_BITS_AT_50 MF52_GET_BITS(MF52_RESISTOR_VALUE_AT_50)
#define MF52_ADC_BITS_AT_55 MF52_GET_BITS(MF52_RESISTOR_VALUE_AT_55)
#define MF52_ADC_BITS_AT_60 MF52_GET_BITS(MF52_RESISTOR_VALUE_AT_60)
#define MF52_ADC_BITS_AT_65 MF52_GET_BITS(MF52_RESISTOR_VALUE_AT_65)
#define MF52_ADC_BITS_AT_70 MF52_GET_BITS(MF52_RESISTOR_VALUE_AT_70)
#define MF52_ADC_BITS_AT_75 MF52_GET_BITS(MF52_RESISTOR_VALUE_AT_75)
#define MF52_ADC_BITS_AT_80 MF52_GET_BITS(MF52_RESISTOR_VALUE_AT_80)
#define MF52_ADC_BITS_AT_85 MF52_GET_BITS(MF52_RESISTOR_VALUE_AT_85)
#define MF52_ADC_BITS_AT_90 MF52_GET_BITS(MF52_RESISTOR_VALUE_AT_90)
#define MF52_ADC_BITS_AT_95 MF52_GET_BITS(MF52_RESISTOR_VALUE_AT_95)
#define MF52_ADC_BITS_AT_100 MF52_GET_BITS(MF52_RESISTOR_VALUE_AT_100)
#define MF52_ADC_BITS_AT_105 MF52_GET_BITS(MF52_RESISTOR_VALUE_AT_105)
#define MF52_ADC_BITS_AT_110 MF52_GET_BITS(MF52_RESISTOR_VALUE_AT_110)