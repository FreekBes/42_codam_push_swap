/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 17:41:49 by fbes          #+#    #+#                 */
/*   Updated: 2021/10/09 15:44:23 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	free_stack(t_stack *s)
{
	t_frame		*frame;
	t_frame		*next_frame;

	if (s)
	{
		frame = s->top;
		while (frame)
		{
			next_frame = frame->next;
			free(frame);
			frame = next_frame;
		}
		free(s);
		s = NULL;
	}
}

t_frame	*get_stack_biggest(t_stack *s)
{
	t_frame		*frame;
	t_frame		*biggest;

	frame = s->top;
	biggest = frame;
	while (frame)
	{
		if (frame->num >= biggest->num)
			biggest = frame;
		frame = frame->next;
	}
	return (biggest);
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

t_stack	*new_stack(char id)
{
	t_stack		*s;

	s = (t_stack *)malloc(sizeof(t_stack));
	if (s)
	{
		s->id = id;
		s->size = 0;
		s->top = NULL;
	}
	return (s);
}
