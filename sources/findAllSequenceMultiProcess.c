#include <sys/sysinfo.h>
#include <signal.h>
#include <wait.h>
#include "findAllSequence.h"

unsigned int* findAllSequence(const char *filepath,
                              char **sequenceArray, size_t size) {
    errno = 0;
    fileMapping *mapping = readFile(filepath);
    if (mapping == NULL) {
        // check errno
        return NULL;
    }
    size_t dataSize = strlen(mapping->dataPtr);
    dataInfo dInfo = {mapping->dataPtr, dataSize};
    int procCounter = get_nprocs();

    unsigned int* ptrSeqCounter = mmap(NULL, size*sizeof(unsigned int),
                               PROT_READ | PROT_WRITE,
                               MAP_SHARED | MAP_ANONYMOUS,
                               0, 0);
    if (ptrSeqCounter == MAP_FAILED) {
        // check errno
        closeFile(mapping);
        return NULL;
    }

    pid_t pid = 0;
    int startIndex = 0, finishIndex = 0;
    __pid_t childId[procCounter];
    for (int i = 0; i < procCounter; ++i) {
        int num_of_patterns = size / (procCounter - i);
        size -= num_of_patterns;
        finishIndex += num_of_patterns;

        pid = fork();
        if (pid < 0) {
            if (i > 0) {
                for (int k = 0; k < i; ++k) {
                    kill(childId[k], SIGKILL);
                    waitpid(childId[k], NULL, 0);
                }
            } else {
                kill(pid, SIGKILL);
            }
            // check errno
            closeFile(mapping);
            return NULL;
        }

        if (pid != 0)
            childId[i] = pid;

        if (pid == 0) {
            for (int j = startIndex; j < finishIndex; ++j) {
                ptrSeqCounter[j] = findSequence(dInfo, sequenceArray[j]);
            }
            exit(0);
        }

        startIndex += num_of_patterns;
    }

    for (int i = 0; i < procCounter; ++i) {
        waitpid(-1, NULL, 0);
    }

    closeFile(mapping);
    return ptrSeqCounter;
}
