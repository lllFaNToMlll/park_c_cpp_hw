#ifndef HEADERS_READANDCLOSEFILE_H_
#define HEADERS_READANDCLOSEFILE_H_

#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>


typedef struct {
    int fd;
    size_t fsize;
    char* dataPtr;
} fileMapping;

fileMapping* readFile(const char* filepath);

void closeFile(fileMapping * mapping);

#endif  // HEADERS_READANDCLOSEFILE_H_
