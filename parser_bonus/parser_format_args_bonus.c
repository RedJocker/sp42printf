/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_format_args_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:10:15 by maurodri          #+#    #+#             */
/*   Updated: 2023/12/14 16:29:33 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"
#include "parser_utils_bonus.h"

int	parse_initial(t_format *format, char **str_ptr)
{
	if (**str_ptr != '%')
	{
		format->conversion = INVALID;
		return (0);
	}
	else
	{
		(*str_ptr)++;
		return (1);
	}
}

int	parse_flags(t_format *format, char **str_ptr)
{
	char	c;

	c = **str_ptr;
	if (c == '-' || c == '0' || c == '+' || c == ' ' || c == '#')
	{
		if (c == '-')
			format->flags |= LEFT_JUSTIFY;
		else if (c == '0')
			format->flags |= ZERO_PAD;
		else if (c == '+')
			format->flags |= SIGNED;
		else if (c == ' ')
			format->flags |= SPACE;
		else if (c == '#')
			format->flags |= HASHTAG;
		(*str_ptr)++;
		return (parse_flags(format, str_ptr));
	}
	return (1);
}

int	parse_width(t_format *format, char **str_ptr)
{
	format->width = 0;
	format->width = parse_number(str_ptr);
	return (1);
}

int	parse_precision(t_format *format, char **str_ptr)
{
	format->precision = 0;
	if (**str_ptr == '.')
	{
		(*str_ptr)++;
		format->precision = parse_number_precision(str_ptr);
	}
	return (1);
}

int	parse_convertion(t_format *format, char **str_ptr)
{
	format->conversion = INVALID;
	if (**str_ptr == 's')
		format->conversion = STRING;
	else if (**str_ptr == 'i' || **str_ptr == 'd')
		format->conversion = BASE_10;
	else if (**str_ptr == 'u')
		format->conversion = UBASE_10;
	else if (**str_ptr == 'c')
		format->conversion = CHAR;
	else if (**str_ptr == '%')
		format->conversion = ESCAPE;
	else if (**str_ptr == 'x')
		format->conversion = HEXA_LOWER;
	else if (**str_ptr == 'X')
		format->conversion = HEXA_UPPER;
	else if (**str_ptr == 'p')
		format->conversion = POINTER;
	if (format->conversion == INVALID)
		return (0);
	else
	{
		(*str_ptr)++;
		return (1);
	}
}
