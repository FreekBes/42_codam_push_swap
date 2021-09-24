/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   num_handling.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/17 21:33:05 by fbes          #+#    #+#                 */
/*   Updated: 2021/09/24 15:49:10 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	is_dup(t_stack *s, int n)
{
	t_frame		*temp;

	temp = s->top;
	while (temp)
	{
		if (temp->num == n)
			return (1);
		temp = temp->next;
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
