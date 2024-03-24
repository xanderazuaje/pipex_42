//
// Created by xander on 3/24/24.
//

#include "pipex.h"


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