/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pop.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 18:58:53 by fbes          #+#    #+#                 */
/*   Updated: 2021/10/28 20:28:35 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "push_swap.h"

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
