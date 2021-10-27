/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 18:41:49 by fbes          #+#    #+#                 */
/*   Updated: 2021/10/27 19:00:07 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <unistd.h>

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

void	rra(t_stack *a)
{
	reverse(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	reverse(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse(a);
	reverse(b);
	write(1, "rrr\n", 4);
}

void	rrf(t_stack *s)
{
	reverse(s);
	write(1, "rr", 2);
	write(1, &(s->id), 1);
	write(1, "\n", 1);
}
