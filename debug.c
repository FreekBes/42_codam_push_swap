/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/09 15:42:21 by fbes          #+#    #+#                 */
/*   Updated: 2021/10/09 15:43:08 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	print_stack(t_stack *s)
{
	t_frame		*frame;

	ft_putchar_fd(s->id, 1);
	ft_putstr_fd(" TOP (SMALLEST) [", 1);
	frame = s->top;
	while (frame)
	{
		ft_putnbr_fd(frame->num, 1);
		if (frame->next)
			ft_putstr_fd(", ", 1);
		frame = frame->next;
	}
	ft_putendl_fd("] BOTTOM (BIGGEST)", 1);
}

static void	print_frame(t_frame *f)
{
	ft_putstr_fd("num: ", 1);
	ft_putnbr_fd(f->num, 1);
	ft_putstr_fd(", prev: 0x", 1);
	ft_putnbr_base_fd((unsigned int)(f->prev), "0123456789ABCDEF", 1);
	ft_putstr_fd(", next: 0x", 1);
	ft_putnbr_base_fd((unsigned int)(f->next), "0123456789ABCDEF", 1);
	ft_putchar_fd('\n', 1);
}

void	debug_stack(t_stack *s)
{
	t_frame		*frame;
	int			i;

	ft_putendl_fd("====================", 1);
	ft_putstr_fd("DEBUG STACK ", 1);
	ft_putchar_fd(s->id, 1);
	ft_putchar_fd('\n', 1);
	frame = s->top;
	i = 0;
	while (frame)
	{
		ft_putstr_fd("index ", 1);
		ft_putnbr_fd(i, 1);
		ft_putstr_fd(", ptr 0x", 1);
		ft_putnbr_base_fd((unsigned int)(frame), "0123456789ABCDEF", 1);
		ft_putstr_fd("; ", 1);
		print_frame(frame);
		frame = frame->next;
		i++;
		if (i > s->size)
		{
			ft_putendl_fd("WARNING: LINKED LIST RELINKS!!", 1);
			break ;
		}
	}
	ft_putendl_fd("====================\n", 1);
}
