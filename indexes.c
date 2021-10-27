/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   indexes.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/27 19:17:33 by fbes          #+#    #+#                 */
/*   Updated: 2021/10/27 20:09:42 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	index_next(const int i, t_stack *s)
{
	t_link	*current;
	t_link	*smallest;
	t_link	*biggest;

	smallest = NULL;
	biggest = NULL;
	current = s->top;
	while (current)
	{
		if (current->id > -1)
		{
			current = current->next;
			continue ;
		}
		if (!smallest || current->num < smallest->num)
			smallest = current;
		if (!biggest || current->num > biggest->num)
			biggest = current;
		current = current->next;
	}
	smallest->id = i;
	biggest->id = s->size - i - 1;
}

void	index_stack(t_stack *s)
{
	int		i;
	int		to;

	i = 0;
	to = s->size * 0.5 + s->size % 2;
	while (i < to)
	{
		index_next(i, s);
		i++;
	}
}
