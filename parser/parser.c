/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:27:52 by maurodri          #+#    #+#             */
/*   Updated: 2024/01/11 21:03:31 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "parser_utils.h"
#include "presenter.h"

int	parse_non_format(char **str_ptr)
{
	int	size;

	size = find_ch_or_end_index(*str_ptr, '%');
	write(1, *str_ptr, size);
	*str_ptr = *str_ptr + size;
	return (size);
}

static void	parse_format_args(t_format *format, char **str_ptr)
{
	if (!parse_initial(format, str_ptr))
		return ;
	parse_flags(format, str_ptr);
	parse_width(format, str_ptr);
	parse_precision(format, str_ptr);
	parse_convertion(format, str_ptr);
}

int	parse_format(char **str_ptr, va_list *lst)
{
	int			len;
	t_format	format;

	len = 0;
	parse_format_args(&format, str_ptr);
	len = present_format(&format, lst);
	return (len);
}
