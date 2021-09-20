/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 18:41:49 by fbes          #+#    #+#                 */
/*   Updated: 2021/09/20 12:05:02 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <unistd.h>

void	reverse(t_stack *s)
{
	int		temp;

	if (s->length > 1)
	{
		temp = s->stack[0];
		ft_memmove(s->stack, &(s->stack[1]), sizeof(int) * (s->length - 1));
		s->stack[s->length - 1] = temp;
	}
}

void	rra(t_stack *a)
{
	reverse(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	reverse(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse(a);
	reverse(b);
	write(1, "rrr\n", 4);
}

void	rrf(t_stack *s)
{
	reverse(s);
	write(1, "rr", 2);
	write(1, &(s->id), 1);
	write(1, "\n", 1);
}
