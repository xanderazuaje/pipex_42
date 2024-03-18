#include "pipex.h"

int assign_in_out_file(t_cp *cp, char **argv, int argc) {
    cp->infile = open(argv[1], O_RDONLY);
    if (cp->infile <= 0) {
        return (0);
    }
    cp->outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (cp->outfile <= 0)
        return (0);
    return (1);
}