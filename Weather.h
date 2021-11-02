#ifndef WEATHER_H_
#define WEATHER_H_
#define SIZE 7
#define MAX_TEMPERATURE 75
#define MIN_TEMPERATURE -100

typedef struct {
    double temperature;
    double precipitation;
    double windSpeed;
} weatherInfo;

typedef struct {
    double averageTemperature;
    double minTemperature;
    double maxTemperature;
    double sumPrecipitation;
} weatherAnalysis;

weatherAnalysis analyze(const weatherInfo weekWeather[], int size);
#endif  // WEATHER_H_
