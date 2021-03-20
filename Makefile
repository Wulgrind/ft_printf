#Compilation

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
INC = -I.

#VALUES

NAME	= libftprintf.a

#MISC

#SOURCES

FILES	=	ft_initflags.c		\
			ft_printf.c			\
			ft_printfC.c		\
			ft_printfD.c		\
			ft_printfP.c		\
			ft_printfS.c		\
			ft_printfU.c		\
			ft_printfX.c		\
			ft_printf_utils.c	\
			ft_printf_utils2.c	\
			ft_printf_utils3.c	\

OBJS	= ${FILES:.c=.o}

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME):	${OBJS}
					ar -cr $(NAME) $(OBJS) ft_printf.h

all:	${NAME}

clean:
		@rm -f *.o;	 rm -f *~

fclean: clean
				@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
