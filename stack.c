/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 17:41:49 by fbes          #+#    #+#                 */
/*   Updated: 2021/10/17 19:08:50 by fbes          ########   odam.nl         */
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
