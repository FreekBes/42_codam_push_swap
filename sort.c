/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 10:55:00 by fbes          #+#    #+#                 */
/*   Updated: 2021/09/20 12:14:27 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int	operate(t_stack *a, t_stack *b)
{
	if (b->length == 0 && is_sorted(a, 0))
		return (0);
	if (a->length == 3)
		sort_three(a);
	else if (a->length == 5)
		sort_five(a, b);
	return (1);
}
