#include "findAllSequence.h"

unsigned int* findAllSequence(const char *filepath,
                              char **sequenceArray, size_t size) {
    errno = 0;
    fileMapping *mapping = readFile(filepath);
    if (mapping == NULL) {
        // check errno
        return NULL;
    }
    unsigned int* ptrSeqCounter = mmap(NULL, size*sizeof(unsigned int),
                                       PROT_READ | PROT_WRITE,
                                       MAP_SHARED | MAP_ANONYMOUS,
                                       0, 0);
    if (ptrSeqCounter == MAP_FAILED) {
        // check errno
        return NULL;
    }
    size_t dataSize = strlen(mapping->dataPtr);
    dataInfo dInfo = {mapping->dataPtr, dataSize};

    for (size_t i = 0; i < size; ++i) {
        ptrSeqCounter[i] = findSequence(dInfo, sequenceArray[i]);
    }

    closeFile(mapping);
    return ptrSeqCounter;
}
