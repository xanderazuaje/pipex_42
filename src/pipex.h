//
// Created by xander on 1/21/24.
//

#ifndef PIPEX_H
#define PIPEX_H

#define FIRST_PROGRAM 2

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include "../lib/libft/libft.h"
#include <fcntl.h>

typedef struct s_cp {
    char *path;
    int infile;
    int outfile;
    int in_write_fd;
    int **pipes;
} t_cp;

int start_with(const char *str, const char *find);
void free_splitted(t_splitted **s);
int is_path(const char *str);
char *find_path(const char *program, char **env);
int assign_in_out_file(t_cp *cp, char **argv, int argc);
void free_pipes(int *i, int **fd);
int check_input(int argc, char** argv, t_cp *cp);
int init_pipes(int argc,int **fd);
int set_path(t_splitted **prg_args, char *arg, t_cp *cp, char **env);
void child_process(int i, t_cp *cp, t_splitted *prg_args, char **env, int argc);
#endif //PIPEX_H
