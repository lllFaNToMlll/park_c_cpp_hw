#ifndef HEADERS_FINDALLSEQUENCE_H_
#define HEADERS_FINDALLSEQUENCE_H_

#include "findSequence.h"
#include "readAndCloseFile.h"

unsigned int* findAllSequence(const char *filepath,
                              char **sequenceArray, size_t size);

#endif  // HEADERS_FINDALLSEQUENCE_H_
