NAME		:= minishell

CC			:= cc

CFLAGS		:= -Wall -Werror -Wextra -g

LDFLAGS		:= -lreadline -lncurses 

env		:=		sources/env/env.c \
				sources/env/env_utils.c

exec	:=		sources/exec/exec_utils.c

parsing :=

utils	:=		sources/utils/ft_calloc.c \
				sources/utils/ft_lstadd_back.c \
				sources/utils/ft_lstclear.c \
				sources/utils/ft_lstnew.c \
				sources/utils/ft_memset.c \
				sources/utils/ft_putstr_fd.c \
				sources/utils/ft_strdup.c \
				sources/utils/ft_strlen.c \
				sources/utils/ft_substr.c

SRCS	:=		$(env) \
				$(exec) \
				$(parsing) \
				$(utils)
				sources/main.c \
				sources/signal.c

OBJS		:=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re