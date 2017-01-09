#include "MF52_10K.h"

float mf52_get_temperature_internal(unsigned int adc_bits, short lower_temperature, unsigned int lower_temperature_adc_bits, unsigned int higher_temperature_adc_bits) {
   float bits_in_5_degrees = (float) (lower_temperature_adc_bits - higher_temperature_adc_bits);
   float delta_bits = (float) (lower_temperature_adc_bits - adc_bits);
   float delta_degrees = delta_bits * 5.0f / bits_in_5_degrees;

   return lower_temperature + delta_degrees;
}

float mf52_get_temperature(unsigned int adc_bits) {
   if (adc_bits <= MF52_ADC_BITS_AT_MINUS_30 && adc_bits > MF52_ADC_BITS_AT_MINUS_25) {
      return mf52_get_temperature_internal(adc_bits, -30, MF52_ADC_BITS_AT_MINUS_30, MF52_ADC_BITS_AT_MINUS_25);
   } else if (adc_bits <= MF52_ADC_BITS_AT_MINUS_25 && adc_bits > MF52_ADC_BITS_AT_MINUS_20) {
      return mf52_get_temperature_internal(adc_bits, -25, MF52_ADC_BITS_AT_MINUS_25, MF52_ADC_BITS_AT_MINUS_20);
   } else if (adc_bits <= MF52_ADC_BITS_AT_MINUS_20 && adc_bits > MF52_ADC_BITS_AT_MINUS_15) {
      return mf52_get_temperature_internal(adc_bits, -20, MF52_ADC_BITS_AT_MINUS_20, MF52_ADC_BITS_AT_MINUS_15);
   } else if (adc_bits <= MF52_ADC_BITS_AT_MINUS_15 && adc_bits > MF52_ADC_BITS_AT_MINUS_10) {
      return mf52_get_temperature_internal(adc_bits, -15, MF52_ADC_BITS_AT_MINUS_15, MF52_ADC_BITS_AT_MINUS_10);
   } else if (adc_bits <= MF52_ADC_BITS_AT_MINUS_10 && adc_bits > MF52_ADC_BITS_AT_MINUS_5) {
      return mf52_get_temperature_internal(adc_bits, -10, MF52_ADC_BITS_AT_MINUS_10, MF52_ADC_BITS_AT_MINUS_5);
   } else if (adc_bits <= MF52_ADC_BITS_AT_MINUS_5 && adc_bits > MF52_ADC_BITS_AT_0) {
      return mf52_get_temperature_internal(adc_bits, -5, MF52_ADC_BITS_AT_MINUS_5, MF52_ADC_BITS_AT_0);
   } else if (adc_bits <= MF52_ADC_BITS_AT_0 && adc_bits > MF52_ADC_BITS_AT_5) {
      return mf52_get_temperature_internal(adc_bits, 0, MF52_ADC_BITS_AT_0, MF52_ADC_BITS_AT_5);
   } else if (adc_bits <= MF52_ADC_BITS_AT_5 && adc_bits > MF52_ADC_BITS_AT_10) {
      return mf52_get_temperature_internal(adc_bits, 5, MF52_ADC_BITS_AT_5, MF52_ADC_BITS_AT_10);
   } else if (adc_bits <= MF52_ADC_BITS_AT_10 && adc_bits > MF52_ADC_BITS_AT_15) {
      return mf52_get_temperature_internal(adc_bits, 10, MF52_ADC_BITS_AT_10, MF52_ADC_BITS_AT_15);
   } else if (adc_bits <= MF52_ADC_BITS_AT_15 && adc_bits > MF52_ADC_BITS_AT_20) {
      return mf52_get_temperature_internal(adc_bits, 15, MF52_ADC_BITS_AT_15, MF52_ADC_BITS_AT_20);
   } else if (adc_bits <= MF52_ADC_BITS_AT_20 && adc_bits > MF52_ADC_BITS_AT_25) {
      return mf52_get_temperature_internal(adc_bits, 20, MF52_ADC_BITS_AT_20, MF52_ADC_BITS_AT_25);
   } else if (adc_bits <= MF52_ADC_BITS_AT_25 && adc_bits > MF52_ADC_BITS_AT_30) {
      return mf52_get_temperature_internal(adc_bits, 25, MF52_ADC_BITS_AT_25, MF52_ADC_BITS_AT_30);
   } else if (adc_bits <= MF52_ADC_BITS_AT_30 && adc_bits > MF52_ADC_BITS_AT_35) {
      return mf52_get_temperature_internal(adc_bits, 30, MF52_ADC_BITS_AT_30, MF52_ADC_BITS_AT_35);
   } else if (adc_bits <= MF52_ADC_BITS_AT_35 && adc_bits > MF52_ADC_BITS_AT_40) {
      return mf52_get_temperature_internal(adc_bits, 35, MF52_ADC_BITS_AT_35, MF52_ADC_BITS_AT_40);
   } else if (adc_bits <= MF52_ADC_BITS_AT_40 && adc_bits > MF52_ADC_BITS_AT_45) {
      return mf52_get_temperature_internal(adc_bits, 40, MF52_ADC_BITS_AT_40, MF52_ADC_BITS_AT_45);
   } else if (adc_bits <= MF52_ADC_BITS_AT_45 && adc_bits > MF52_ADC_BITS_AT_50) {
      return mf52_get_temperature_internal(adc_bits, 45, MF52_ADC_BITS_AT_45, MF52_ADC_BITS_AT_50);
   } else if (adc_bits <= MF52_ADC_BITS_AT_50 && adc_bits > MF52_ADC_BITS_AT_55) {
      return mf52_get_temperature_internal(adc_bits, 50, MF52_ADC_BITS_AT_50, MF52_ADC_BITS_AT_55);
   } else if (adc_bits <= MF52_ADC_BITS_AT_55 && adc_bits > MF52_ADC_BITS_AT_60) {
      return mf52_get_temperature_internal(adc_bits, 55, MF52_ADC_BITS_AT_55, MF52_ADC_BITS_AT_60);
   } else if (adc_bits <= MF52_ADC_BITS_AT_60 && adc_bits > MF52_ADC_BITS_AT_65) {
      return mf52_get_temperature_internal(adc_bits, 60, MF52_ADC_BITS_AT_60, MF52_ADC_BITS_AT_65);
   } else if (adc_bits <= MF52_ADC_BITS_AT_65 && adc_bits > MF52_ADC_BITS_AT_70) {
      return mf52_get_temperature_internal(adc_bits, 65, MF52_ADC_BITS_AT_65, MF52_ADC_BITS_AT_70);
   } else if (adc_bits <= MF52_ADC_BITS_AT_70 && adc_bits > MF52_ADC_BITS_AT_75) {
      return mf52_get_temperature_internal(adc_bits, 70, MF52_ADC_BITS_AT_70, MF52_ADC_BITS_AT_75);
   } else if (adc_bits <= MF52_ADC_BITS_AT_75 && adc_bits > MF52_ADC_BITS_AT_80) {
      return mf52_get_temperature_internal(adc_bits, 75, MF52_ADC_BITS_AT_75, MF52_ADC_BITS_AT_80);
   } else if (adc_bits <= MF52_ADC_BITS_AT_80 && adc_bits > MF52_ADC_BITS_AT_85) {
      return mf52_get_temperature_internal(adc_bits, 80, MF52_ADC_BITS_AT_80, MF52_ADC_BITS_AT_85);
   } else if (adc_bits <= MF52_ADC_BITS_AT_85 && adc_bits > MF52_ADC_BITS_AT_90) {
      return mf52_get_temperature_internal(adc_bits, 85, MF52_ADC_BITS_AT_85, MF52_ADC_BITS_AT_90);
   } else if (adc_bits <= MF52_ADC_BITS_AT_90 && adc_bits > MF52_ADC_BITS_AT_95) {
      return mf52_get_temperature_internal(adc_bits, 90, MF52_ADC_BITS_AT_90, MF52_ADC_BITS_AT_95);
   } else if (adc_bits <= MF52_ADC_BITS_AT_95 && adc_bits > MF52_ADC_BITS_AT_100) {
      return mf52_get_temperature_internal(adc_bits, 95, MF52_ADC_BITS_AT_95, MF52_ADC_BITS_AT_100);
   } else if (adc_bits <= MF52_ADC_BITS_AT_100 && adc_bits > MF52_ADC_BITS_AT_105) {
      return mf52_get_temperature_internal(adc_bits, 100, MF52_ADC_BITS_AT_100, MF52_ADC_BITS_AT_105);
   } else if (adc_bits <= MF52_ADC_BITS_AT_105 && adc_bits > MF52_ADC_BITS_AT_110) {
      return mf52_get_temperature_internal(adc_bits, 105, MF52_ADC_BITS_AT_105, MF52_ADC_BITS_AT_110);
   } else return 0.0;
}
