/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_sorted.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/24 18:21:19 by fbes          #+#    #+#                 */
/*   Updated: 2021/08/24 18:24:34 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *s, int dir)
{
	int		i;

	i = s->length - 1;
	if (dir > 0)
	{
		while (i >= 0)
		{
			if (s->stack[i - 1] < s->stack[i])
				return (0);
		}
	}
	else
	{
		while (i >= 0)
		{
			if (s->stack[i - 1] > s->stack[i])
				return (0);
		}
	}
	return (1);
}
