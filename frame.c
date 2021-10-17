/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frame.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/17 19:08:20 by fbes          #+#    #+#                 */
/*   Updated: 2021/10/17 19:09:00 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_frame	*get_stack_biggest(t_stack *s)
{
	t_frame		*frame;
	t_frame		*biggest;

	frame = s->top;
	biggest = frame;
	while (frame)
	{
		if (frame->num > biggest->num)
			biggest = frame;
		frame = frame->next;
	}
	return (biggest);
}

t_frame	*get_stack_smallest(t_stack *s)
{
	t_frame		*frame;
	t_frame		*smallest;

	frame = s->top;
	smallest = frame;
	while (frame)
	{
		if (frame->num < smallest->num)
			smallest = frame;
		frame = frame->next;
	}
	return (smallest);
}

int	get_min_steps_to_reach(t_stack *s, t_frame *f)
{
	t_frame		*temp;
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

t_frame	*get_stack_bottom(t_stack *s)
{
	t_frame		*frame;

	frame = s->top;
	while (frame->next)
		frame = frame->next;
	return (frame);
}

t_frame	*get_stack_frame(t_stack *s, int index)
{
	t_frame		*frame;
	int			j;

	if (index >= s->size)
		return (NULL);
	j = 0;
	frame = s->top;
	while (j < index && frame)
	{
		frame = frame->next;
		j++;
	}
	return (frame);
}
