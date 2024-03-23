#include "pipex.h"

int main(int argc, char **argv, char **env) {
    int i;
    t_cp cp;
    t_splitted *prg_args;
    int *id;
    int state;

    if(!check_input(argc, argv, &cp))
        return (0);
    id = (int *) malloc(sizeof(int) * (argc - 2));
    i = FIRST_PROGRAM;
    cp.prev_pipe = -1;
    while (i < argc - 1) {
        if(!set_path(&prg_args, argv[i], &cp, env) && i++)
        {
            close(cp.pipe[RD_PIPE]);
            close(cp.pipe[WR_PIPE]);
            close(cp.prev_pipe);
            pipe(cp.pipe);
            close(cp.pipe[WR_PIPE]);
            cp.prev_pipe = cp.pipe[RD_PIPE];
            continue;
        }
        pipe(cp.pipe);
        id[i - 2] = fork();
        if (id[i - 2] == 0)
            child_process(i, &cp, prg_args, env, argc);
        close(cp.prev_pipe);
        close(cp.pipe[WR_PIPE]);
        cp.prev_pipe = cp.pipe[RD_PIPE];
        free_splitted(&prg_args);
        free(cp.path);
        i++;
    }
    state = 0;
    close(cp.pipe[RD_PIPE]);
    close(cp.pipe[WR_PIPE]);
    close(cp.prev_pipe);
    close(cp.infile);
    close(cp.outfile);
    while (state != -1)
        state = waitpid(-1, NULL, 0);
    free(id);
}
