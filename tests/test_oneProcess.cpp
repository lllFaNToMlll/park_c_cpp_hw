#include <gtest/gtest.h>
#include <iostream>
extern "C" {
#include "findAllSequence.h"
}

TEST(oneProcess1, testfile1) {
    char **sequenceArray = (char **)malloc((4)*sizeof(char *));
    sequenceArray[0] = (char *)malloc((strlen("ga") + 1)*sizeof(char));
    sequenceArray[1] = (char *)malloc((strlen("ma") + 1)*sizeof(char));
    sequenceArray[2] = (char *)malloc((strlen("ke") + 1)*sizeof(char));
    sequenceArray[3] = (char *)malloc((strlen("mb") + 1)*sizeof(char));
    strcpy(sequenceArray[0], "ga");
    strcpy(sequenceArray[1], "ma");
    strcpy(sequenceArray[2], "ke");
    strcpy(sequenceArray[3], "mb");
    const char *filepath = "texts/testfile1.txt";

    unsigned int* seqCounter = findAllSequence(filepath, sequenceArray, 4);

    EXPECT_EQ(seqCounter[0], 3);
    EXPECT_EQ(seqCounter[1], 2);
    EXPECT_EQ(seqCounter[2], 2);
    EXPECT_EQ(seqCounter[3], 1);

    munmap(seqCounter, 4*sizeof(unsigned int));
    for (int i = 0; i < 4; ++i) {
        free(sequenceArray[i]);
    }
    free(sequenceArray);
}

TEST(oneProcess2, falseFilepath) {
    char **sequenceArray = (char **)malloc((4)*sizeof(char *));
    sequenceArray[0] = (char *)malloc((strlen("ga") + 1)*sizeof(char));
    sequenceArray[1] = (char *)malloc((strlen("ma") + 1)*sizeof(char));
    sequenceArray[2] = (char *)malloc((strlen("ke") + 1)*sizeof(char));
    sequenceArray[3] = (char *)malloc((strlen("mb") + 1)*sizeof(char));
    strcpy(sequenceArray[0], "ga");
    strcpy(sequenceArray[1], "ma");
    strcpy(sequenceArray[2], "ke");
    strcpy(sequenceArray[3], "mb");
    const char *filepath = "texts/badFilepath.txt";

    unsigned int* seqCounter = findAllSequence(filepath, sequenceArray, 4);

    EXPECT_EQ(seqCounter, nullptr);

    munmap(seqCounter, 4*sizeof(unsigned int));
    for (int i = 0; i < 4; ++i) {
        free(sequenceArray[i]);
    }
    free(sequenceArray);
}

TEST(oneProcess3, testfile2) {
    char **sequenceArray = (char **)malloc((4)*sizeof(char *));
    sequenceArray[0] = (char *)malloc((strlen("Dj") + 1)*sizeof(char));
    sequenceArray[1] = (char *)malloc((strlen("4") + 1)*sizeof(char));
    sequenceArray[2] = (char *)malloc((strlen("aw") + 1)*sizeof(char));
    sequenceArray[3] = (char *)malloc((strlen("as") + 1)*sizeof(char));
    strcpy(sequenceArray[0], "Dj");
    strcpy(sequenceArray[1], "4");
    strcpy(sequenceArray[2], "aw");
    strcpy(sequenceArray[3], "as");
    const char *filepath = "texts/testfile2.txt";

    unsigned int* seqCounter = findAllSequence(filepath, sequenceArray, 4);

    EXPECT_EQ(seqCounter[0], 1);
    EXPECT_EQ(seqCounter[1], 0);
    EXPECT_EQ(seqCounter[2], 3);
    EXPECT_EQ(seqCounter[3], 4);

    munmap(seqCounter, 4*sizeof(unsigned int));
    for (int i = 0; i < 4; ++i) {
        free(sequenceArray[i]);
    }
    free(sequenceArray);
}
