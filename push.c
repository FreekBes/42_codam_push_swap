/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 18:41:53 by fbes          #+#    #+#                 */
/*   Updated: 2021/11/01 19:25:07 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/**
 * Add a link or a number to the top of a stack
 * @param t_stack *s:	The stack to add the link to
 * @param t_link *link:	The link to add, can be NULL
 * @param int n:		The number to add to the stack in case *link == NULL
 * @return int:			Returns 1 on success, 0 on failure
 */
void	push(t_stack *s, t_link *link, int n)
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

/**
 * Push the top from stack a to stack B and print pa
 * @param t_stack *a:	The stack to push to
 * @param t_stack *b:	The stack to pop from
 */
void	pa(t_stack *a, t_stack *b)
{
	if (b->size > 0)
	{
		push(a, pop(b), -1);
		write(1, "pa\n", 3);
	}
}

/**
 * Push the top from stack a to stack B and print pb
 * @param t_stack *a:	The stack to pop from
 * @param t_stack *b:	The stack to push to
 */
void	pb(t_stack *a, t_stack *b)
{
	if (a->size > 0)
	{
		push(b, pop(a), -1);
		write(1, "pb\n", 3);
	}
}

/**
 * Push the top from one stack to the other stack and print p<s2->id>
 * @param t_stack *s1:	The stack to pop from
 * @param t_stack *s2:	The stack to push to
 */
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

/**
 * Push the smallest link from stack a to stack b with the least amount of steps
 * @param t_stack *a:	Stack A to pop from
 * @param t_stack *b:	Stack B to push to
 */
void	push_smallest_to_b(t_stack *a, t_stack *b)
{
	t_link	*smallest;
	int		steps;

	if (a->size < 1)
		return ;
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
