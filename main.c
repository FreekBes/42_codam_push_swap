/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 17:25:40 by fbes          #+#    #+#                 */
/*   Updated: 2021/10/09 15:14:36 by fbes          ########   odam.nl         */
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

static int	parse_num(t_stack *a, int *n, char *s, int free_after)
{
	if (ft_strlen(s) == 0)
		return (-1);
	if (!ps_atoi(s, n))
		return (-1);
	if (is_dup(a, *n))
		return (-1);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	char		**spl;
	int			i;
	int			j;
	int			n;

	if (argc < 2)
		return (print_error(NULL, NULL));
	a = new_stack('a');
	b = new_stack('b');
	if (a && b)
	{
		i = argc - 1;
		while (i > 0)
		{
			if (ft_strchr(argv[i], ' '))
			{
				spl = ft_split(argv[i], ' ');
				if (!spl)
					return (print_error(a, b));
				j = 0;
				while (spl[j])
					j++;
				if (j == 0)
				{
					ft_free_double_ptr((void **)spl);
					return (print_error(a, b));
				}
				while (j > 0)
				{
					if (parse_num(a, &n, spl[j - 1], 0) > 0)
						push(a, n);
					else
					{
						ft_free_double_ptr((void **)spl);
						return (print_error(a, b));
					}
					j--;
				}
				ft_free_double_ptr((void **)spl);
			}
			else
			{
				if (parse_num(a, &n, argv[i], 0) > 0)
					push(a, n);
				else
					return (print_error(a, b));
			}
			i--;
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
