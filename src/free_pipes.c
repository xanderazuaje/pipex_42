#include "pipex.h"

void free_pipes(int *i, int **fd) {
    *i -= 1;
    while (*i >= 0)
        free(fd[(*i)--]);
    free(fd);
}
