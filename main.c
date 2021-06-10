/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 17:25:40 by fbes          #+#    #+#                 */
/*   Updated: 2021/06/10 19:04:21 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static void	print_stacks(t_stack *a, t_stack *b)
{
	int			i;

	i = a->max - 1;
	while (i >= 0)
	{
		if (i < a->length)
			ft_putnbr_fd(a->stack[i], 1);
		else
			ft_putchar_fd(' ', 1);
		ft_putchar_fd(' ', 1);
		if (i < b->length)
			ft_putnbr_fd(b->stack[i], 1);
		else
			ft_putchar_fd(' ', 1);
		ft_putchar_fd('\n', 1);
		i--;
	}
	ft_putendl_fd("_ _", 1);
	ft_putendl_fd("a b", 1);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	int			i;

	a = new_stack('a', argc - 1);
	b = new_stack('b', argc - 1);
	if (a && b)
	{
		i = 1;
		while (i < argc)
		{
			a->stack[argc - i - 1] = ft_atoi(argv[i]);
			i++;
		}
		a->length = argc - 1;
		print_stack(a);
		print_stack(b);
	}
	free_stack(a);
	free_stack(b);
	exit(0);
	return (0);
}
