#include "pipex.h"

void child_process(int i, t_cp *cp, t_splitted *prg_args, char **env, int argc){
    if (i == FIRST_PROGRAM)
        dup2(cp->infile, STDIN_FILENO);
    else
        dup2(cp->pipes[i - 1][0], STDIN_FILENO);
    close(cp->infile);
    close(cp->pipes[i - 1][1]);
    close(cp->pipes[i - 1][0]);
    if (i == argc - 2)
        dup2(cp->outfile, STDOUT_FILENO);
    else
        dup2(cp->pipes[i][1], STDOUT_FILENO);
    close(cp->pipes[i][1]);
    close(cp->pipes[i][0]);
    close(cp->outfile);
    execve(cp->path, prg_args->string, env);
    exit(1);
}

