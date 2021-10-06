/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 17:41:49 by fbes          #+#    #+#                 */
/*   Updated: 2021/10/06 22:12:24 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <limits.h>

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

void	free_stack(t_stack *s)
{
	t_frame		*frame;
	t_frame		*next_frame;

	if (s)
	{
		frame = s->top;
		while (frame)
		{
			next_frame = frame->next;
			free(frame);
			frame = next_frame;
		}
		free(s);
		s = NULL;
	}
}

t_frame	*get_stack_biggest(t_stack *s)
{
	t_frame		*frame;
	t_frame		*biggest;

	frame = s->top;
	biggest = frame;
	while (frame)
	{
		if (frame->num >= biggest->num)
			biggest = frame;
		frame = frame->next;
	}
	return (biggest);
}

t_frame	*get_stack_bottom(t_stack *s)
{
	t_frame		*frame;

	frame = s->top;
	while (frame->next)
		frame = frame->next;
	return (frame);
}

t_frame	*get_stack_frame(t_stack *s, int index)
{
	t_frame		*frame;
	int			j;

	if (index >= s->size)
		return (NULL);
	j = 0;
	frame = s->top;
	while (j < index && frame)
	{
		frame = frame->next;
		j++;
	}
	return (frame);
}

t_stack	*new_stack(char id)
{
	t_stack		*s;

	s = (t_stack *)malloc(sizeof(t_stack));
	if (s)
	{
		s->id = id;
		s->size = 0;
		s->top = NULL;
	}
	return (s);
}
