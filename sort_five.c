/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_five.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 12:51:24 by fbes          #+#    #+#                 */
/*   Updated: 2021/10/05 22:37:56 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	sort_five(t_stack *a, t_stack *b)
{
	int		i;

	write(1, "sortfive", 8);
	while (a->size > 3)
		pb(a, b);
	while (!is_sorted(a, 1))
		sort_three(a);
	while (!is_sorted(b, 1))
		sort_three(b);
	print_stack(a);
	i = 0;
	while (b->size > 0)
	{
		if (get_stack_bottom(a)->num < b->top->num)
		{
			while (i < a->size)
			{
				ra(a);
				print_stack(a);
				i++;
			}
		}
		else
		{
			while (a->top->num < get_stack_bottom(b)->num)
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
