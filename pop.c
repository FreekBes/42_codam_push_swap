/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pop.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 18:58:53 by fbes          #+#    #+#                 */
/*   Updated: 2021/09/24 15:03:26 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

t_frame	*pop(t_stack *s)
{
	t_frame		*popped;

	if (s->top == NULL)
		return (NULL);
	popped = s->top;
	s->top = popped->next;
	s->size -= 1;
	return (popped);
}
