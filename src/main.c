#include "pipex.h"

void close_pipes(int argc, int **pipes)
{
    int i = 0;
    while(i < argc - 1){
        close(pipes[i][0]);
        close(pipes[i][1]);
        i++;
    }
}

int main(int argc, char **argv, char **env) {
    int i;
    t_cp cp;
    t_splitted *prg_args;
    int id;

    if(!check_input(argc, argv, &cp))
        return (0);
    if(!init_pipes(argc, cp.pipes))
        return (0);
    i = FIRST_PROGRAM;
    while (i < argc - 1) {
        if(!set_path(&prg_args, argv[i], &cp, env) && i++)
            continue;
        id = fork();
        if (id == 0)
            child_process(i, &cp, prg_args, env, argc);
        free_splitted(&prg_args);
        free(cp.path);
        i++;
    }
    close_pipes(argc, cp.pipes);
    while(argc-- - 2 > 1)
        wait(NULL);
    free_pipes(&i, cp.pipes);
}
