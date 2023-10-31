/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:23:47 by maurodri          #+#    #+#             */
/*   Updated: 2023/10/30 19:24:56 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "parser_utils.h"

int	is_char_format(char *str)
{
	return (str[1] == 'c');
}

int	parse_char(char **str_ptr, va_list *lst)
{
	char	ch;

	ch = (char) va_arg(*lst, int);
	write(1, &ch, 1);
	*str_ptr = *str_ptr + 2;
	return (1);
}
