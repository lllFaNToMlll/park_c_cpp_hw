#include "WeatherInputOutput.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_PRECIPITATION 2000
#define MIN_PRECIPITATION 0
#define MAX_WINDSPEED 70
#define MIN_WINDSPEED 0

static void checkScan(const int scanChecker) {
    if (scanChecker == 0) {
        printf("\n\nERROR -1! Input error (expected number)."
               "Restart the program and "
               "enter all the values correctly.\n\n");
        exit(-1);
    }
}

static double checkUserInput(const char string[], const int msg_day_number,
                      const int min, const int max, int *scanChecker) {
    printf("Please enter the %s on the %d day of the week: ",
           string, msg_day_number);
    double userInput = 0;
    *scanChecker = scanf("%lf", &userInput);
    checkScan(*scanChecker);

    while (userInput > max || userInput < min) {
        printf("Please enter the permissible %s on the %d day of the week "
               "(from %d to %d): ", string, msg_day_number, min, max);
        *scanChecker = scanf("%lf", &userInput);
        checkScan(*scanChecker);
    }

    return userInput;
}

static void checkSize(const int size) {
    if (size != SIZE) {
        printf("\n\nERROR -2! Input error (minimum number of entries = 7)."
               " Restart the program and fill in at least a whole week.\n\n");
        exit(-2);
    }
}

static void checkExit(const int scanChecker) {
    if (scanChecker == EOF) {
        printf("\n\nERROR -3! Input error (you can stop entering only "
               "after filling in all the information about the current day). "
               "Restart the program.\n\n");
        exit(-3);
    }
}

void scanWeek(weatherInfo *weekWeather) {
    int scanChecker = 0, msg_day_number = 0, size = 0;
    double buf = 0;
    while (1) {
        buf = checkUserInput(
                "temperature (or use Ctrl+D to stop typing."
                " The input stop is available only after filling in the week.)",
                msg_day_number + 1, MIN_TEMPERATURE,
                MAX_TEMPERATURE, &scanChecker);
        if (scanChecker == EOF) {
            checkSize(size);
            return;
        }
        weekWeather[msg_day_number].temperature = buf;
        weekWeather[msg_day_number].precipitation = checkUserInput(
                "precipitation", msg_day_number + 1, MIN_PRECIPITATION,
                MAX_PRECIPITATION, &scanChecker);
        checkExit(scanChecker);

        weekWeather[msg_day_number].windSpeed = checkUserInput(
                "wind speed (m/s)", msg_day_number + 1, MIN_WINDSPEED,
                MAX_WINDSPEED, &scanChecker);
        checkExit(scanChecker);

        msg_day_number++;
        if (msg_day_number == 7) {
            msg_day_number = 0;
            size = SIZE;
        }
    }
}

void printWeek(const weatherInfo weekWeather[], int size) {
    for (int i = 0; i < size; ++i)
        printf("\n%d day: temperature: %2.2f, precipitation: %2.2f, "
               "wind speed: %2.2f\n", i+1, weekWeather[i].temperature,
               weekWeather[i].precipitation, weekWeather[i].windSpeed);
}

void printAnalysis(const weatherAnalysis *analysisWeek) {
    printf("Max temperature: %2.2f; Min temperature: %2.2f; "
           "Average temperature: %2.2f; Sum of precipitation: %2.2f\n",
           analysisWeek->maxTemperature, analysisWeek->minTemperature,
           analysisWeek->averageTemperature, analysisWeek->sumPrecipitation);
}
