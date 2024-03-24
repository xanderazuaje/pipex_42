#include "pipex.h"

void reset_pipes(t_cp *cp) {
    close((*cp).pipe[RD_PIPE]);
    close((*cp).pipe[WR_PIPE]);
    close((*cp).prev_pipe);
    pipe((*cp).pipe);
    close((*cp).pipe[WR_PIPE]);
    (*cp).prev_pipe = (*cp).pipe[RD_PIPE];
}

void finish_pipes(t_cp *cp) {
    close((*cp).pipe[RD_PIPE]);
    close((*cp).pipe[WR_PIPE]);
    close((*cp).infile);
    close((*cp).outfile);
}

void pipex(int argc, char **env, int i, int *id, t_cp *cp) {

    pipe(cp->pipe);
    id[i - cp->count] = fork();
    if (id[i - cp->count] == 0)
        child_process(i, cp, env, argc);
    close(cp->pipe[WR_PIPE]);
    cp->prev_pipe = cp->pipe[RD_PIPE];
    free_splitted(&cp->prg_args);
    free(cp->path);
}

int getFirstCommand(char **argv) {
    if(ft_strncmp("here_doc", argv[2], 9))
        return 3;
    return 2;
}

int main(int argc, char **argv, char **env) {
    int i;
    t_cp cp;
    int *id;
    int state;

    if(!check_input(argc, argv, &cp))
        return (0);
    cp.count = getFirstCommand(argv);
    i = cp.count;
    id = (int *) malloc(sizeof(int) * (argc - cp.count));
    while (i < argc - 1) {
        if(!set_path(&cp.prg_args, argv[i], &cp, env) && i++)
        {
            reset_pipes(&cp);
            continue;
        }
        pipex(argc, env, i, id, &cp);
        i++;
    }
    state = 0;
    finish_pipes(&cp);
    while (state != -1)
        state = waitpid(-1, NULL, 0);
    free(id);
}
