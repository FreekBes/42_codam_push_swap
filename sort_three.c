/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_three.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/24 17:59:05 by fbes          #+#    #+#                 */
/*   Updated: 2021/09/20 12:54:40 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *s)
{
	if (s->stack[2] > s->stack[1] && s->stack[1] < s->stack[0] && s->stack[0] > s->stack[2])
		sf(s);
	else if (s->stack[2] > s->stack[1] && s->stack[1] > s->stack[0] && s->stack[0] < s->stack[2])
		sf(s);
	else if (s->stack[2] > s->stack[1] && s->stack[1] < s->stack[0] && s->stack[0] < s->stack[2])
		rf(s);
	else if (s->stack[2] < s->stack[1] && s->stack[1] > s->stack[0] && s->stack[0] > s->stack[2])
		sf(s);
	else if (s->stack[2] < s->stack[1] && s->stack[1] > s->stack[0] && s->stack[0] < s->stack[2])
		rrf(s);
}
