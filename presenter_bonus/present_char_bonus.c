/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   present_char_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:02:50 by maurodri          #+#    #+#             */
/*   Updated: 2023/12/04 13:18:27 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presenter_utils_bonus.h"
#include "presenter_bonus.h"
#include <stdlib.h>
#include <stdio.h> // TODO remove

int	present_char(t_format *format, va_list *lst)
{
	char	ch;
	char	*str;
	size_t	size;

	size = (format->width > 0 && format->width) || 1;
	printf("size: %zu\n", size);
	str = malloc(size * sizeof(char));
	ch = (char) va_arg(*lst, int);
	if (!str)
		return -1;
	if ((format->flags && LEFT_JUSTIFY) == LEFT_JUSTIFY)
		str[size - 1] = ch;
	else
		str[0] = ch;
	write(1, str, size);
	return (1);
}
