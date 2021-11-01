/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 18:41:49 by fbes          #+#    #+#                 */
/*   Updated: 2021/11/01 21:47:12 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

/**
 * Reverse rotate a stack (shift down all elements by 1, last becomes first one)
 * @param *s	The stack to reverse rotate
 */
void	reverse(t_stack *s)
{
	t_link		*temp;

	if (s->size > 1)
	{
		temp = get_stack_bottom(s);
		temp->next = s->top;
		s->top = temp;
		get_stack_link(s, s->size - 1)->next = NULL;
		s->top->prev = NULL;
		s->top->next->prev = s->top;
	}
}

/**
 * Reverse rotate stack A and print rra
 * @param *a	Stack A
 */
void	rra(t_stack *a)
{
	reverse(a);
	write(1, "rra\n", 4);
}

/**
 * Reverse rotate stack B and print rrb
 * @param *b	Stack B
 */
void	rrb(t_stack *b)
{
	reverse(b);
	write(1, "rrb\n", 4);
}

/**
 * Reverse rotate both stack A and stack B and print rrr
 * @param *a	Stack A
 * @param *b	Stack B
 */
void	rrr(t_stack *a, t_stack *b)
{
	reverse(a);
	reverse(b);
	write(1, "rrr\n", 4);
}

/**
 * Reverse rotate a stack and print rr<s->id>
 * @param *s	A stack
 */
void	rrf(t_stack *s)
{
	reverse(s);
	write(1, "rr", 2);
	write(1, &(s->id), 1);
	write(1, "\n", 1);
}
