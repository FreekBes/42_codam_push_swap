# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fbes <fbes@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2021/06/10 17:22:54 by fbes          #+#    #+#                  #
#    Updated: 2021/11/01 16:52:17 by fbes          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =			push_swap

SRCS =			main.c num_handling.c stack.c push.c reverse.c rotate.c swap.c \
				pop.c sort.c is_sorted.c debug.c link.c indexes.c

OBJS =			$(SRCS:.c=.o)

CFLAGS =		-Wall -Werror -Wextra -pedantic -std=c89

all: $(NAME)

$(NAME): libft/libft.a $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -I libft libft/libft.a -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -I libft

libft/libft.a:
	make -C libft

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean:
	rm -f $(OBJS) $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
