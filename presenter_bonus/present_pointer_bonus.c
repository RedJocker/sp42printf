/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   present_pointer_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:03:52 by maurodri          #+#    #+#             */
/*   Updated: 2023/12/04 19:55:46 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presenter_utils_bonus.h"
#include "presenter_bonus.h"
#include <stdlib.h>
#include <stdio.h> // TODO remove

int	present_pointer(t_format *fmt, va_list *lst)
{
	unsigned long long	num;
	char				*num_str;
	int					num_str_len;
	int					nlen;
	
	num = (unsigned long long) va_arg(*lst, void *);
	if (!num)
	{
		num_str_len = ((fmt->width > 5) * fmt->width) + ((fmt->width <= 5) * 5);
		printf("Anum_str_len: %d\n", num_str_len);
		num_str = malloc(num_str_len * sizeof(char));
		if (!num_str)
			return -1;
		fill_string(num_str, ' ', num_str_len);
		ft_memcpy(num_str + num_str_len - 5, "(nil)", 5);	
	}
	else
	{
		nlen = hex_num_size(num) + 2;
		num_str_len = ((fmt->width > nlen) * fmt->width) + ((fmt->width <= nlen) * nlen);
		printf("Bnum_str_len: %d\n", num_str_len);
		num_str = malloc(num_str_len * sizeof(char));
		if (!num_str)
			return -1;
		fill_string(num_str, ' ', num_str_len);
		hex_num_string(num_str + fmt->width - nlen, nlen, num, XBASEL); 
		ft_memcpy(num_str + fmt->width - nlen, "0x", 2);
	}
	write(1, num_str, num_str_len);
	free(num_str);
	return (num_str_len);
}
