/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 17:25:40 by fbes          #+#    #+#                 */
/*   Updated: 2021/09/20 12:55:14 by fbes          ########   odam.nl         */
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

static int	print_error(t_stack *a, t_stack *b)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	write(2, "Error\n", 6);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	int			i;
	int			n;

	if (argc < 2)
		return (print_error(NULL, NULL));
	a = new_stack('a', argc - 1);
	b = new_stack('b', argc - 1);
	if (a && b)
	{
		i = 1;
		while (i < argc)
		{
			if (!ps_atoi(argv[i], &n))
				return (print_error(a, b));
			if (is_dup(a, n))
				return (print_error(a, b));
			a->stack[argc - i - 1] = n;
			(a->length)++;
			i++;
		}
		print_stack(a);
		print_stacks(a, b);
		while (operate(a, b))
			i++;
		print_stacks(a, b);
		print_stack(b);
	}
	free_stack(a);
	free_stack(b);
	exit(0);
	return (0);
}
