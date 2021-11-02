#include "Weather.h"

weatherAnalysis analyze(const weatherInfo weekWeather[], int size) {
    weatherAnalysis analysisData = {weekWeather[0].temperature,
                                    weekWeather[0].temperature,
                                    weekWeather[0].temperature,
                                    weekWeather[0].precipitation};

    for (int i = 1; i < size; ++i) {
        analysisData.sumPrecipitation += weekWeather[i].precipitation;
        analysisData.averageTemperature += weekWeather[i].temperature;

        if (analysisData.maxTemperature < weekWeather[i].temperature)
            analysisData.maxTemperature = weekWeather[i].temperature;

        if (analysisData.minTemperature > weekWeather[i].temperature)
            analysisData.minTemperature = weekWeather[i].temperature;
    }

     analysisData.averageTemperature /= size;

     return analysisData;
}
