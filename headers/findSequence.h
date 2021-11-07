#ifndef HEADERS_FINDSEQUENCE_H_
#define HEADERS_FINDSEQUENCE_H_
#include <string.h>

typedef struct {
    char* data;
    size_t dataSize;
} dataInfo;

unsigned int findSequence(dataInfo dInfo, char *seq);

#endif  // HEADERS_FINDSEQUENCE_H_
