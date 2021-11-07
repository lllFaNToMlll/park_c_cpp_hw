#include "findSequence.h"

unsigned int findSequence(dataInfo dInfo, char *seq) {
    unsigned int seqCounter = 0, flag = 0;
    size_t seqSize = strlen(seq);
    for (size_t dataIdx = 0; dataIdx < dInfo.dataSize; ++dataIdx) {
        if (seq[0] == dInfo.data[dataIdx]) {
            for (size_t i = 1; i < seqSize &&
            (dataIdx + i) < dInfo.dataSize; ++i) {
                if (seq[i] != dInfo.data[dataIdx + i]) {
                    flag = 0;
                    dataIdx += i-1;
                    break;
                }
                flag = 1;
            }
            if (flag == 1)
                seqCounter++;
        }
    }
    return seqCounter;
}
