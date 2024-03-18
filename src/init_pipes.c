#include "pipex.h"

int init_pipes(const int argc,int **fd){
    int i;

    i = 0;
    while (i < argc - 1) {
        fd[i] = (int *) malloc(2 * sizeof(int));
        if (!fd[i]) {
            free_pipes(&i, fd);
            return (0);
        }
        pipe(fd[i]);
        i++;
    }
    return (1);
}
