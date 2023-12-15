#include <fcntl.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

#define BUFFER_SIZE 42
void test_get_next_line() {
    int fd = open("files/42_with_nl", O_RDWR);
    assert(fd != -1);

    char *line = get_next_line(fd);
    assert(line != NULL);
    assert(strcmp(line, "01234567890123456789012345678901234567890\n") == 0);
    free(line);

    if (BUFFER_SIZE == 42) {
        char c = 0;
        read(fd, &c, 1);
        assert(c == '1');

        line = get_next_line(fd);
        assert(line == NULL);
    } else {
        line = get_next_line(fd);
        assert(line != NULL);
        assert(strcmp(line, "1") == 0);
        free(line);

        line = get_next_line(fd);
        assert(line == NULL);
    }

    close(fd);
}

