/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 18:41:53 by fbes          #+#    #+#                 */
/*   Updated: 2021/09/20 12:04:03 by fbes          ########   odam.nl         */
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
		pop(b);
		write(1, "pa\n", 3);
	}
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->length > 0)
	{
		push(b, a->stack[a->length - 1]);
		pop(a);
		write(1, "pb\n", 3);
	}
}

void	pf(t_stack *s1, t_stack *s2)
{
	if (s1->length > 0)
	{
		push(s2, s1->stack[s1->length - 1]);
		pop(s1);
		write(1, "p", 1);
		write(1, &(s2->id), 1);
		write(1, "\n", 1);
	}
}
