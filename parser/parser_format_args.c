/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:20:29 by maurodri          #+#    #+#             */

/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "parser_utils.h"

int	parse_initial(t_format *format, char **str_ptr)
{
	if(**str_ptr != '%')
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
	(void) format;
	(void) str_ptr;
	return (1);
}

int	parse_width(t_format *format, char **str_ptr)
{
	(void) format;
	(void) str_ptr;
	return (1);
}

int	parse_precision(t_format *format, char **str_ptr)
{
	(void) format;
	(void) str_ptr;
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
		format->conversion = CHAR;
	if (format->conversion == INVALID)
		return (0);
	else
	{
		(*str_ptr)++;
		return (1);
	}
}
