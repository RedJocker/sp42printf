/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   present_string_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:03:53 by maurodri          #+#    #+#             */
/*   Updated: 2024/01/04 19:58:18 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presenter_utils_bonus.h"
#include "presenter_bonus.h"

static int	string_precision_size(char *str, int precision)
{
	int	size;

	if (!str && precision < 6 && precision != 0)
		return (0);
	else if (!str && (precision >= 6 || precision == 0))
		return (6);
	if (precision == -1)
		return (0);
	size = ft_strlen(str);
	if (precision > 0 && precision < size)
		return (precision);
	else
		return (size);
}

static char	*precision_string(char *str, t_format *fmt)
{
	int		precision_str_size;
	char	*precision_str;

	precision_str_size = string_precision_size(str, fmt->precision);
	precision_str = malloc((precision_str_size + 1) * sizeof(char));
	if (!precision_str)
		return ((char *) 0);
	precision_str[precision_str_size] = '\0';
	if (!str)
		ft_memcpy(precision_str, "(null)", precision_str_size);
	else
		ft_memcpy(precision_str, str, precision_str_size);
	return (precision_str);
}

static int	outstr_size(int len, t_format *fmt)
{
	if (fmt->width > len)
		return (fmt->width);
	else
		return (len);
}

static int	present_string_fmt(
	char *str, t_format *fmt, char **outstr_ptr)
{
	char	*precision_str;
	int		precision_strlen;
	int		outstr_len;
	char	*ptr;

	precision_str = precision_string(str, fmt);
	if (!precision_str)
		return (-1);
	precision_strlen = ft_strlen(precision_str);
	outstr_len = outstr_size(precision_strlen, fmt);
	*outstr_ptr = malloc(outstr_len * sizeof(char));
	if (!(*outstr_ptr))
		return (-1);
	fill_string(*outstr_ptr, ' ', outstr_len);
	if (has_flags(fmt, 1, LEFT_JUSTIFY))
		ft_memcpy(*outstr_ptr, precision_str, precision_strlen);
	else
	{
		ptr = *outstr_ptr + outstr_len - (precision_strlen);
		ft_memcpy(ptr, precision_str, precision_strlen);
	}
	free(precision_str);
	return (outstr_len);
}

int	present_string(t_format *format, va_list *lst)
{
	char	*str;
	char	*out_str;
	int		out_str_len;

	out_str_len = 0;
	str = va_arg (*lst, char *);
	out_str_len = present_string_fmt(str, format, &out_str);
	if (!out_str)
		return (-1);
	if (out_str_len > 0)
		write(1, out_str, out_str_len);
	free(out_str);
	return (out_str_len);
}
