/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_three.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/24 17:59:05 by fbes          #+#    #+#                 */
/*   Updated: 2021/09/24 16:39:34 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	sort_three(t_stack *s)
{
	int		n0;
	int		n1;
	int		n2;

	ft_putstr_fd("three ", 1);
	debug_stack(s);
	if (s->size != 3)
		return ;
	n0 = s->top->num;
	n1 = s->top->next->num;
	n2 = s->top->next->next->num;
	if (n2 > n1 && n1 < n0 && n0 > n2)
		sf(s);
	else if (n2 > n1 && n1 > n0 && n0 < n2)
		sf(s);
	else if (n2 > n1 && n1 < n0 && n0 < n2)
		rrf(s);
	else if (n2 < n1 && n1 > n0 && n0 > n2)
		sf(s);
	else if (n2 < n1 && n1 > n0 && n0 < n2)
		rf(s);
}
