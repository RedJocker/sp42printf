/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presenter_utils3_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:58:47 by maurodri          #+#    #+#             */
/*   Updated: 2024/01/10 19:38:27 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presenter_utils_bonus.h"
#include "presenter_bonus.h"

int	pointer_size_outstr(int xlen, t_format *fmt)
{
	int	outstr_len;

	outstr_len = 0;
	if (fmt->width > xlen)
		outstr_len = fmt->width;
	else
	{
		if (has_flags(fmt, 1, SPACE) || has_flags(fmt, 1, SIGNED))
			outstr_len = xlen + 1;
		else
			outstr_len = xlen;
	}
	return (outstr_len);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *) dst)[i] = ((char *) src)[i];
		i++;
	}
	return (dst);
}

void	fill_string(char *str, char filler, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
		str[i++] = filler;
}

int	ubase10_num_size(unsigned int nbr, int precision)
{
	int	size;

	size = 0;
	if (nbr == 0 && precision > -1)
		size = 1;
	else
		while (nbr != 0)
			nbr /= 10 + (0 * size++);
	if (precision > size)
		return (precision);
	else
		return (size);
}

int	ubase10_precision(t_format *fmt)
{
	int	precision;

	if (has_flags(fmt, 1, ZERO_PAD)
		&& !has_flags(fmt, 1, LEFT_JUSTIFY)
		&& fmt->precision == 0
		&& fmt->width > 0)
		precision = fmt->width;
	else
		precision = fmt->precision;
	return (precision);
}
