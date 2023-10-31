/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_base10.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:25:45 by maurodri          #+#    #+#             */
/*   Updated: 2023/10/30 19:26:59 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "parser_utils.h"

int	parse_base10(char **str_ptr, va_list *lst)
{
	int		num;
	int		size;

	num = va_arg(*lst, int);
	ft_putnbr_fd(num, 1);
	*str_ptr = *str_ptr + 2;
	if (num <= 0)
		size = 1;
	else
		size = 0;
	while (num != 0)
	{
		size++;
		num /= 10;
	}
	return (size);
}

int	is_base10_format(char *str)
{
	return (str[1] == 'd' || str[1] == 'i');
}
