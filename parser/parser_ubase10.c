/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_ubase10.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:34:11 by maurodri          #+#    #+#             */
/*   Updated: 2023/10/30 19:35:26 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "parser_utils.h"

int	is_ubase10_format(char *str)
{
	return (str[1] == 'u');
}

int	parse_ubase10(char **str_ptr, va_list *lst)
{
	unsigned int	num;
	int				size;

	num = va_arg(*lst, unsigned int);
	ft_putunbr_fd(num, 1);
	*str_ptr = *str_ptr + 2;
	size = 0;
	while (num != 0)
	{
		size++;
		num /= 10;
	}
	return (size);
}
