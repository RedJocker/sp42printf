/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   present_hexa_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:49:41 by maurodri          #+#    #+#             */
/*   Updated: 2024/01/09 20:37:53 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presenter_utils_bonus.h"
#include "presenter_bonus.h"

static int	hexa_size_outstr(int xlen, t_format *fmt, unsigned int num)
{
	int	outstr_len;
	int	has_hashtag;

	outstr_len = 0;
	has_hashtag = has_flags(fmt, 1, HASHTAG);
	if (has_hashtag && num == 0 && fmt->width > xlen)
		outstr_len = fmt->width;
	else if (has_hashtag && num == 0)
		outstr_len = xlen;
	else if (has_hashtag && fmt->width > xlen + 2)
		outstr_len = fmt->width;
	else if (has_hashtag)
		outstr_len = xlen + 2;
	else if (fmt->width > xlen)
		outstr_len = fmt->width;
	else
		outstr_len = xlen;
	return (outstr_len);
}

static int	hexa_pad_offset(int outlen, int xlen, t_format *fmt, int n)
{
	if (has_flags(fmt, 1, LEFT_JUSTIFY))
		return (0);
	return (outlen - (xlen + 2 * (has_flags(fmt, 1, HASHTAG) && n != 0)));
}

static int	present_hexa_num(
	unsigned int n, t_format *fmt, char **out_ptr, char *base)
{
	char	*numstr;
	int		xlen;
	int		outlen;
	char	*ptr;

	numstr = hex_num_string(n, base, fmt);
	if (!numstr)
		return (-1);
	xlen = ft_strlen(numstr);
	outlen = hexa_size_outstr(xlen, fmt, n);
	*out_ptr = malloc(outlen * sizeof(char));
	if (!(*out_ptr))
		return (-1);
	fill_string(*out_ptr, ' ', outlen);
	ptr = *out_ptr + hexa_pad_offset(outlen, xlen, fmt, n);
	if (has_flags(fmt, 1, HASHTAG) && n != 0)
	{
		ft_memcpy(ptr, base + 16, 2);
		ptr += 2;
	}
	ft_memcpy(ptr, numstr, xlen);
	free(numstr);
	return (outlen);
}

int	present_hexa(t_format *fmt, va_list *lst, char *base)
{
	unsigned int	num;
	char			*out_str;
	int				out_str_len;

	out_str_len = 0;
	num = (unsigned int) va_arg(*lst, unsigned int);
	out_str_len = present_hexa_num(num, fmt, &out_str, base);
	if (!out_str)
		return (-1);
	write(1, out_str, out_str_len);
	free(out_str);
	return (out_str_len);
}
