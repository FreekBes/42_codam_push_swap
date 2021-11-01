/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pop.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 18:58:53 by fbes          #+#    #+#                 */
/*   Updated: 2021/11/01 19:12:16 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "push_swap.h"

/**
 * Remove the top link from the stack and then returns said link
 * @param t_stack *s:	The stack to remove the top link of
 * @return t_link*:		The removed link
 */
t_link	*pop(t_stack *s)
{
	t_link		*popped;

	if (s->top == NULL)
		return (NULL);
	popped = s->top;
	s->top = popped->next;
	s->size -= 1;
	if (s->top)
		s->top->prev = NULL;
	return (popped);
}
