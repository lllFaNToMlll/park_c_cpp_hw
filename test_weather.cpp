#include <gtest/gtest.h>
#include <iostream>
extern "C" {
#include "Weather.h"
}


TEST(weatherInfo1, analyze1) {
    weatherInfo weatherWeek[SIZE] = {
            {4, 5, 6}
            , {5, 6, 7}
            , {6, 7, 8}
            , {7, 8, 9}
            , {8, 9, 10}
            , {9, 10, 11}
            , {10, 11, 12}
    };
    weatherAnalysis testStruct = {7.0, 4.0, 10.0, 56.0};
    weatherAnalysis analysisWeek = analyze(weatherWeek, SIZE);

    EXPECT_FLOAT_EQ(analysisWeek.averageTemperature,
                    testStruct.averageTemperature);
    EXPECT_FLOAT_EQ(analysisWeek.minTemperature,
                    testStruct.minTemperature);
    EXPECT_FLOAT_EQ(analysisWeek.maxTemperature,
                    testStruct.maxTemperature);
    EXPECT_FLOAT_EQ(analysisWeek.sumPrecipitation,
                    testStruct.sumPrecipitation);
}

TEST(weatherInfo2, analyze2) {
    weatherInfo weatherWeek[SIZE] = {
              {-3, 5, 6}
            , {-2, 5, 7}
            , {-1, 5, 8}
            , {0, 5, 9}
            , {1, 5, 10}
            , {2, 5, 11}
            , {3, 5, 12}
    };
    weatherAnalysis testStruct = {0.0, -3.0, 3.0, 35.0};
    weatherAnalysis analysisWeek = analyze(weatherWeek, SIZE);

    EXPECT_FLOAT_EQ(analysisWeek.averageTemperature,
                    testStruct.averageTemperature);
    EXPECT_FLOAT_EQ(analysisWeek.minTemperature,
                    testStruct.minTemperature);
    EXPECT_FLOAT_EQ(analysisWeek.maxTemperature,
                    testStruct.maxTemperature);
    EXPECT_FLOAT_EQ(analysisWeek.sumPrecipitation,
                    testStruct.sumPrecipitation);
}
