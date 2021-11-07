#include "findAllSequence.h"
#include <time.h>

int main(int argc, char *argv[]) {
    time_t start;
    start = time(NULL);
    if (argc < 2) {
        printf("File path not mentioned\n");
        exit(0);
    }
    char **sequenceArray = (char **)malloc((argc-2)*sizeof(char *));
    for (int i = 0; i < argc-2; ++i) {
        sequenceArray[i] = (char *)malloc((strlen(argv[i+2]) + 1)*sizeof(char));
        strcpy(sequenceArray[i], argv[i+2]);
    }
    const char *filepath = argv[1];

    unsigned int* seqCounter = findAllSequence(filepath, sequenceArray, argc-2);
    if (seqCounter == NULL)
        printf("ERROR %d", errno);
    printf("Text: \"%s\"\n", filepath);
    for (int i = 0; i < argc-2; ++i)
        printf("The number of \"%s\": %d \n", sequenceArray[i], seqCounter[i]);
    munmap(seqCounter, (argc-2)*sizeof(unsigned int));
    for (int i = 0; i < (argc-2); ++i) {
        free(sequenceArray[i]);
    }
    free(sequenceArray);
    time_t end;
    end = time(NULL);
    printf("Time-run of the program: %ld"
           " \n--------------------------------\n", end-start);
    return 0;
}
