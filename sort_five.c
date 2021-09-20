/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_five.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 12:51:24 by fbes          #+#    #+#                 */
/*   Updated: 2021/09/20 13:21:51 by fbes          ########   odam.nl         */
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
		pa(a, b);
		// still need to figure out how to put the number from b
		// at the right spot in a
		print_stack(a);
		if (a->stack[a->length - 1] > a->stack[a->length - 2])
			ra(a);
	}
	print_stack(a);
	exit(0);
}
