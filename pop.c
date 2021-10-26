/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pop.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 18:58:53 by fbes          #+#    #+#                 */
/*   Updated: 2021/10/26 22:08:56 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

t_frame	*pop(t_stack *s)
{
	t_frame		*popped;

	if (s->top == NULL)
		return (NULL);
	popped = s->top;
	s->top = popped->next;
	s->size -= 1;
	if (s->top)
		s->top->prev = NULL;
	return (popped);
}
