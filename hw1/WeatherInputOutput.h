#ifndef WEATHERINPUTOUTPUT_H_
#define WEATHERINPUTOUTPUT_H_
#include "Weather.h"

void scanWeek(weatherInfo *weekWeather);

void printWeek(const weatherInfo weekWeather[], int size);

void printAnalysis(const weatherAnalysis *analysisWeek);
#endif  //  WEATHERINPUTOUTPUT_H_
