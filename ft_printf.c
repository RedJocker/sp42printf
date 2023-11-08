/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 21:15:46 by maurodri          #+#    #+#             */
/*   Updated: 2023/11/01 17:10:26 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "parser/parser.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		ret;

	va_start(args, str);
	len = 0;
	ret = 0;
	while (*str)
	{
		len += parse_non_format((char **)&str);
		ret = parse_format((char **)&str, &args);
		if (ret < 0)
			return (ret);
		len += ret;
	}
	va_end(args);
	return (len);
}
