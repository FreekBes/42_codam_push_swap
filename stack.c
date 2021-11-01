/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 17:41:49 by fbes          #+#    #+#                 */
/*   Updated: 2021/11/01 21:45:46 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

/**
 * Free a stack and all of its links, then set it to NULL
 * @param *s	The stack to free
 */
void	free_stack(t_stack *s)
{
	t_link		*link;
	t_link		*next_link;

	if (s)
	{
		link = s->top;
		while (link)
		{
			next_link = link->next;
			free(link);
			link = next_link;
		}
		free(s);
		s = NULL;
	}
}

/**
 * Allocate and populate a new stack
 * @param id	The stack's ID (usually 'a' or 'b')
 * @return		A pointer to the created stack
 */
t_stack	*new_stack(char id)
{
	t_stack		*s;

	s = (t_stack *)malloc(sizeof(t_stack));
	if (s)
	{
		s->id = id;
		s->size = 0;
		s->top = NULL;
	}
	return (s);
}
