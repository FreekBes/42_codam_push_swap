/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 18:40:34 by fbes          #+#    #+#                 */
/*   Updated: 2021/09/20 12:06:17 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <unistd.h>

void	swap(t_stack *s)
{
	int		temp;

	if (s->length > 1)
	{
		temp = s->stack[s->length - 1];
		s->stack[s->length - 1] = s->stack[s->length - 2];
		s->stack[s->length - 2] = temp;
	}
}

void	sa(t_stack *a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

void	sf(t_stack *s)
{
	swap(s);
	write(1, "s", 1);
	write(1, &(s->id), 1);
	write(1, "\n", 1);
}
