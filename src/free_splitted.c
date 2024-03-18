#include "pipex.h"

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
