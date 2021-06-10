/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 17:25:40 by fbes          #+#    #+#                 */
/*   Updated: 2021/06/10 18:29:08 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	int			i;

	a = new_stack('a', argc - 1);
	//b = new_stack('b', argc - 1);
	if (a)
	{
		i = 1;
		while (i < argc)
		{
			a->stack[argc - i - 1] = ft_atoi(argv[i]);
			i++;
		}
		a->length = argc - 1;
		print_stack(a);
		push(a, 42);
		print_stack(a);
		rotate(a);
		print_stack(a);
		reverse(a);
		print_stack(a);
		reverse(a);
		print_stack(a);
		reverse(a);
		print_stack(a);
		reverse(a);
		print_stack(a);
		reverse(a);
		print_stack(a);
	}
	free_stack(a);
	//free_stack(b);
	exit(0);
	return (0);
}
