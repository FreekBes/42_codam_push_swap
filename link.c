/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   link.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/17 19:08:20 by fbes          #+#    #+#                 */
/*   Updated: 2021/10/17 19:09:00 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "push_swap.h"

/**
 * Get the biggest link in a stack
 * @param t_stack *s:	The stack to check
 * @return t_link*:		The smallest link
 */
t_link	*get_stack_biggest(t_stack *s)
{
	t_link		*link;
	t_link		*biggest;

	link = s->top;
	biggest = link;
	while (link)
	{
		if (link->num > biggest->num)
			biggest = link;
		link = link->next;
	}
	return (biggest);
}

/**
 * Get the smallest link in a stack
 * @param t_stack *s:	The stack to check
 * @return t_link*:		The biggest link
 */
t_link	*get_stack_smallest(t_stack *s)
{
	t_link		*link;
	t_link		*smallest;

	link = s->top;
	smallest = link;
	while (link)
	{
		if (link->num < smallest->num)
			smallest = link;
		link = link->next;
	}
	return (smallest);
}

/**
 * Get the minimum required steps to reach a link
 * @param t_stack *s:	The stack to check in
 * @param t_link *f:	The link to search for in t_stack *s
 * @return int:			The amount of steps required to reach t_link *f,
 * 						is positive if steps are from the top of the stack,
 * 						is negative if steps are from the back of the stack
 */
int	get_min_steps_to_reach(t_stack *s, t_link *f)
{
	t_link		*temp;
	int			steps_front;
	int			steps_back;

	steps_front = 0;
	temp = s->top;
	while (temp && temp != f)
	{
		steps_front++;
		temp = temp->next;
	}
	steps_back = 1;
	temp = get_stack_bottom(s);
	while (temp && temp != f)
	{
		steps_back++;
		temp = temp->prev;
	}
	if (steps_front < steps_back)
		return (steps_front);
	else
		return (-steps_back);
}

/**
 * Get the bottom of a stack
 * @param t_stack *s:	The stack to get the bottom of
 * @return t_link*:		The bottom link of the stack
 */
t_link	*get_stack_bottom(t_stack *s)
{
	t_link		*link;

	link = s->top;
	while (link->next)
		link = link->next;
	return (link);
}

/**
 * Get a link from a stack based on its index number (iterative index, not id)
 * @param t_stack *s:	The stack to iterate over
 * @param int index:	The index at which to return the link
 * @return t_link*:		The link at that index
 */
t_link	*get_stack_link(t_stack *s, int index)
{
	t_link		*link;
	int			j;

	if (index >= s->size)
		return (NULL);
	j = 0;
	link = s->top;
	while (j < index && link)
	{
		link = link->next;
		j++;
	}
	return (link);
}
