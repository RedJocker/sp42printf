/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   present_hexa_lower_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:03:51 by maurodri          #+#    #+#             */
/*   Updated: 2024/01/08 23:42:30 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presenter_utils_bonus.h"
#include "presenter_bonus.h"

int	hexa_size_outstr(int xlen, t_format *fmt, unsigned int num)
{
	int	outstr_len;
	int	has_hashtag;

	outstr_len = 0;
	has_hashtag = has_flags(fmt, 1, HASHTAG);
	if (has_hashtag && num == 0 && fmt->width > xlen)
		outstr_len = fmt->width;
	else if (has_hashtag && num == 0)
		outstr_len = xlen;
	else if(has_hashtag && fmt->width > xlen + 2)
		outstr_len = fmt->width;
	else if (has_hashtag)
		outstr_len = xlen + 2;
	else if (fmt->width > xlen)
		outstr_len = fmt->width;
	else
		outstr_len = xlen;
	return (outstr_len);
}

int	present_hexa_num(
	unsigned int num, t_format *fmt, char **outstr_ptr, char *base)
{
	char	*numstr;
	int		xlen;
	int		outstr_len;
	char	*ptr;

	numstr = hex_num_string(num, base, fmt);
	if (!numstr)
		return (-1);
	xlen = ft_strlen(numstr);
	outstr_len = hexa_size_outstr(xlen, fmt, num);
	*outstr_ptr = malloc(outstr_len * sizeof(char));
	if (!(*outstr_ptr))
		return (-1);
	fill_string(*outstr_ptr, ' ', outstr_len);
	if (has_flags(fmt, 1, LEFT_JUSTIFY))
		ptr = *outstr_ptr;
	else
		ptr = *outstr_ptr + outstr_len - (xlen + 2 * (has_flags(fmt, 1, HASHTAG) && num != 0));
	if (has_flags(fmt, 1, HASHTAG) && num != 0)
	{
		ft_memcpy(ptr, "0x", 2);
		ptr +=2;
	}
	ft_memcpy(ptr, numstr, xlen);
	free(numstr);
	return (outstr_len);
}

int	present_hexa_lower(t_format *fmt, va_list *lst)
{
	unsigned int	num;
	char			*out_str;
	int				out_str_len;

	out_str_len = 0;
	num = (unsigned int) va_arg(*lst, unsigned int);
	out_str_len = present_hexa_num(num, fmt, &out_str, XBASEL);
	if (!out_str)
		return (-1);
	write(1, out_str, out_str_len);
	free(out_str);
	return (out_str_len);
}
