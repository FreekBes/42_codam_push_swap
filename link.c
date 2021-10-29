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

t_link	*get_stack_biggest(t_stack *s)
{
	t_link		*link;
	t_link		*biggest;

	link = s->top;
	biggest = link;
	while (link)
	{
		if (link->id > biggest->id)
			biggest = link;
		link = link->next;
	}
	return (biggest);
}

t_link	*get_stack_smallest(t_stack *s)
{
	t_link		*link;
	t_link		*smallest;

	link = s->top;
	smallest = link;
	while (link)
	{
		if (link->id < smallest->id)
			smallest = link;
		link = link->next;
	}
	return (smallest);
}

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

t_link	*get_stack_bottom(t_stack *s)
{
	t_link		*link;

	link = s->top;
	while (link->next)
		link = link->next;
	return (link);
}

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
