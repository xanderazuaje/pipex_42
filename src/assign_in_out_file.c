#include "pipex.h"

int assign_in_out_file(t_cp *cp, char **argv, int argc) {
    int pipe_fd[2];
    char *last_line;
    char *limit;

    if(ft_strncmp(argv[1], "here_doc", 9) == 0)
    {
        limit = ft_strjoin(argv[2], "\n");
        if (!limit)
            return (0);
        if(pipe(pipe_fd) == -1)
            return (0);
        cp->infile = pipe_fd[0];
        while(1)
        {
            last_line = get_next_line(STDIN_FILENO);
            if(!last_line)
                return(close(pipe_fd[0]), 0);
            if(ft_strncmp(limit, last_line, 9) == 0)
            {
                close(pipe_fd[1]);
                free(last_line);
                free(limit);
                break;
            }
            write(pipe_fd[1], last_line, ft_strlen(last_line));
            free(last_line);
        }
    }
    else
        cp->infile = open(argv[1], O_RDONLY);
    if (cp->infile < 0) {
        return (0);
    }
    cp->outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (cp->outfile <= 0)
        return (0);
    return (1);
}