#include "pipex.h"
#include <stdio.h>

/*
 * 1. Create pipe
 * 2. Create fork
 * 3. Dup2 to pipes
 * 4. Execve
 */

// ping [1]

int is_path(char *str) {
    char *path;

    path = "PATH";
    while (*str && *path) {
        if (*str != *path)
            return (0);
        str++;
        path++;
    }
    return (1);
}

int main(int argc, char **argv, char **env) {
    /*
    int fd[2];
    if (pipe(fd) == -1) {
        return (0);
    }
    int pid_left;
    int pid_right;

    pid_left = fork();
    if (pid_left == -1) {
        return (0);
    }
    if (pid_left == 0) {
        close(fd[0]);
        execve()
    }

    close(fd[0]);
    close(fd[1]);
    */
    return (0);
}
