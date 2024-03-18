#include "pipex.h"

int start_with(const char *str, const char *find) {
    while (*str && *find) {
        if (*str != *find)
            return (0);
        str++;
        find++;
    }
    return (1);
}
