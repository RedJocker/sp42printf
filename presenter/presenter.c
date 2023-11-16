/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presenter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:54:06 by maurodri          #+#    #+#             */
/*   Updated: 2023/11/16 15:07:17 by maurodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presenter_utils.h"
#include "presenter.h"

int	present_format(t_format *format, va_list *lst)
{
	if (format->conversion == STRING)
		return (present_string(lst));
	else if (format->conversion == BASE_10)
		return (present_base10(lst));
	else if (format->conversion == UBASE_10)
		return (present_ubase10(lst));
	else if (format->conversion == CHAR)
		return (present_char(lst));
	else if (format->conversion == ESCAPE)
		return (present_escape(lst));
	else if (format->conversion == HEXA_LOWER)
		return (present_hexa_lower(lst));
	else if (format->conversion == HEXA_UPPER)
		return (present_hexa_upper(lst));
	else if (format->conversion == POINTER)
		return (present_pointer(lst));
	return (-1);
}
