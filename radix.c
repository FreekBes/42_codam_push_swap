/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 19:50:05 by fbes          #+#    #+#                 */
/*   Updated: 2021/10/28 20:09:07 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack *a, t_stack *b)
{
	int		size;
	int		i;
	int		j;
	int		num;

	size = a->size;
	i = 0;
	while (!is_sorted(a, 1))
	{
		j = 0;
		while (j < size)
		{
			num = a->top->id;
			if ((num >> i) & 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (b->size > 0)
			pa(a, b);
		i++;
	}
}
