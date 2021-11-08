#include "readAndCloseFile.h"

fileMapping* readFile(const char* filepath) {
    errno = 0;
    int fd = open(filepath, O_RDONLY);
    if (fd < 0) {
        // check errno
        return NULL;
    }

    struct stat statbuf;
    if (fstat(fd, &statbuf) < 0) {
        close(fd);
        // check errno
        return NULL;
    }
    size_t fsize = (size_t)statbuf.st_size;

    char *ptr = mmap(NULL, fsize,
                     PROT_READ,
                     MAP_PRIVATE,
                     fd, 0);
    if (ptr == MAP_FAILED) {
        close(fd);
        // check errno
        return NULL;
    }
    fileMapping * mapping = (fileMapping *)malloc(sizeof(fileMapping));
    if (mapping == NULL) {
        munmap(ptr, fsize);
        close(fd);
        // check errno
        return NULL;
    }

    mapping->fd = fd;
    mapping->fsize = fsize;
    mapping->dataPtr = ptr;

    return mapping;
}

void closeFile(fileMapping * mapping) {
    munmap(mapping->dataPtr, mapping->fsize);
    close(mapping->fd);
    free(mapping);
}
