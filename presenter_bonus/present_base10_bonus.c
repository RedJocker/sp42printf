/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   present_base10_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:03:12 by maurodri          #+#    #+#             */
/*   Updated: 2024/01/18 01:01:15 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presenter_utils_bonus.h"
#include "presenter_bonus.h"

static int	base10_precision(t_format *fmt, int num_size, int num)
{
	int	precision;
	int	is_signed;
	int	is_padded;

	precision = 0;
	is_signed = (has_flags(fmt, 1, SIGNED) || num < 0);
	is_padded = has_flags(fmt, 1, ZERO_PAD);
	if (fmt->precision == 0
		&& fmt->width > 0
		&& !has_flags(fmt, 1, LEFT_JUSTIFY))
		precision = num_size * (!is_padded) + fmt->width * is_padded;
	else
		precision = fmt->precision + (is_signed || has_flags(fmt, 1, SPACE));
	if (num == 0 && fmt->precision == -1)
		return (is_signed || has_flags(fmt, 1, SPACE));
	else if (num_size >= precision)
		return (num_size + (is_signed || has_flags(fmt, 1, SPACE)));
	return (precision);
}

static int	fill_base10_num(
	char *num_str, int n, int size)
{
	long long	nbr;
	int			i;
	char		digit;

	i = 0;
	if (n < 0)
		nbr = -((long long) n);
	else
		nbr = (long long) n;
	while (nbr != 0)
	{
		digit = '0' + (nbr % 10);
		num_str[size - 1 - i++] = digit;
		nbr /= 10;
	}
	return (i);
}

static char	*base10_str(int n, t_format *fmt)
{
	int		size;
	char	*num_str;
	int		num_size;

	num_size = base10_num_size(n);
	size = base10_precision(fmt, num_size, n);
	num_str = malloc((size + 1) * sizeof(char));
	if (!num_str)
		return ((char *) 0);
	if (has_flags(fmt, 1, ZERO_PAD) || fmt->precision != -1)
		fill_string(num_str, '0', size);
	else
		fill_string(num_str, ' ', size);
	if (n == 0 && fmt->precision == 0)
		num_str[0] = '0';
	else
		fill_base10_num(num_str, n, size);
	if (n < 0)
		num_str[0] = '-';
	else if (has_flags(fmt, 1, SIGNED))
		num_str[0] = '+';
	else if (has_flags(fmt, 1, SPACE) && !(fmt->precision == size))
		num_str[0] = ' ';
	num_str[size] = '\0';
	return (num_str);
}

static int	present_base10_num(
	int num, t_format *fmt, char **outstr_ptr)
{
	char	*numstr;
	int		numstr_len;
	int		outstr_len;
	char	*ptr;

	numstr = base10_str(num, fmt);
	if (!numstr)
		return (-1);
	numstr_len = ft_strlen(numstr);
	outstr_len = fmt->width * (fmt->width > numstr_len)
		+ numstr_len * (fmt->width <= numstr_len);
	*outstr_ptr = malloc(outstr_len * sizeof(char));
	if (!(*outstr_ptr))
		return (-1);
	fill_string(*outstr_ptr, ' ', outstr_len);
	if (has_flags(fmt, 1, LEFT_JUSTIFY))
		ft_memcpy(*outstr_ptr, numstr, numstr_len);
	else
	{
		ptr = *outstr_ptr + outstr_len - (numstr_len);
		ft_memcpy(ptr, numstr, numstr_len);
	}
	free(numstr);
	return (outstr_len);
}

int	present_base10(t_format *format, va_list *lst)
{
	int					n;
	char				*out_str;
	int					out_str_len;

	out_str_len = 0;
	n = va_arg (*lst, int);
	out_str_len = present_base10_num(n, format, &out_str);
	if (!out_str)
		return (-1);
	if (out_str_len > 0)
		write(1, out_str, out_str_len);
	free(out_str);
	return (out_str_len);
}
