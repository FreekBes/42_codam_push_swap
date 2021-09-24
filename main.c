/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 17:25:40 by fbes          #+#    #+#                 */
/*   Updated: 2021/09/24 16:40:08 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

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
	a = new_stack('a');
	b = new_stack('b');
	if (a && b)
	{
		i = 1;
		while (i < argc)
		{
			if (!ps_atoi(argv[i], &n))
				return (print_error(a, b));
			if (is_dup(a, n))
				return (print_error(a, b));
			push(a, n);
			i++;
		}
		debug_stack(a);
		debug_stack(b);
		while (operate(a, b))
			i++;
		debug_stack(a);
		debug_stack(b);
	}
	free_stack(a);
	free_stack(b);
	exit(0);
	return (0);
}
