#include "Weather.h"
#include "WeatherInputOutput.h"

int main() {
    weatherInfo weatherWeek[SIZE];
    scanWeek(weatherWeek);
    printWeek(weatherWeek, SIZE);
    weatherAnalysis analysisWeek = analyze(weatherWeek, SIZE);
    printAnalysis(&analysisWeek);
    return 0;
}
