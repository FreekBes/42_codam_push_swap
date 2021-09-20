/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 18:41:51 by fbes          #+#    #+#                 */
/*   Updated: 2021/09/20 12:05:37 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <unistd.h>

void	rotate(t_stack *s)
{
	int		temp;

	if (s->length > 1)
	{
		temp = s->stack[s->length - 1];
		ft_memmove(&(s->stack[1]), s->stack, sizeof(int) * (s->length - 1));
		s->stack[0] = temp;
	}
}

void	ra(t_stack *a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

void	rf(t_stack *s)
{
	rotate(s);
	write(1, "r", 1);
	write(1, &(s->id), 1);
	write(1, "\n", 1);
}
