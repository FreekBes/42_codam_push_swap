/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pop.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 18:58:53 by fbes          #+#    #+#                 */
/*   Updated: 2021/06/10 18:59:51 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	pop(t_stack *s)
{
	if (s->length > 0)
	{
		s->stack[s->length - 1] = 0;
		s->length--;
	}
}
