/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presenter_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:03:49 by maurodri          #+#    #+#             */
/*   Updated: 2023/11/27 16:06:01 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presenter_utils_bonus.h"

static void	nbr_helper(long long num, int fd)
{
	char	digit;

	if (num < 10)
	{
		digit = '0' + (char) num;
		write(fd, &digit, 1);
	}
	else
	{
		nbr_helper(num / 10, fd);
		nbr_helper(num % 10, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	num;

	num = (long long) n;
	if (num < 0)
	{
		write(fd, "-", 1);
		nbr_helper(-num, fd);
	}
	else
	{
		nbr_helper(num, fd);
	}
}

int	ft_putunbr_fd(unsigned int num, int fd)
{
	char	digit;
	int		size;

	size = 0;
	if (num < 10)
	{
		digit = '0' + (char) num;
		write(fd, &digit, 1);
		size++;
	}
	else
	{
		size += ft_putunbr_fd(num / 10, fd);
		size += ft_putunbr_fd(num % 10, fd);
	}
	return (size);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}
