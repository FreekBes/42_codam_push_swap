/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_five.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 12:51:24 by fbes          #+#    #+#                 */
/*   Updated: 2021/10/27 18:58:55 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	push_smallest_to_b(t_stack *a, t_stack *b)
{
	t_link	*smallest;
	int		steps;

	smallest = get_stack_smallest(a);
	steps = get_min_steps_to_reach(a, smallest);
	if (steps > 0)
	{
		while (steps > 0)
		{
			ra(a);
			steps--;
		}
	}
	else if (steps < 0)
	{
		while (steps < 0)
		{
			rra(a);
			steps++;
		}
	}
	pb(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	while (a->size > 3)
		push_smallest_to_b(a, b);
	while (!is_sorted(a, 1))
		sort_three(a);
	while (b->size > 0)
		pa(a, b);
}
