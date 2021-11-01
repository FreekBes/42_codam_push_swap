/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_sorted.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/24 18:21:19 by fbes          #+#    #+#                 */
/*   Updated: 2021/11/01 16:55:41 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * dir > 0: stack s is sorted 0 1 2
 * dir <= 0: stack s is sorted 2 1 0
 */

int	is_sorted(t_stack *s, int dir)
{
	t_link		*link;

	if (s->size < 2)
		return (1);
	link = s->top;
	if (dir > 0)
	{
		while (link->next)
		{
			if (link->next->num < link->num)
				return (0);
			link = link->next;
		}
	}
	else
	{
		while (link->next)
		{
			if (link->next->num > link->num)
				return (0);
			link = link->next;
		}
	}
	return (1);
}
