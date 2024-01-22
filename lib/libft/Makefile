NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3

SOURCE = ft_isalpha\
	ft_isdigit\
	ft_isalnum\
	ft_isascii\
	ft_isprint\
	ft_strlen\
	ft_memset\
	ft_bzero\
	ft_memcpy\
	ft_memmove\
	ft_strlcpy\
	ft_strlcat\
	ft_toupper\
	ft_tolower\
	ft_strchr\
	ft_strrchr\
	ft_strncmp\
	ft_memchr\
	ft_memcmp\
	ft_strnstr\
	ft_atoi\
	ft_calloc\
	ft_strdup\
	ft_substr\
	ft_strjoin\
	ft_strtrim\
	ft_split\
	ft_itoa\
	ft_strmapi\
	ft_striteri\
	ft_putchar_fd\
	ft_putstr_fd\
	ft_putendl_fd\
	ft_putnbr_fd\
	ft_lstadd_front\
	ft_lstsize\
	ft_lstlast\
	ft_lstadd_back\
	ft_lstdelone\
	ft_lstclear\
	ft_lstiter\
	ft_lstmap\
	ft_lstnew\
	len_to_char\


OBJS = $(SOURCE:=.o)

$(NAME): $(OBJS)
	@ar -r $(NAME) $(OBJS)
	@echo compiling...

all: $(NAME) 

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re
