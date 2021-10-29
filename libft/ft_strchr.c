/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 19:47:41 by fbes          #+#    #+#                 */
/*   Updated: 2021/10/30 00:07:28 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char)c;
	while (*s != '\0' || ch == '\0')
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
