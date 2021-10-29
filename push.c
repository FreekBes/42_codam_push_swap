/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 18:41:53 by fbes          #+#    #+#                 */
/*   Updated: 2021/10/29 20:13:01 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	push(t_stack *s, t_link *link, int n)
{
	if (!link)
	{
		link = malloc(sizeof(t_link));
		if (link)
		{
			link->num = n;
			link->id = -1;
		}
	}
	if (link)
	{
		link->next = s->top;
		link->prev = NULL;
		if (s->top != NULL)
			s->top->prev = link;
		s->top = link;
		s->size += 1;
		return (1);
	}
	return (0);
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->size > 0)
	{
		push(a, pop(b), -1);
		write(1, "pa\n", 3);
	}
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->size > 0)
	{
		push(b, pop(a), -1);
		write(1, "pb\n", 3);
	}
}

void	pf(t_stack *s1, t_stack *s2)
{
	if (s1->size > 0)
	{
		push(s2, pop(s1), -1);
		write(1, "p", 1);
		write(1, &(s2->id), 1);
		write(1, "\n", 1);
	}
}

void	push_smallest_to_b(t_stack *a, t_stack *b)
{
	t_link	*smallest;
	int		steps;

	smallest = get_stack_smallest(a);
	steps = get_min_steps_to_reach(a, smallest);
	if (steps > 0)
	{
		while (steps > 0)
		{
			ra(a);
			steps--;
		}
	}
	else if (steps < 0)
	{
		while (steps < 0)
		{
			rra(a);
			steps++;
		}
	}
	pb(a, b);
}
