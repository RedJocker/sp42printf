/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   present_pointer_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:03:52 by maurodri          #+#    #+#             */
/*   Updated: 2023/12/08 22:50:37 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presenter_utils_bonus.h"
#include "presenter_bonus.h"
#include <stdlib.h>

static int	present_pointer_null(t_format *fmt, char **out_str_ptr)
{
	int	num_str_len;

	num_str_len = ((fmt->width > 5) * fmt->width) + ((fmt->width <= 5) * 5);
	*out_str_ptr = malloc(num_str_len * sizeof(char));
	if (!(*out_str_ptr))
		return (-1);
	fill_string(*out_str_ptr, ' ', num_str_len);
	if ((fmt->flags & LEFT_JUSTIFY) == LEFT_JUSTIFY)
		ft_memcpy(*out_str_ptr, "(nil)", 5);
	else
		ft_memcpy(*out_str_ptr + num_str_len - 5, "(nil)", 5);
	return (num_str_len);
}

static void	present_pointer_left_justify(
	char *num_str, int num_str_len, char **out_str_ptr)
{
	ft_memcpy(*out_str_ptr, "0x", 2);
	ft_memcpy(*out_str_ptr + 2, num_str, num_str_len);
}

static int	present_pointer_num(
	unsigned long long num, t_format *fmt, char **out_str_ptr)
{
	char	*num_str;
	int		num_strlen;
	int		xlen;
	int		out_strlen;

	num_str = hex_num_string(num, XBASEL, fmt->precision);
	if (!num_str)
		return (-1);
	num_strlen = ft_strlen(num_str);
	xlen = num_strlen + 2;
	out_strlen = ((fmt->width > xlen) * fmt->width)
		+ ((fmt->width <= xlen) * xlen);
	*out_str_ptr = malloc(out_strlen * sizeof(char));
	if (!(*out_str_ptr))
		return (-1);
	fill_string(*out_str_ptr, ' ', out_strlen);
	if ((fmt->flags & LEFT_JUSTIFY) == LEFT_JUSTIFY)
		present_pointer_left_justify(num_str, num_strlen, out_str_ptr);
	else
	{
		ft_memcpy(*out_str_ptr + (out_strlen - xlen), "0x", 2);
		ft_memcpy(*out_str_ptr +(out_strlen - num_strlen), num_str, num_strlen);
	}
	free(num_str);
	return (out_strlen);
}

int	present_pointer(t_format *fmt, va_list *lst)
{
	unsigned long long	num;
	char				*out_str;
	int					out_str_len;

	out_str_len = 0;
	num = (unsigned long long) va_arg(*lst, void *);
	if (!num)
		out_str_len = present_pointer_null(fmt, &out_str);
	else
		out_str_len = present_pointer_num(num, fmt, &out_str);
	if (!out_str)
		return (-1);
	write(1, out_str, out_str_len);
	free(out_str);
	return (out_str_len);
}
