#include <stdio.h>
#include "pipex.h"

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
        if (start_with(*env, "PATH")) {
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