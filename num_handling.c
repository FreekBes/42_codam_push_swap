/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   num_handling.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/17 21:33:05 by fbes          #+#    #+#                 */
/*   Updated: 2021/10/27 18:58:55 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	is_dup(t_stack *s, int n)
{
	t_link		*temp;

	temp = s->top;
	while (temp)
	{
		if (temp->num == n)
			return (1);
		temp = temp->next;
	}
	return (0);
}

static int	ps_atoi(char *s, int *n)
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

int	parse_num(t_stack *a, int *n, char *s)
{
	if (ft_strlen(s) == 0)
		return (-1);
	if (!ps_atoi(s, n))
		return (-1);
	if (is_dup(a, *n))
		return (-1);
	return (1);
}
