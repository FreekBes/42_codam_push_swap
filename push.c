/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 18:41:53 by fbes          #+#    #+#                 */
/*   Updated: 2021/06/10 18:55:13 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <unistd.h>

void	push(t_stack *s, int n)
{
	if (s->length < s->max)
	{
		s->stack[s->length] = n;
		s->length++;
	}
	else
		s->stack[s->length - 1] = n;
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->length > 0)
	{
		push(a, b->stack[b->length - 1]);
		write(1, "pa\n", 3);
	}
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->length > 0)
	{
		push(b, a->stack[a->length - 1]);
		write(1, "pb\n", 3);
	}
}
