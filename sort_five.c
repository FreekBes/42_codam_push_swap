/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_five.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 12:51:24 by fbes          #+#    #+#                 */
/*   Updated: 2021/09/20 13:34:53 by fbes          ########   odam.nl         */
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
	print_stack(a);
	while (b->length > 0)
	{
		i = 0;
		while (a->stack[a->length - 1] < b->stack[b->length - 1])
		{
			ra(a);
			i++;
		}
		pa(a, b);
		print_stack(a);
		while (i > 0)
		{
			rra(a);
			i--;
		}
	}
	print_stack(a);
	exit(0);
}
