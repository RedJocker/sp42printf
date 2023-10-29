/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:30:43 by maurodri          #+#    #+#             */
/*   Updated: 2023/10/23 16:45:34 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	helper(long long num, int fd)
{
	char	digit;

	if (num < 10)
	{
		digit = '0' + (char) num;
		write(fd, &digit, 1);
	}
	else
	{
		helper(num / 10, fd);
		helper(num % 10, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	num;

	num = (long long) n;
	if (num < 0)
	{
		write(fd, "-", 1);
		helper(-num, fd);
	}
	else
	{
		helper(num, fd);
	}
}
