/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   num_handling.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/17 21:33:05 by fbes          #+#    #+#                 */
/*   Updated: 2021/09/20 12:00:33 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	is_dup(t_stack *s, int n)
{
	int		i;

	i = s->max - 1;
	while (i >= s->max - s->length)
	{
		if (n == s->stack[i])
			return (1);
		i--;
	}
	return (0);
}

int	ps_atoi(char *s, int *n)
{
	long long	num;
	int			neg;
	int			i;

	num = 0;
	neg = 1;
	i = 0;
	while (s[i])
	{
		if (i == 0 && s[i] == '-')
			neg = -1;
		else if (s[i] >= '0' && s[i] <= '9')
			num = num * 10 + ((int)s[i] - '0');
		else
			return (0);
		if ((neg == -1 && num > 2147483648) || (neg == 1 && num > 2147483647))
			return (0);
		i++;
	}
	*n = (int)(num * neg);
	return (1);
}
