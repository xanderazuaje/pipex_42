//
// Created by xander on 3/18/24.
//
#include "pipex.h"

int set_path(t_splitted **prg_args, char *arg, t_cp *cp, char **env){
    *prg_args = ft_split(arg, ' ');
    cp->path = find_path((*prg_args)->string[0], env);
    if (!cp->path) {
        ft_putstr_fd(*(*prg_args)->string, 1);
        ft_putstr_fd(": command not found\n", 1);
        free_splitted(prg_args);
        return (0);
    }
    return (1);
}

