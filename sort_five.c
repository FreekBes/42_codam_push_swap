/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_five.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 12:51:24 by fbes          #+#    #+#                 */
/*   Updated: 2021/10/06 22:50:14 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	sort_five(t_stack *a, t_stack *b)
{
	int		steps_front;
	int		steps_back;
	int		steps_taken;
	t_frame	*frame;
	t_frame	*biggest;
	int		i;

	while (a->size > 3)
		pb(a, b);
	while (!is_sorted(a, 1))
		sort_three(a);
	ft_putendl_fd("sortfive", 1);
	print_stack(a);
	print_stack(b);
	steps_taken = 0;
	while (b->size > 0)
	{
		biggest = get_stack_biggest(a);
		ft_putstr_fd("biggest num in a: ", 1);
		ft_putnbr_fd(biggest->num, 1);
		ft_putchar_fd('\n', 1);
		if (biggest->num > b->top->num)
		{
			steps_front = 0;
			frame = a->top;
			// bug is probably in below line
			// debug with [5, 25, 6, 763, 2]
			// should check if number before it is actually smaller
			// is hard to do when it is the first number but the list needs
			// to be rotated because of steps_taken in the end...
			// plus frame->prev is sometimes NULL
			while (steps_front < a->size && b->top->num > frame->num) {
				frame = frame->next;
				steps_front++;
			}
			frame = get_stack_bottom(a);
			steps_back = 0;
			while (steps_back < a->size && b->top->num < frame->num)
			{
				frame = frame->prev;
				steps_back++;
			}
			ft_putstr_fd("steps_front: ", 1);
			ft_putnbr_fd(steps_front, 1);
			ft_putstr_fd("\nsteps_back: ", 1);
			ft_putnbr_fd(steps_back, 1);
			ft_putchar_fd('\n', 1);
			i = 0;
			while (steps_front <= steps_back && i < steps_front)
			{
				ra(a);
				i++;
				steps_taken++;
			}
			while (steps_front > steps_back && i < steps_back)
			{
				rra(a);
				i++;
				steps_taken--;
			}
			print_stack(a);
			print_stack(b);
			pa(a, b);
			print_stack(a);
			print_stack(b);
			ft_putstr_fd("steps_taken: ", 1);
			ft_putnbr_fd(steps_taken, 1);
			ft_putchar_fd('\n', 1);
		}
		else
		{
			pa(a, b);
			ra(a);
		}
	}
	while (steps_taken > 0)
	{
		ra(a);
		steps_taken--;
	}
	while (steps_taken < 0)
	{
		rra(a);
		steps_taken++;
	}
	debug_stack(a);
	debug_stack(b);


	/*
		if (get_stack_bottom(a)->num < b->top->num)
		{
			while (i < a->size)
			{
				ra(a);
				print_stack(a);
				i++;
			}
		}
		else
		{
			while (a->top->num < get_stack_bottom(b)->num)
			{
				ra(a);
				print_stack(a);
				i++;
			}
		}
		pa(a, b);
		print_stack(a);
	}
	while (i > 0)
	{
		rra(a);
		print_stack(a);
		i--;
	}
	*/
	exit(0);
}
