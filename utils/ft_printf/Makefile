SRCS= ft_printf.c

CC = gcc
MAIN  = main.c
NAME = libftprintf.a
OUT = ./a.out
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -fr
AR = ar -rc
OBJS = $(SRCS:.c=.o)


all: ${NAME}

${NAME}: ${OBJS}
	@${AR} ${NAME} ${OBJS}
	@echo "Succesfully archieved"

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

run: ${NAME}
	@${CC} ${CFLAGS} ${MAIN} ${NAME}
	@${OUT}


clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: fclean clean all
