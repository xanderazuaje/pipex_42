#include "pipex.h"


int main(const int argc, char **argv, char **env) {
    int i;
    t_cp cp;
    t_splitted *prg_args;
    int **fd;

    if(!check_input(argc, argv, &cp, &fd))
        return (0);
    if(!init_pipes(argc, fd))
        return (0);
    i = FIRST_PROGRAM;
    while (i < argc - 1) {
        prg_args = ft_split(argv[i], ' ');
        cp.path = find_path(prg_args->string[0], env);
        if (!cp.path) {
            i++;
            continue;
        }
        int id = fork();

        if (id == 0) {
            if (i == FIRST_PROGRAM)
                dup2(cp.infile, STDIN_FILENO);
            else
                dup2(fd[i - 1][0], STDIN_FILENO);
            close(cp.infile);
            close(fd[i - 1][1]);
            close(fd[i - 1][0]);
            if (i == argc - 2)
                dup2(cp.outfile, STDOUT_FILENO);
            else
                dup2(fd[i][1], STDOUT_FILENO);
            close(fd[i][1]);
            close(fd[i][0]);
            close(cp.outfile);
            execve(cp.path, prg_args->string, env);
            exit(1);
        }
        free_splitted(&prg_args);
        free(cp.path);
        i++;
    }
    wait(NULL);
    free_pipes(&i, fd);
}
