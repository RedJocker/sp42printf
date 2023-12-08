/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   present_pointer_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:03:52 by maurodri          #+#    #+#             */
/*   Updated: 2023/12/07 22:25:12 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presenter_utils_bonus.h"
#include "presenter_bonus.h"
#include <stdlib.h>
#include <stdio.h> // TODO remove



static void	present_pointer_null(t_format *fmt, char **out_str_ptr)
{
	int	num_str_len;
	
	num_str_len = ((fmt->width > 5) * fmt->width) + ((fmt->width <= 5) * 5);
	
	*out_str_ptr = malloc(num_str_len * sizeof(char));
	if (!(*out_str_ptr))
		return ;
	fill_string(*out_str_ptr, ' ', num_str_len);
	if ((fmt->flags & LEFT_JUSTIFY) == LEFT_JUSTIFY)
		ft_memcpy(*out_str_ptr, "(nil)", 5);
	else
		ft_memcpy(*out_str_ptr + num_str_len - 5, "(nil)", 5);
}


int	present_pointer(t_format *fmt, va_list *lst)
{
	unsigned long long	num;
	char				*out_str;
	char				*num_str;
	int					num_str_len;
	int					out_str_len;
	int					nlen;

	out_str_len = 0;
	num = (unsigned long long) va_arg(*lst, void *);
	if (!num)
		present_pointer_null(fmt, &out_str);
	else
	{
		num_str = hex_num_string(num, XBASEL);
		if (!num_str)
			return -1;
		nlen = ft_strlen(num_str);
		num_str_len = nlen;
		nlen = 2 + ((fmt->precision > nlen) * fmt->precision) + ((fmt->precision <= nlen) * nlen);
		out_str_len = ((fmt->width > nlen) * fmt->width) + ((fmt->width <= nlen) * nlen);
		out_str = malloc(out_str_len * sizeof(char));
		if (!out_str)
			return -1;
		fill_string(out_str, ' ', out_str_len);
		if ((fmt->flags & LEFT_JUSTIFY) == LEFT_JUSTIFY)
		{
			ft_memcpy(out_str, "0x", 2);
			ft_memcpy(out_str + 2, num_str, num_str_len);
		}
		else
		{
			ft_memcpy(out_str + (out_str_len - nlen), "0x", 2);
			ft_memcpy(out_str + (out_str_len - num_str_len), num_str, num_str_len);
		}
		free(num_str);
	}
	write(1, out_str, out_str_len);
	free(out_str);
	return (out_str_len);
}
