/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presenter_utils2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:04:23 by maurodri          #+#    #+#             */
/*   Updated: 2023/12/13 20:24:37 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presenter_utils_bonus.h"
#include <stdlib.h>

int	ft_putnbr_hex(unsigned long long nbr, char *hexbase)
{
	char	digit;
	int		size;

	if (nbr == 0)
		return (write(1, "0", 1));
	size = 0;
	if (nbr >= 16)
	{
		size += ft_putnbr_hex(nbr / 16, hexbase);
		size += ft_putnbr_hex(nbr % 16, hexbase);
	}
	else
	{
		digit = hexbase[nbr];
		size += write(1, &digit, 1);
	}
	return (size);
}

void	fill_string(char *str, char filler, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
		str[i++] = filler;
}

int	hex_num_size(unsigned long long nbr)
{
	int	size;

	size = 0;
	if (nbr == 0)
		size = 1;
	else
		while (nbr != 0)
			nbr /= 16 + (0 * size++);
	return (size);
}

static int	hex_num_string_precision(t_format *fmt)
{
	int		precision;

	if (has_flags(fmt, 1, ZERO_PAD)
		&& !has_flags(fmt, 1, LEFT_JUSTIFY) && fmt->precision == -1)
		precision = fmt->width - 2;
	else
		precision = fmt->precision;
	return (precision);
}

char	*hex_num_string(unsigned long long n, char *xbase, t_format *fmt)
{
	int		i;
	int		size;
	char	*num_str;
	int		precision;

	precision = hex_num_string_precision(fmt);
	size = hex_num_size(n);
	if (precision > size)
		size = precision;
	num_str = malloc((size + 1) * sizeof(char));
	if (!num_str)
		return ((char *) 0);
	fill_string(num_str, ' ', size);
	i = 0;
	num_str[size] = '\0';
	if (n == 0)
		num_str[0] = '0';
	else
	{
		while (n != 0)
		{
			num_str[size - 1 - i++] = xbase[n % 16];
			//num_str[size-- - 1] = xbase[n % 16];
			n /= 16;
		}
	}
	while (size - 1 - i >= 0)
		num_str[size - 1 - i++] = '0';
	//while (size-- - 1>= 0)
	//	num_str[size-- - 1] = '0';
	return (num_str);
}
