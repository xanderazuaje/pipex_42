#include "pipex.h"

static void reset_pipes(t_cp *cp) {
    close((*cp).pipe[RD_PIPE]);
    close((*cp).pipe[WR_PIPE]);
    close((*cp).prev_pipe);
    pipe((*cp).pipe);
    close((*cp).pipe[WR_PIPE]);
    (*cp).prev_pipe = (*cp).pipe[RD_PIPE];
}

static void finish_pipes(t_cp *cp) {
    close((*cp).pipe[RD_PIPE]);
    close((*cp).pipe[WR_PIPE]);
    close((*cp).infile);
    close((*cp).outfile);
}

static int getFirstCommand(char **argv) {
    if(ft_strncmp("here_doc", argv[2], 9))
        return 3;
    return 2;
}

void iterate_pipes(int argc, char *const *argv, char **env, t_cp *cp) {
    int i;
    int *id;

    i = (*cp).count;
    id = (int *) malloc(sizeof(int) * (argc - (*cp).count));
    while (i < argc - 1) {
        if(!set_path(&(*cp).prg_args, argv[i], cp, env) && i++)
        {
            reset_pipes(cp);
            continue;
        }
        pipex(argc, env, i, id, cp);
        i++;
    }
    free(id);
}

int main(int argc, char **argv, char **env) {
    t_cp cp;
    int state;

    if(!check_input(argc, argv, &cp))
        return (0);
    cp.count = getFirstCommand(argv);
    iterate_pipes(argc, argv, env, &cp);
    state = 0;
    finish_pipes(&cp);
    while (state != -1)
        state = waitpid(-1, NULL, 0);
}
