/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presenter_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:02:30 by maurodri          #+#    #+#             */
/*   Updated: 2023/12/13 18:47:20 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presenter_utils_bonus.h"
#include "presenter_bonus.h"

int	present_format(t_format *format, va_list *lst)
{
	if (format->conversion == STRING)
		return (present_string(format, lst));
	else if (format->conversion == BASE_10)
		return (present_base10(format, lst));
	else if (format->conversion == UBASE_10)
		return (present_ubase10(format, lst));
	else if (format->conversion == CHAR)
		return (present_char(format, lst));
	else if (format->conversion == ESCAPE)
		return (present_escape(format, lst));
	else if (format->conversion == HEXA_LOWER)
		return (present_hexa_lower(format, lst));
	else if (format->conversion == HEXA_UPPER)
		return (present_hexa_upper(format, lst));
	else if (format->conversion == POINTER)
		return (present_pointer(format, lst));
	return (-1);
}
