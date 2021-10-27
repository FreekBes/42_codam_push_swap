/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_sorted.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/24 18:21:19 by fbes          #+#    #+#                 */
/*   Updated: 2021/10/27 18:58:55 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// dir > 0: stack s is sorted 0 1 2
// dir <= 0: stack s is sorted 2 1 0

int	is_sorted(t_stack *s, int dir)
{
	t_link		*frame;

	if (s->size < 2)
		return (1);
	frame = s->top;
	if (dir > 0)
	{
		while (frame->next)
		{
			if (frame->next->num < frame->num)
				return (0);
			frame = frame->next;
		}
	}
	else
	{
		while (frame->next)
		{
			if (frame->next->num > frame->num)
				return (0);
			frame = frame->next;
		}
	}
	return (1);
}
