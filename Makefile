NAME		:= minishell

CC			:= cc

CFLAGS		:= -Wall -Werror -Wextra

env		:=		sources/env/env.c \
				sources/env/env_utils.c

exec	:=		sources/exec/exec_utils.c

parsing :=

utils	:=		sources/utils/ft_calloc.c
				sources/utils/ft_lstadd_back.c
				sources/utils/ft_lstclear.c
				sources/utils/ft_lstnew.c
				sources/utils/
				sources/utils/
				sources/utils/
				sources/utils/
				sources/utils/

SRCS	:=		$(env) \
				$(exec) \
				$(parsing) \
				$(utils)
				main.c \
				sources/signal.c

