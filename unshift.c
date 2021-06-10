/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unshift.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 18:48:12 by fbes          #+#    #+#                 */
/*   Updated: 2021/06/10 18:51:57 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	unshift(t_stack *s, int n)
{
	ft_memmove(&(s->stack[1]), s->stack, sizeof(int) * (s->max - 1));
	s->stack[0] = n;
	if (s->length < s->max)
		s->length++;
}
