/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_sorted.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/24 18:21:19 by fbes          #+#    #+#                 */
/*   Updated: 2021/09/20 12:00:33 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// dir > 0: stack s is sorted 0 1 2
// dir <= 0: stack s is sorted 2 1 0

int	is_sorted(t_stack *s, int dir)
{
	int		i;

	i = 0;
	if (dir > 0)
	{
		while (i < s->length - 1)
		{
			if (s->stack[i] > s->stack[i + 1])
				return (0);
			i++;
		}
	}
	else
	{
		while (i < s->length - 1)
		{
			if (s->stack[i] < s->stack[i + 1])
				return (0);
			i++;
		}
	}
	return (1);
}
