NAME        := minishell
CC          := cc
CFLAGS      := -Wall -Werror -Wextra -g
LDFLAGS     := -lreadline  # Link against the readline library

env         :=  sources/env/env.c sources/env/env_utils.c
exec        :=  sources/exec/exec_utils.c sources/exec/exec_builtin.c sources/exec/exist_check.c \
                sources/exec/get_path.c sources/exec/error_msg.c sources/exec/expanded_utils.c sources/exec/expanded.c
utils       :=  sources/utils/ft_calloc.c sources/utils/ft_lstadd_back.c sources/utils/ft_lstclear.c \
                sources/utils/ft_lstnew.c sources/utils/ft_memset.c sources/utils/ft_putstr_fd.c \
                sources/utils/ft_strdup.c sources/utils/ft_strlen.c sources/utils/ft_substr.c sources/utils/ft_bzero.c \
                sources/utils/ft_lstlast.c sources/utils/ft_lstdelone.c sources/utils/ft_strcmp.c \
                sources/utils/ft_strncmp.c sources/utils/ft_isalpha.c sources/utils/ft_isalnum.c \
                sources/utils/ft_strjoin.c sources/utils/ft_strjoin_args.c sources/utils/ft_isspace.c \
                sources/utils/ft_strchr.c sources/utils/ft_atoi.c sources/utils/ft_putchar_fd.c sources/utils/ft_split.c\
                sources/utils/ft_strnstr.c sources/utils/ft_strjoin_f.c 
tokenize    :=  sources/tokenize/tokenizer.c sources/tokenize/tokenizer_lst.c sources/tokenize/tokenizer_appenders.c \
                sources/tokenize/tokenizer_handlers.c sources/tokenize/tokenizer_utils.c
main        :=  sources/main.c 
signal      :=  sources/signal.c
parsing     :=  sources/parsing/parsing.c sources/parsing/parsing_utils.c sources/parsing/parsing_help.c \
                sources/parsing/parsing_nodes.c \
                sources/parsing/parsing_error.c sources/parsing/parsing_clear.c
cleaning    :=  sources/cleaning/clean.c
builtins    :=  sources/builtins/utils.c sources/builtins/cd.c   sources/builtins/pwd.c  \
                sources/builtins/echo.c sources/builtins/env.c sources/builtins/export.c \
                sources/builtins/unset.c sources/builtins/exit.c 
SRCS        :=  $(env) $(exec) $(utils) $(main) $(signal) $(tokenize) $(parsing) $(cleaning) $(builtins)
OBJS        := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
