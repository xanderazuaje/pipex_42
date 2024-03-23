#include "pipex.h"

int check_input(const int argc, char** argv, t_cp *cp)
{
    if (argc < 5)
        return (ft_putstr_fd("not enough params\n", 1), 0);
    if (!assign_in_out_file(cp, argv, argc))
        return (perror("error"), 0);
    return (1);
}
