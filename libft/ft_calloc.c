/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 21:00:09 by fbes          #+#    #+#                 */
/*   Updated: 2021/10/30 00:12:14 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	size_t			size_to_malloc;

	if (nmemb == 0)
		nmemb = 1;
	if (size == 0)
		size = 1;
	size_to_malloc = size * nmemb;
	ptr = malloc(size_to_malloc);
	if (ptr)
		ft_bzero(ptr, size_to_malloc);
	return (ptr);
}
