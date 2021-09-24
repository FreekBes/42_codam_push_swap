/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/12 18:42:02 by fbes          #+#    #+#                 */
/*   Updated: 2021/09/25 00:38:25 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	int		writes;

	writes = 0;
	if (n == -2147483648)
		return (write(fd, "-2147483648", 11));
	if (n < 0)
	{
		writes += write(fd, "-", 1);
		n *= -1;
	}
	return (writes + ft_putnbr_base_fd((unsigned int)n, "0123456789", fd));
}
