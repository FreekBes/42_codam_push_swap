/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 18:40:34 by fbes          #+#    #+#                 */
/*   Updated: 2021/10/28 20:29:50 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

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
