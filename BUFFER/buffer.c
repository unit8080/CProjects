#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
extern int read(int fd, void *buffer, size_t count);
extern int write(int fd, void *buffer, size_t count);

size_t writen (int fd, void *buf, size_t count)
{
    if (buf == NULL || count == 0)
        return 0;
    size_t curr_count = 0;
    while (count > 0) {
        int rc = write(fd, buf, count);
        if (rc < 0)
            return -1;
        if (rc == 0)
            return curr_count;
        curr_count = curr_count + rc;
        buf = buf + rc;
        count = count - rc;
    }
    return curr_count;
}

size_t readn (int fd, void *buf, size_t count)
{
    if (buf == NULL || count == 0)
        return 0;
    size_t current_count = 0;
    while (count > 0) {
        int rc = read(fd, buf, count);
        if (rc < 0)
            return -1;

        if (rc == 0)
            return current_count;
        current_count = current_count + rc;
        buf = buf + rc;
        count = count - rc;
    }
    return current_count;
}

// Gather of size "count" into buffer "buf" from 
// Array of pointers to buffer of 100 bytes each.
// Return : total bytes gathered.
#define MAX_ARRAY_SIZE 10
int gather (void *buf0, void *A[], size_t count)
{
    void *buf = buf0;
    if (buf == NULL || count == 0)
        return -1;
    int i = 0;
    int bytes_copied = 0;
    while (count > 0 && i < MAX_ARRAY_SIZE) {
        int len = 100;
        if (count < len)
            len = count;
        bcopy(A[i], buf, len);
        bytes_copied = bytes_copied + len;
        count = count - len;
        buf = buf + len;
        i = i + 1;
    }
    return bytes_copied;
}

int main(void)
{

}

