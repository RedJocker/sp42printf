/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:31:53 by maurodri          #+#    #+#             */
/*   Updated: 2023/10/30 19:33:11 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "parser_utils.h"

int	is_string_format(char *str)
{
	return (str[1] == 's');
}

int	parse_string(char **str_ptr, va_list *lst)
{
	char	*str;
	int		str_len;

	str = va_arg(*lst, char *);
	str_len = (int) ft_strlen(str);
	write(1, str, str_len);
	*str_ptr = *str_ptr + 2;
	return (str_len);
}
