/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   num_handling.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/17 21:33:05 by fbes          #+#    #+#                 */
/*   Updated: 2021/11/01 20:58:16 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

/**
 * Checks if a number is already in the stack
 * @param t_stack *s:	The stack to check
 * @param int n:		The number to check for
 */
static int	is_dup(t_stack *s, int n)
{
	t_link	*temp;

	temp = s->top;
	while (temp)
	{
		if (temp->num == n)
			return (1);
		temp = temp->next;
	}
	return (0);
}

/**
 * Below method is ft_atoi but modified for push_swap, where it can parse a
 * number outside of int's range, but should return an error then
 * @param char *s:	The string to parse
 * @param int *n:	The int to parse to
 * @return int:		Returns 1 on success, 0 on failure
 */
static int	ps_atoi(char *s, int *n)
{
	long	num;
	int		neg;
	int		i;

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

/**
 * Parse a number and check for errors
 * @param t_stack *a:	The stack to check for the number to add (no duplicates)
 * @param int *n:		The number to parse to
 * @param char *s:		The string to parse
 * @return int:			Returns 1 on success, -1 on failure
 */
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

/**
 * Check if a string consists only of spaces
 * @param char *s:	The string to check
 * @return int:		Returns 1 if only spaces, 0 if not
 */
int	only_spaces(const char *s)
{
	while (*s == ' ')
		s++;
	if (*s == '\0')
		return (1);
	return (0);
}
