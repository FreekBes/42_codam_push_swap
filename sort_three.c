/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_three.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/24 17:59:05 by fbes          #+#    #+#                 */
/*   Updated: 2021/10/05 22:55:01 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *s)
{
	int		n1;
	int		n2;
	int		n3;

	debug_stack(s);
	if (s->size != 3)
		return ;
	n1 = s->top->num;
	n2 = s->top->next->num;
	n3 = s->top->next->next->num;
	if (n1 > n2 && n2 < n3 && n3 > n1)
		sf(s);
	else if (n1 > n2 && n2 > n3 && n3 < n1)
		sf(s);
	else if (n1 > n2 && n2 < n3 && n3 < n1)
		ra(s);
	else if (n1 < n2 && n2 > n3 && n3 > n1)
		sf(s);
	else if (n1 < n2 && n2 > n3 && n3 < n1)
		rrf(s);
}
