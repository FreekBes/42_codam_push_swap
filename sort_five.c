/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_five.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 12:51:24 by fbes          #+#    #+#                 */
/*   Updated: 2021/09/20 17:02:38 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	sort_five(t_stack *a, t_stack *b)
{
	int		i;

	while (a->length > 3)
		pb(a, b);
	while (!is_sorted(a, 0))
		sort_three(a);
	while (!is_sorted(b, 0))
		sort_three(b);
	print_stack(a);
	i = 0;
	while (b->length > 0)
	{
		if (a->stack[0] < b->stack[b->length - 1])
		{
			while (i < a->length)
			{
				ra(a);
				print_stack(a);
				i++;
			}
		}
		else
		{
			while (a->stack[a->length - 1] < b->stack[b->length - 1])
			{
				ra(a);
				print_stack(a);
				i++;
			}
		}
		pa(a, b);
		print_stack(a);
	}
	while (i > 0)
	{
		rra(a);
		print_stack(a);
		i--;
	}
	exit(0);
}
