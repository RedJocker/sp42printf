/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:27:52 by maurodri          #+#    #+#             */
/*   Updated: 2023/11/01 17:08:22 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "parser_utils.h"

int	is_valid_format(char *str)
{
	return (str[0] == '%' && str[1] != '\0');
}

int	parse_non_format(char **str_ptr)
{
	int	size;

	size = find_ch_or_end_index(*str_ptr, '%');
	write(1, *str_ptr, size);
	*str_ptr = *str_ptr + size;
	return (size);
}

int	parse_format(char **str_ptr, va_list *lst)
{
	int	len;

	len = 0;
	if (is_valid_format(*str_ptr))
	{
		if (is_base10_format(*str_ptr))
			len = parse_base10(str_ptr, lst);
		else if (is_string_format(*str_ptr))
			len = parse_string(str_ptr, lst);
		else if (is_char_format(*str_ptr))
			len = parse_char(str_ptr, lst);
		else if (is_escape_format(*str_ptr))
			len = parse_escape(str_ptr, lst);
		else if (is_ubase10_format(*str_ptr))
			len = parse_ubase10(str_ptr, lst);
		else
			len = -1;
	}
	return (len);
}
