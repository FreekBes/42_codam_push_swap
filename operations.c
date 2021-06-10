/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 17:38:53 by fbes          #+#    #+#                 */
/*   Updated: 2021/06/10 18:38:13 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <unistd.h>

static void	print_op(char *op, char id)
{
	write(1, op, ft_strlen(op));
	write(1, &id, 1);
	write(1, "\n", 1);
}

void	swap(t_stack *s)
{
	int		temp;

	if (s->length > 1)
	{
		temp = s->stack[0];
		s->stack[0] = s->stack[1];
		s->stack[1] = temp;
	}
}

void	push(t_stack *s, int n)
{
	ft_memmove(&(s->stack[1]), s->stack, sizeof(int) * (s->max - 1));
	s->stack[0] = n;
	if (s->length < s->max)
		s->length++;
}

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
