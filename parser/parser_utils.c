/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:51:58 by maurodri          #+#    #+#             */
/*   Updated: 2023/10/30 19:22:25 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_utils.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

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

int	find_ch_or_end_index(char *str, char ch)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ch)
	{
		i++;
	}
	return (i);
}
