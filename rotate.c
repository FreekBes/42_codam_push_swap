/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 18:41:51 by fbes          #+#    #+#                 */
/*   Updated: 2021/09/24 16:36:34 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <unistd.h>

void	rotate(t_stack *s)
{
	t_frame		*temp;

	if (s->size > 1)
	{
		temp = s->top;
		s->top = temp->next;
		temp->next = NULL;
		get_stack_bottom(s)->next = temp;
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
