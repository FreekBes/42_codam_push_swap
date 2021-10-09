/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_double_ptr.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/31 19:45:17 by fbes          #+#    #+#                 */
/*   Updated: 2021/10/09 15:05:48 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_free_double_ptr(void **freeable)
{
	int		i;

	if (freeable)
	{
		i = 0;
		while (freeable[i])
		{
			free(freeable[i]);
			i++;
		}
		free(freeable);
	}
	freeable = NULL;
	return (NULL);
}
