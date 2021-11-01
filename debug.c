/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/09 15:42:21 by fbes          #+#    #+#                 */
/*   Updated: 2021/11/01 21:47:58 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

/**
 * Print a stack on one line, only the numbers
 * @param *s	The stack to print
 */
void	print_stack(t_stack *s)
{
	t_link		*link;

	ft_putchar_fd(s->id, 1);
	ft_putstr_fd(" TOP (SMALLEST) [", 1);
	link = s->top;
	while (link)
	{
		ft_putnbr_fd(link->num, 1);
		if (link->next)
			ft_putstr_fd(", ", 1);
		link = link->next;
	}
	ft_putendl_fd("] BOTTOM (BIGGEST)", 1);
}

/**
 * Prints one link in a stack on one line
 * @param *f	The link to print
 */
static void	print_link(t_link *f)
{
	ft_putstr_fd("num: ", 1);
	ft_putnbr_fd(f->num, 1);
	ft_putstr_fd(", id: ", 1);
	ft_putnbr_fd(f->id, 1);
	ft_putstr_fd(", prev: 0x", 1);
	ft_putnbr_base_fd((unsigned int)(f->prev), "0123456789ABCDEF", 1);
	ft_putstr_fd(", next: 0x", 1);
	ft_putnbr_base_fd((unsigned int)(f->next), "0123456789ABCDEF", 1);
	ft_putchar_fd('\n', 1);
}

/**
 * Prints a lot of information on a stack in order to debug stuff
 * @param *s	The stack to print
 */
void	debug_stack(t_stack *s)
{
	t_link		*link;
	int			i;

	ft_putstr_fd("====================\nDEBUG STACK ", 1);
	ft_putchar_fd(s->id, 1);
	ft_putchar_fd('\n', 1);
	link = s->top;
	i = 0;
	while (link)
	{
		ft_putstr_fd("index ", 1);
		ft_putnbr_fd(i, 1);
		ft_putstr_fd(", ptr 0x", 1);
		ft_putnbr_base_fd((unsigned int)(link), "0123456789ABCDEF", 1);
		ft_putstr_fd("; ", 1);
		print_link(link);
		link = link->next;
		i++;
		if (i > s->size)
		{
			ft_putendl_fd("[WARNING] LINKED LIST RELINKS!!", 1);
			break ;
		}
	}
	ft_putendl_fd("====================\n", 1);
}
