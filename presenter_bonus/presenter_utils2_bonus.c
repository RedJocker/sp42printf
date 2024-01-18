/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presenter_utils2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:04:23 by maurodri          #+#    #+#             */
/*   Updated: 2024/01/18 09:42:01 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presenter_utils_bonus.h"

static int	hex_num_size(unsigned long long nbr, int precision)
{
	int	size;

	size = 0;
	if (nbr == 0)
		size = 1;
	else
		while (nbr != 0)
			nbr /= 16 + (0 * size++);
	if (precision > size)
		return (precision);
	else
		return (size);
}

static int	fill_hex_num(
	char *num_str, unsigned long long n, int size, char *xbase)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		num_str[size - 1 - i++] = xbase[n % 16];
		n /= 16;
	}
	return (i);
}

char	*hex_num_string(unsigned int n, char *xbase, t_format *fmt)
{
	int		i;
	int		size;
	char	*num_str;
	int		precision;

	if (has_flags(fmt, 1, ZERO_PAD)
		&& !has_flags(fmt, 1, LEFT_JUSTIFY) && fmt->precision == 0)
	{
		if (has_flags(fmt, 2, ZERO_PAD, HASHTAG) && n != 0)
			precision = fmt->width - 2;
		else
			precision = fmt->width;
	}
	else
		precision = fmt->precision;
	size = hex_num_size(n, precision) * !(fmt->precision == -1 && n == 0);
	num_str = malloc((size + 1) * sizeof(char));
	if (!num_str)
		return ((char *) 0);
	i = fill_hex_num(num_str, n, size, xbase);
	while (size - 1 - i >= 0)
		num_str[size - 1 - i++] = '0';
	num_str[size] = '\0';
	return (num_str);
}

char	*pointer_hex_num_string(
	unsigned long long n, char *xbase, t_format *fmt)
{
	int		i;
	int		size;
	char	*num_str;
	int		precision;

	if (has_flags(fmt, 1, ZERO_PAD)
		&& !has_flags(fmt, 1, LEFT_JUSTIFY) && fmt->precision == 0)
		precision = fmt->width - 2;
	else
		precision = fmt->precision;
	size = hex_num_size(n, precision);
	num_str = malloc((size + 1) * sizeof(char));
	if (!num_str)
		return ((char *) 0);
	i = 0;
	num_str[size] = '\0';
	if (n == 0)
		num_str[0] = '0';
	else
		i = fill_hex_num(num_str, n, size, xbase);
	while (size - 1 - i >= 0)
		num_str[size - 1 - i++] = '0';
	return (num_str);
}
