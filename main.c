/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/10 17:25:40 by fbes          #+#    #+#                 */
/*   Updated: 2021/11/01 16:43:06 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	print_error(t_stack *a, t_stack *b)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
	return (0);
}

static int	parse_space_sep_str_err(t_stack *a, t_stack *b, char **spl)
{
	ft_free_double_ptr((void **)spl);
	return (print_error(a, b));
}

static int	parse_space_sep_str(t_stack *a, t_stack *b, char *s, int *n)
{
	char	**spl;
	int		i;

	spl = ft_split(s, ' ');
	if (!spl)
		return (print_error(a, b));
	i = 0;
	while (spl[i])
		i++;
	if (i == 0)
		return (parse_space_sep_str_err(a, b, spl));
	while (i > 0)
	{
		if (parse_num(a, n, spl[i - 1]) > 0)
			push(a, NULL, *n);
		else
			return (parse_space_sep_str_err(a, b, spl));
		i--;
	}
	ft_free_double_ptr((void **)spl);
	return (1);
}

static int	handle_argv(t_stack *a, t_stack *b, int argc, char **argv)
{
	int		i;
	int		n;

	i = argc - 1;
	while (i > 0)
	{
		if (ft_strchr(argv[i], ' '))
			parse_space_sep_str(a, b, argv[i], &n);
		else
		{
			if (parse_num(a, &n, argv[i]) > 0)
				push(a, NULL, n);
			else
				return (print_error(a, b));
		}
		i--;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;

	if (argc < 2)
		return (0);
	a = new_stack('a');
	b = new_stack('b');
	if (a && b)
	{
		handle_argv(a, b, argc, argv);
		sort(a, b);
	}
	free_stack(a);
	free_stack(b);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
