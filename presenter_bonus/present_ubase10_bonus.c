/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   present_ubase10_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:03:54 by maurodri          #+#    #+#             */
/*   Updated: 2024/01/03 06:40:41 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presenter_utils_bonus.h"
#include "presenter_bonus.h"

static int	fill_ubase10_num(
	char *num_str, unsigned int n, int size)
{
	int		i;
	char	digit;

	i = 0;
	while (n != 0)
	{
		digit = '0' + (n % 10);
		num_str[size - 1 - i++] = digit;
		n /= 10;
	}
	return (i);
}

static char	*ubase10_str(unsigned int n, t_format *fmt)
{
	int		i;
	int		size;
	char	*num_str;
	int		precision;

	precision = ubase10_precision(fmt);
	size = ubase10_num_size(n, precision);
	num_str = malloc((size + 1) * sizeof(char));
	if (!num_str)
		return ((char *) 0);
	fill_string(num_str, ' ', size);
	i = 0;
	num_str[size] = '\0';
	if (n == 0 && precision == 0)
		num_str[0] = '0';
	else
		i = fill_ubase10_num(num_str, n, size);
	while (size - 1 - i >= 0)
		num_str[size - 1 - i++] = '0';
	return (num_str);
}

static int	ubase10_size_outstr(int len, t_format *fmt)
{
	int	outstr_len;

	outstr_len = 0;
	if (fmt->width > len)
		outstr_len = fmt->width;
	else
	{
		outstr_len = len;
	}
	return (outstr_len);
}

static int	present_ubase10_num(
	unsigned int num, t_format *fmt, char **outstr_ptr)
{
	char	*numstr;
	int		numstr_len;
	int		outstr_len;
	char	*ptr;

	numstr = ubase10_str(num, fmt);
	if (!numstr)
		return (-1);
	numstr_len = ft_strlen(numstr);
	outstr_len = ubase10_size_outstr(numstr_len, fmt);
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

int	present_ubase10(t_format *format, va_list *lst)
{
	unsigned int		n;
	unsigned long long	num;
	char				*out_str;
	int					out_str_len;

	out_str_len = 0;
	n = va_arg (*lst, long long);
	num = (unsigned long long) n;
	out_str_len = present_ubase10_num(num, format, &out_str);
	if (!out_str)
		return (-1);
	if (out_str_len > 0)
		write(1, out_str, out_str_len);
	free(out_str);
	return (out_str_len);
}
