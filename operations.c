/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 17:38:53 by fbes          #+#    #+#                 */
/*   Updated: 2021/06/10 18:28:37 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <unistd.h>

void	swap(t_stack *s)
{
	int		temp;

	if (s->length > 1)
	{
		temp = s->stack[0];
		s->stack[0] = s->stack[1];
		s->stack[1] = temp;
		write(1, "s", 1);
		write(1, &s->id, 1);
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
