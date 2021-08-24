/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/24 17:59:05 by fbes          #+#    #+#                 */
/*   Updated: 2021/08/24 18:32:43 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	operate(t_stack *a, t_stack *b)
{
	int		i;

	// if a is empty, or contains 1 number while b contains 0, exit
	if (a->length == 0 || (a->length == 1 && b->length == 0))
		return (0);
	i = a->length - 1;
	// while i is at least 0, and stack a appears sorted, do i--
	while (i >= 0 && a->stack[i - 1] > a->stack[i])
		i--;
	// if we got to index 0, a is sorted. exit
	if (i == 0)
		return (0);
	// if not, push to b until we reach the (former) top
	while (i < a->length - 1)
	{
		pb(a, b);
		i++;
	}
	// then swap a
	sa(a);
	// check if


	// yeah nvm I hate this, I'll just do something else for now
	return (1);
}
