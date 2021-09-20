/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 17:41:49 by fbes          #+#    #+#                 */
/*   Updated: 2021/09/20 12:57:32 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

// stacks implemented using arrays
// top equals last index

void	print_stack(t_stack *s)
{
	int		i;

	i = 0;
	ft_putstr_fd("BOTTOM (BIGGEST) [", 1);
	while (i < s->length)
	{
		if (i > 0)
			ft_putchar_fd(' ', 1);
		ft_putnbr_fd(s->stack[i], 1);
		i++;
	}
	ft_putstr_fd("] TOP (SMALLEST)\n", 1);
}

void	free_stack(t_stack *s)
{
	if (s)
	{
		if (s->stack)
			free(s->stack);
		free(s);
		s = NULL;
	}
}

t_stack	*new_stack(char id, int maxlen)
{
	t_stack		*s;

	s = (t_stack *)malloc(sizeof(t_stack));
	if (s)
	{
		s->id = id;
		s->max = maxlen;
		s->length = 0;
		s->stack = (int *)ft_calloc(maxlen, sizeof(int));
		if (!s->stack)
			free_stack(s);
	}
	return (s);
}
