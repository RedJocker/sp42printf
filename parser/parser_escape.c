/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_escape.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:17:07 by maurodri          #+#    #+#             */
/*   Updated: 2023/10/30 19:21:43 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "parser_utils.h"

int	parse_escape(char **str_ptr, va_list *lst)
{
	char	ch;

	(void) lst;
	ch = '%';
	write(1, &ch, 1);
	*str_ptr = *str_ptr + 2;
	return (1);
}

int	is_escape_format(char *str)
{
	return (str[1] == '%');
}
