/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   present_char_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:02:50 by maurodri          #+#    #+#             */
/*   Updated: 2023/12/13 18:46:38 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presenter_utils_bonus.h"
#include "presenter_bonus.h"
#include <stdlib.h>

int	present_char(t_format *format, va_list *lst)
{
	char	ch;
	char	*str;
	size_t	size;

	size = (format->width > 0) * format->width + (format->width <= 0) * 1;
	str = malloc(size * sizeof(char));
	ch = ' ';
	if (!str)
		return (-1);
	fill_string(str, ch, size);
	ch = (char) va_arg(*lst, int);
	if ((format->flags & LEFT_JUSTIFY) == LEFT_JUSTIFY)
		str[0] = ch;
	else
		str[size - 1] = ch;
	write(1, str, size);
	free(str);
	return (size);
}
