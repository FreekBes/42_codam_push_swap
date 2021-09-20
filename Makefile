# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fbes <fbes@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2021/06/10 17:22:54 by fbes          #+#    #+#                  #
#    Updated: 2021/09/20 12:51:41 by fbes          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =			push_swap

SRCS =			main.c num_handling.c stack.c push.c reverse.c rotate.c swap.c \
				pop.c sort.c sort_three.c sort_five.c is_sorted.c

OBJS =			$(SRCS:.c=.o)

CFLAGS =

all: $(NAME)

$(NAME): libft $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) libft/libft.a -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

libft: FORCE
	make -C libft

FORCE:

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean:
	rm -f $(OBJS) $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re libft FORCE
