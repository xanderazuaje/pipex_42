#include "pipex.h"
#include <stdio.h>

/*
 * 1. Create pipe
 * 2. Create fork
 * 3. Dup2 to pipes
 * 4. Execve
 */

#define FIRST_PROGRAM 2

int starts_with(const char *str, const char *find) {
    while (*str && *find) {
        if (*str != *find)
            return (0);
        str++;
        find++;
    }
    return (1);
}

void free_splitted(t_splitted **s) {
    if (!*s)
        return;
    while ((*s)->len) {
        free((*s)->string[(*s)->len - 1]);
        (*s)->len--;
    }
    free((*s)->string);
    free(*s);
}

int is_path(const char *str) {
    return starts_with(str, "./") ||
           starts_with(str, "../") ||
           starts_with(str, "/");
}

char *find_path(const char *program, char **env) {
    t_splitted *routes = NULL;
    char *path = NULL;
    char *prev;
    size_t i = 0;
    int status;

    if (!program)
        return (NULL);
    if (is_path(program))
        return (ft_strdup(program));
    while (*env) {
        if (starts_with(*env, "PATH")) {
            routes = ft_split(*env + 5, ':');
            if (!routes)
                return (NULL);
        }
        env++;
    }
    while (routes && i < routes->len) {
        prev = ft_strjoin("/", program);
        if (!prev)
            break;
        path = ft_strjoin(routes->string[i], prev);
        free(prev);
        if (!path)
            break;
        status = access(path, X_OK);
        if (status == 0) {
            free_splitted(&routes);
            return path;
        }
        free(path);
        i++;
    }
    free_splitted(&routes);
    return (NULL);
}

typedef struct s_cp {
    char *path;
    int infile;
    int outfile;
} t_cp;

void free_pipes(int *i, int **fd) {
    *i -= 1;
    while (*i >= 0)
        free(fd[(*i)--]);
    free(fd);
}

int main(const int argc, char **argv, char **env) {
    int i;
    t_cp cp;
    t_splitted *prg_args;
    int **fd;
    if (argc < 5) {
        return (0);
    }
    ft_bzero(&cp, sizeof(t_cp));
    cp.infile = open(argv[1], O_RDONLY);
    if (cp.infile <= 0) {
        perror("error");
        return (0);
    }
    cp.outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (cp.outfile <= 0)
        return (0);
    fd = (int **) malloc((argc - 1) * sizeof(int *));
    if (!fd) {
        perror("error");
    }
    i = 0;
    while (i < argc - 1) {
        fd[i] = (int *) malloc(2 * sizeof(int));
        if (!fd[i]) {
            free_pipes(&i, fd);
        }
        pipe(fd[i]);
        i++;
    }
    i = FIRST_PROGRAM;
    while (i < argc - 1) {
        prg_args = ft_split(argv[i], ' ');
        cp.path = find_path(prg_args->string[0], env);
        if (!cp.path) {
            i++;
            continue;
        }
        // aoeu
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
