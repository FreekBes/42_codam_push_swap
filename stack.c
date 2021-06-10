/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 17:41:49 by fbes          #+#    #+#                 */
/*   Updated: 2021/06/10 18:10:54 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	print_stack(t_stack *s)
{
	int		i;

	i = 0;
	while (i < s->max)
	{
		if (i > 0)
			ft_putchar_fd(' ', 1);
		ft_putnbr_fd(s->stack[i], 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
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
