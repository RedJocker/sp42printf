/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   present_pointer_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:03:52 by maurodri          #+#    #+#             */
/*   Updated: 2024/01/08 19:19:14 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presenter_utils_bonus.h"
#include "presenter_bonus.h"

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
	t_format *fmt, char *num_str, int num_str_len, char *outstr)
{
	if (has_flags(fmt, 1, SIGNED))
		ft_memcpy(outstr++, "+", 1);
	else if (has_flags(fmt, 1, SPACE))
		outstr++;
	ft_memcpy(outstr, "0x", 2);
	ft_memcpy(outstr + 2, num_str, num_str_len);
}

static void	present_pointer_right_justify(
	t_format *fmt, char *numstr, int numstr_len, char *outstr)
{
	if (has_flags(fmt, 1, SIGNED))
		ft_memcpy(outstr++, "+", 1);
	ft_memcpy(outstr, "0x", 2);
	ft_memcpy(outstr + 2, numstr, numstr_len);
}

static int	present_pointer_num(
	unsigned long long num, t_format *fmt, char **outstr_ptr)
{
	char	*numstr;
	int		numstr_len;
	int		outstr_len;
	char	*ptr;

	numstr = pointer_hex_num_string(num, XBASEL, fmt);
	if (!numstr)
		return (-1);
	numstr_len = ft_strlen(numstr);
	outstr_len = pointer_size_outstr(numstr_len + 2, fmt);
	*outstr_ptr = malloc(outstr_len * sizeof(char));
	if (!(*outstr_ptr))
		return (-1);
	fill_string(*outstr_ptr, ' ', outstr_len);
	if (has_flags(fmt, 1, LEFT_JUSTIFY))
		present_pointer_left_justify(fmt, numstr, numstr_len, *outstr_ptr);
	else
	{
		ptr = *outstr_ptr + outstr_len - (numstr_len + 2);
		if (has_flags(fmt, 1, SIGNED))
			ptr--;
		present_pointer_right_justify(fmt, numstr, numstr_len, ptr);
	}
	free(numstr);
	return (outstr_len);
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
