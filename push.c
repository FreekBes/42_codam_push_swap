/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 18:41:53 by fbes          #+#    #+#                 */
/*   Updated: 2021/10/26 22:08:56 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <unistd.h>

int	push(t_stack *s, int n)
{
	t_frame		*frame;

	frame = malloc(sizeof(t_frame));
	if (frame)
	{
		frame->num = n;
		frame->next = s->top;
		frame->prev = NULL;
		if (s->top != NULL)
			s->top->prev = frame;
		s->top = frame;
		s->size += 1;
		return (1);
	}
	return (0);
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->size > 0)
	{
		push(a, b->top->num);
		pop(b);
		write(1, "pa\n", 3);
	}
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->size > 0)
	{
		push(b, a->top->num);
		pop(a);
		write(1, "pb\n", 3);
	}
}

void	pf(t_stack *s1, t_stack *s2)
{
	if (s1->size > 0)
	{
		push(s2, s1->top->num);
		pop(s1);
		write(1, "p", 1);
		write(1, &(s2->id), 1);
		write(1, "\n", 1);
	}
}
