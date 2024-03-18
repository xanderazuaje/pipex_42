#include "pipex.h"

int is_path(const char *str) {
    return start_with(str, "./") ||
           start_with(str, "../") ||
           start_with(str, "/");
}
