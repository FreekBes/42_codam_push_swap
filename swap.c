/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 18:40:34 by fbes          #+#    #+#                 */
/*   Updated: 2021/11/01 21:46:13 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

/**
 * Swap the first two links of a stack
 * @param *s	The stack to swap from
 */
void	swap(t_stack *s)
{
	t_link		*temp;

	if (s->size > 1)
	{
		temp = s->top;
		s->top = temp->next;
		temp->next = s->top->next;
		s->top->next = temp;
		s->top->prev = NULL;
		s->top->next->prev = s->top;
		s->top->next->next->prev = s->top->next;
	}
}

/**
 * Swap the first two elements of stack A and print sa
 * @param *a	Stack A
 */
void	sa(t_stack *a)
{
	swap(a);
	write(1, "sa\n", 3);
}

/**
 * Swap the first two elements of stack B and print sb
 * @param *b	Stack B
 */
void	sb(t_stack *b)
{
	swap(b);
	write(1, "sb\n", 3);
}

/**
 * Swap the first two elements of both stack A and stack B and print ss
 * @param *a	Stack A
 * @param *b	Stack B
 */
void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

/**
 * Swap the first two elements of a stack and print s<s->id>
 * @param *s	A stack
 */
void	sf(t_stack *s)
{
	swap(s);
	write(1, "s", 1);
	write(1, &(s->id), 1);
	write(1, "\n", 1);
}
