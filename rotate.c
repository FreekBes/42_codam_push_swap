/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 18:41:51 by fbes          #+#    #+#                 */
/*   Updated: 2021/11/01 21:46:54 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

/**
 * Rotate a stack (shift up all elements by 1, first becomes last one)
 * @param *s	The stack to rotate
 */
void	rotate(t_stack *s)
{
	t_link		*temp;
	t_link		*bottom;

	if (s->size > 1)
	{
		temp = s->top;
		s->top = temp->next;
		s->top->prev = NULL;
		temp->next = NULL;
		bottom = get_stack_bottom(s);
		temp->prev = bottom;
		bottom->next = temp;
	}
}

/**
 * Rotate stack A and print ra
 * @param *a	Stack A
 */
void	ra(t_stack *a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

/**
 * Rotate stack B and print rb
 * @param *b	Stack B
 */
void	rb(t_stack *b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

/**
 * Rotate both stack A and stack B and print rr
 * @param *a	Stack A
 * @param *b	Stack B
 */
void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

/**
 * Rotate a stack and print r<s->id>
 * @param *s	A stack
 */
void	rf(t_stack *s)
{
	rotate(s);
	write(1, "r", 1);
	write(1, &(s->id), 1);
	write(1, "\n", 1);
}
